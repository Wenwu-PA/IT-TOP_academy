using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace SyncHomeworkModule4;

internal sealed class FilePipelinePage : UserControl, IStoppable
{
    private readonly TextBox directoryBox = new() { Width = 370 };
    private readonly NumericUpDown countBox = new()
    {
        Minimum = 10, Maximum = 1000, Value = 50, Width = 75
    };
    private readonly Button startButton = UiHelpers.CreateButton("Создать файлы и отчёт");
    private readonly Label statusLabel = UiHelpers.CreateLabel("Ожидание запуска");
    private readonly TextBox log = UiHelpers.CreateLog();
    private CancellationTokenSource? cancellation;

    public FilePipelinePage()
    {
        directoryBox.Text = Path.Combine(
            Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments), "SyncHomeworkModule4");

        var browseButton = UiHelpers.CreateButton("Обзор...");
        browseButton.Click += (_, _) =>
        {
            using var dialog = new FolderBrowserDialog();
            if (Directory.Exists(directoryBox.Text))
                dialog.SelectedPath = directoryBox.Text;
            if (dialog.ShowDialog(this) == DialogResult.OK)
                directoryBox.Text = dialog.SelectedPath;
        };

        var top = UiHelpers.CreateToolbar();
        top.Controls.Add(UiHelpers.CreateLabel("Папка:"));
        top.Controls.Add(directoryBox);
        top.Controls.Add(browseButton);
        top.Controls.Add(UiHelpers.CreateLabel("Чисел:"));
        top.Controls.Add(countBox);
        top.Controls.Add(startButton);
        top.Controls.Add(statusLabel);

        Controls.Add(log);
        Controls.Add(top);
        startButton.Click += (_, _) => Start();
    }

    private void Start()
    {
        if (cancellation != null)
            return;

        string folder = directoryBox.Text.Trim();
        if (folder.Length == 0)
        {
            MessageBox.Show("Выберите папку для файлов.", "Проверка данных");
            return;
        }

        try
        {
            Directory.CreateDirectory(folder);
        }
        catch (Exception error) when (error is IOException or UnauthorizedAccessException or ArgumentException)
        {
            MessageBox.Show(error.Message, "Не удалось открыть папку");
            return;
        }

        int numberCount = (int)countBox.Value;
        string allFile = Path.Combine(folder, "numbers.txt");
        string primesFile = Path.Combine(folder, "primes.txt");
        string sevensFile = Path.Combine(folder, "primes_last_7.txt");
        string reportFile = Path.Combine(folder, "report.txt");

        log.Clear();
        startButton.Enabled = false;
        statusLabel.Text = "Работают 4 потока...";
        var source = new CancellationTokenSource();
        cancellation = source;

        var mutex = new Mutex();
        var firstDone = new ManualResetEventSlim(false);
        var secondDone = new ManualResetEventSlim(false);
        var thirdDone = new ManualResetEventSlim(false);
        bool firstOk = false;
        bool secondOk = false;
        bool thirdOk = false;

        // Each stage waits for the preceding stage and takes the same Mutex
        // while reading/writing the files. Events express the stage order.
        void RunStage(string description, Action action, ManualResetEventSlim done,
            Action onSuccess, ManualResetEventSlim? previous = null, Func<bool>? previousOk = null)
        {
            bool acquired = false;
            try
            {
                previous?.Wait();
                if (source.IsCancellationRequested || (previousOk != null && !previousOk()))
                {
                    UiHelpers.WriteLog(this, log, $"Пропуск: {description}");
                    return;
                }

                mutex.WaitOne();
                acquired = true;
                UiHelpers.WriteLog(this, log,
                    $"Поток {Environment.CurrentManagedThreadId}: {description}");
                action();
                onSuccess();
            }
            catch (Exception error)
            {
                UiHelpers.WriteLog(this, log, $"Ошибка: {error.Message}");
            }
            finally
            {
                if (acquired)
                    mutex.ReleaseMutex();
                done.Set();
            }
        }

        var first = new Thread(() => RunStage(
            "Генерация случайных чисел",
            () =>
            {
                int[] numbers = Enumerable.Range(0, numberCount)
                    .Select(_ => Random.Shared.Next(1, 1000)).ToArray();
                File.WriteAllLines(allFile, numbers.Select(value => value.ToString()));
                UiHelpers.WriteLog(this, log, $"Готов {allFile} ({numbers.Length} чисел)");
            }, firstDone, () => firstOk = true)) { IsBackground = true };

        var second = new Thread(() => RunStage(
            "Поиск простых чисел",
            () =>
            {
                int[] primes = File.ReadAllLines(allFile)
                    .Select(int.Parse).Where(IsPrime).ToArray();
                File.WriteAllLines(primesFile, primes.Select(value => value.ToString()));
                UiHelpers.WriteLog(this, log, $"Готов {primesFile} ({primes.Length} простых)");
            }, secondDone, () => secondOk = true, firstDone, () => firstOk)) { IsBackground = true };

        var third = new Thread(() => RunStage(
            "Поиск простых чисел, оканчивающихся на 7",
            () =>
            {
                int[] sevens = File.ReadAllLines(primesFile)
                    .Select(int.Parse).Where(value => value % 10 == 7).ToArray();
                File.WriteAllLines(sevensFile, sevens.Select(value => value.ToString()));
                UiHelpers.WriteLog(this, log, $"Готов {sevensFile} ({sevens.Length} чисел)");
            }, thirdDone, () => thirdOk = true, secondDone, () => secondOk)) { IsBackground = true };

        var fourth = new Thread(() =>
        {
            bool acquired = false;
            try
            {
                thirdDone.Wait();
                if (!thirdOk || source.IsCancellationRequested)
                {
                    UiHelpers.WriteLog(this, log, "Отчёт не создан: предыдущий этап не завершён.");
                    return;
                }

                mutex.WaitOne();
                acquired = true;
                var report = new StringBuilder();
                report.AppendLine("Отчёт о созданных файлах");
                report.AppendLine($"Дата: {DateTime.Now:dd.MM.yyyy HH:mm:ss}");
                report.AppendLine();

                foreach (string file in new[] { allFile, primesFile, sevensFile })
                {
                    string[] lines = File.ReadAllLines(file);
                    report.AppendLine($"Файл: {Path.GetFileName(file)}");
                    report.AppendLine($"Путь: {file}");
                    report.AppendLine($"Количество чисел: {lines.Length}");
                    report.AppendLine($"Размер: {new FileInfo(file).Length} байт");
                    report.AppendLine($"Содержимое: {string.Join(", ", lines)}");
                    report.AppendLine();
                }

                File.WriteAllText(reportFile, report.ToString(), Encoding.UTF8);
                UiHelpers.WriteLog(this, log, $"Поток {Environment.CurrentManagedThreadId}: отчёт {reportFile}");
            }
            catch (Exception error)
            {
                UiHelpers.WriteLog(this, log, $"Ошибка создания отчёта: {error.Message}");
            }
            finally
            {
                if (acquired)
                    mutex.ReleaseMutex();

                UiHelpers.Post(this, () =>
                {
                    startButton.Enabled = true;
                    statusLabel.Text = "Обработка закончена";
                    cancellation = null;
                    source.Dispose();
                    firstDone.Dispose();
                    secondDone.Dispose();
                    thirdDone.Dispose();
                    mutex.Dispose();
                });
            }
        }) { IsBackground = true };

        first.Start();
        second.Start();
        third.Start();
        fourth.Start();
    }

    private static bool IsPrime(int number)
    {
        if (number < 2)
            return false;

        for (int divisor = 2; divisor <= number / divisor; divisor++)
        {
            if (number % divisor == 0)
                return false;
        }
        return true;
    }

    public void StopWork() => cancellation?.Cancel();
}
