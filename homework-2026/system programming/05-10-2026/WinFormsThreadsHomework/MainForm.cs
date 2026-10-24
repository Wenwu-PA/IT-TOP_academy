using System.Drawing;
using System.Numerics;

namespace ThreadNumbers;

public sealed class MainForm : Form
{
    private const int MaxVisibleNumbers = 500;

    private readonly TextBox _lowerInput = new() { Width = 115 };
    private readonly TextBox _upperInput = new() { Width = 115 };

    private readonly ListBox _primeNumbers = CreateNumberList();
    private readonly ListBox _fibonacciNumbers = CreateNumberList();

    private readonly Label _primeStatus = CreateStatusLabel();
    private readonly Label _fibonacciStatus = CreateStatusLabel();

    private readonly Button _stopPrimeButton = CreateButton("Остановить");
    private readonly Button _pausePrimeButton = CreateButton("Пауза");
    private readonly Button _resumePrimeButton = CreateButton("Продолжить");

    private readonly Button _stopFibonacciButton = CreateButton("Остановить");
    private readonly Button _pauseFibonacciButton = CreateButton("Пауза");
    private readonly Button _resumeFibonacciButton = CreateButton("Продолжить");

    private NumberWorker? _primeWorker;
    private NumberWorker? _fibonacciWorker;

    private int _primeVersion;
    private int _fibonacciVersion;
    private bool _primeRunning;
    private bool _fibonacciRunning;
    private bool _primePaused;
    private bool _fibonacciPaused;

    public MainForm()
    {
        Text = "Генерация чисел — многопоточность";
        StartPosition = FormStartPosition.CenterScreen;
        MinimumSize = new Size(880, 560);
        Size = new Size(1040, 700);
        Font = new Font("Segoe UI", 10);

        BuildInterface();
        UpdateButtons();

        FormClosing += (_, _) =>
        {
            StopPrime(false);
            StopFibonacci(false);
        };
    }

    private void BuildInterface()
    {
        var root = new TableLayoutPanel
        {
            Dock = DockStyle.Fill,
            Padding = new Padding(14),
            ColumnCount = 1,
            RowCount = 3
        };
        root.RowStyles.Add(new RowStyle(SizeType.Absolute, 55));
        root.RowStyles.Add(new RowStyle(SizeType.Absolute, 95));
        root.RowStyles.Add(new RowStyle(SizeType.Percent, 100));
        Controls.Add(root);

        root.Controls.Add(new Label
        {
            Text = "Генерация простых чисел и чисел Фибоначчи",
            Dock = DockStyle.Fill,
            Font = new Font("Segoe UI", 16, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleLeft
        }, 0, 0);

        var settings = new FlowLayoutPanel
        {
            Dock = DockStyle.Fill,
            WrapContents = true,
            AutoScroll = true,
            Padding = new Padding(0, 6, 0, 0)
        };

        settings.Controls.Add(CreateInputLabel("От"));
        settings.Controls.Add(_lowerInput);
        settings.Controls.Add(CreateInputLabel("До"));
        settings.Controls.Add(_upperInput);

        var startButton = CreateButton("Старт / рестарт");
        startButton.Width = 165;
        startButton.Click += (_, _) => RestartBoth();
        settings.Controls.Add(startButton);

        settings.Controls.Add(new Label
        {
            Text = "Пустые поля: простые от 2, Фибоначчи от 0; без верхней границы — до остановки.",
            AutoSize = true,
            Margin = new Padding(8, 10, 0, 0)
        });
        root.Controls.Add(settings, 0, 1);

        var columns = new TableLayoutPanel
        {
            Dock = DockStyle.Fill,
            ColumnCount = 2,
            RowCount = 1
        };
        columns.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50));
        columns.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50));
        columns.RowStyles.Add(new RowStyle(SizeType.Percent, 100));
        root.Controls.Add(columns, 0, 2);

        columns.Controls.Add(CreateNumberGroup(
            "Простые числа",
            _primeNumbers,
            _primeStatus,
            _stopPrimeButton,
            _pausePrimeButton,
            _resumePrimeButton), 0, 0);

        columns.Controls.Add(CreateNumberGroup(
            "Числа Фибоначчи",
            _fibonacciNumbers,
            _fibonacciStatus,
            _stopFibonacciButton,
            _pauseFibonacciButton,
            _resumeFibonacciButton), 1, 0);

        _stopPrimeButton.Click += (_, _) => StopPrime();
        _pausePrimeButton.Click += (_, _) => PausePrime();
        _resumePrimeButton.Click += (_, _) => ResumePrime();

        _stopFibonacciButton.Click += (_, _) => StopFibonacci();
        _pauseFibonacciButton.Click += (_, _) => PauseFibonacci();
        _resumeFibonacciButton.Click += (_, _) => ResumeFibonacci();

        AcceptButton = startButton;
    }

    private static GroupBox CreateNumberGroup(
        string title,
        ListBox numbers,
        Label status,
        Button stop,
        Button pause,
        Button resume)
    {
        var group = new GroupBox
        {
            Text = title,
            Dock = DockStyle.Fill,
            Padding = new Padding(10)
        };
        var layout = new TableLayoutPanel
        {
            Dock = DockStyle.Fill,
            ColumnCount = 1,
            RowCount = 3
        };
        layout.RowStyles.Add(new RowStyle(SizeType.Absolute, 36));
        layout.RowStyles.Add(new RowStyle(SizeType.Percent, 100));
        layout.RowStyles.Add(new RowStyle(SizeType.Absolute, 55));

        var buttons = new FlowLayoutPanel
        {
            Dock = DockStyle.Fill,
            WrapContents = true
        };
        buttons.Controls.Add(stop);
        buttons.Controls.Add(pause);
        buttons.Controls.Add(resume);

        layout.Controls.Add(status, 0, 0);
        layout.Controls.Add(numbers, 0, 1);
        layout.Controls.Add(buttons, 0, 2);
        group.Controls.Add(layout);
        return group;
    }

    private static ListBox CreateNumberList() => new()
    {
        Dock = DockStyle.Fill,
        Font = new Font("Consolas", 11),
        HorizontalScrollbar = true
    };

    private static Label CreateStatusLabel() => new()
    {
        Text = "Не запущен",
        Dock = DockStyle.Fill,
        TextAlign = ContentAlignment.MiddleLeft
    };

    private static Label CreateInputLabel(string text) => new()
    {
        Text = text,
        AutoSize = true,
        Margin = new Padding(8, 7, 5, 0)
    };

    private static Button CreateButton(string text) => new()
    {
        Text = text,
        Width = 116,
        Height = 34,
        Margin = new Padding(4)
    };

    private bool TryReadLimits(out long lower, out long? upper)
    {
        lower = 0;
        upper = null;

        if (!string.IsNullOrWhiteSpace(_lowerInput.Text) &&
            (!long.TryParse(_lowerInput.Text.Trim(), out lower) || lower < 0))
        {
            MessageBox.Show("Нижняя граница должна быть неотрицательным целым числом.",
                "Ошибка ввода", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            return false;
        }

        if (!string.IsNullOrWhiteSpace(_upperInput.Text))
        {
            if (!long.TryParse(_upperInput.Text.Trim(), out long parsedUpper) ||
                parsedUpper < lower)
            {
                MessageBox.Show("Верхняя граница должна быть целым числом не меньше нижней.",
                    "Ошибка ввода", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return false;
            }
            upper = parsedUpper;
        }
        return true;
    }

    private void RestartBoth()
    {
        if (!TryReadLimits(out long lower, out long? upper))
            return;

        // Сначала полностью завершаем старые потоки, затем создаём новые.
        StopPrime(false);
        StopFibonacci(false);
        _primeNumbers.Items.Clear();
        _fibonacciNumbers.Items.Clear();

        StartPrime(lower, upper);
        StartFibonacci(lower, upper);
    }

    private void StartPrime(long lower, long? upper)
    {
        int version = ++_primeVersion;
        _primeRunning = true;
        _primePaused = false;
        _primeStatus.Text = "Работает";
        UpdateButtons();

        _primeWorker = new NumberWorker(
            (token, pause) => GeneratePrimes(lower, upper, token, pause, n =>
                PostToUi(() =>
                {
                    if (version == _primeVersion)
                        AddNumber(_primeNumbers, n.ToString());
                })),
            () => PostToUi(() => CompletePrime(version, "Завершено")),
            ex => PostToUi(() => CompletePrime(version, $"Ошибка: {ex.Message}")));
        _primeWorker.Start();
    }

    private void StartFibonacci(long lower, long? upper)
    {
        int version = ++_fibonacciVersion;
        _fibonacciRunning = true;
        _fibonacciPaused = false;
        _fibonacciStatus.Text = "Работает";
        UpdateButtons();

        _fibonacciWorker = new NumberWorker(
            (token, pause) => GenerateFibonacci(lower, upper, token, pause, n =>
                PostToUi(() =>
                {
                    if (version == _fibonacciVersion)
                        AddNumber(_fibonacciNumbers, n.ToString());
                })),
            () => PostToUi(() => CompleteFibonacci(version, "Завершено")),
            ex => PostToUi(() => CompleteFibonacci(version, $"Ошибка: {ex.Message}")));
        _fibonacciWorker.Start();
    }

    private static void GeneratePrimes(
        long lower, long? upper,
        CancellationToken token, ManualResetEventSlim pause,
        Action<long> show)
    {
        long number = Math.Max(2, lower);

        while (!upper.HasValue || number <= upper.Value)
        {
            pause.Wait(token);
            token.ThrowIfCancellationRequested();

            if (IsPrime(number, token, pause))
            {
                show(number);
                if (token.WaitHandle.WaitOne(45))
                    return;
            }

            if (number == long.MaxValue)
                return;
            number++;
        }
    }

    private static bool IsPrime(
        long number, CancellationToken token, ManualResetEventSlim pause)
    {
        if (number < 2) return false;
        if (number == 2) return true;
        if (number % 2 == 0) return false;

        for (long divisor = 3; divisor <= number / divisor; divisor += 2)
        {
            // Проверяем остановку/паузу даже во время долгого поиска делителей.
            if (divisor % 1024 == 3)
                pause.Wait(token);

            if (number % divisor == 0)
                return false;
        }
        return true;
    }

    private static void GenerateFibonacci(
        long lower, long? upper,
        CancellationToken token, ManualResetEventSlim pause,
        Action<BigInteger> show)
    {
        BigInteger first = 0;
        BigInteger second = 1;

        while (true)
        {
            pause.Wait(token);
            token.ThrowIfCancellationRequested();

            if (upper.HasValue && first > upper.Value)
                return;

            if (first >= lower)
                show(first);

            BigInteger next = first + second;
            first = second;
            second = next;

            if (token.WaitHandle.WaitOne(90))
                return;
        }
    }

    private static void AddNumber(ListBox list, string number)
    {
        // Не накапливаем в интерфейсе бесконечное число строк.
        if (list.Items.Count >= MaxVisibleNumbers)
            list.Items.RemoveAt(0);

        list.Items.Add(number);
        list.TopIndex = list.Items.Count - 1;
    }

    private void PostToUi(Action action)
    {
        if (IsDisposed || Disposing || !IsHandleCreated)
            return;

        try
        {
            BeginInvoke(action); // Работать с контролами можно только из UI-потока.
        }
        catch (InvalidOperationException)
        {
            // Окно уже закрывается.
        }
    }

    private void CompletePrime(int version, string text)
    {
        if (version != _primeVersion) return;
        _primeRunning = false;
        _primePaused = false;
        _primeStatus.Text = text;
        UpdateButtons();
    }

    private void CompleteFibonacci(int version, string text)
    {
        if (version != _fibonacciVersion) return;
        _fibonacciRunning = false;
        _fibonacciPaused = false;
        _fibonacciStatus.Text = text;
        UpdateButtons();
    }

    private void StopPrime(bool updateStatus = true)
    {
        _primeVersion++; // Старые сообщения от потока больше не добавятся в список.
        _primeWorker?.Stop();
        _primeWorker = null;
        _primeRunning = false;
        _primePaused = false;

        if (updateStatus)
            _primeStatus.Text = "Остановлен";
        UpdateButtons();
    }

    private void StopFibonacci(bool updateStatus = true)
    {
        _fibonacciVersion++;
        _fibonacciWorker?.Stop();
        _fibonacciWorker = null;
        _fibonacciRunning = false;
        _fibonacciPaused = false;

        if (updateStatus)
            _fibonacciStatus.Text = "Остановлен";
        UpdateButtons();
    }

    private void PausePrime()
    {
        if (!_primeRunning || _primePaused) return;
        _primeWorker?.Pause();
        _primePaused = true;
        _primeStatus.Text = "Пауза";
        UpdateButtons();
    }

    private void ResumePrime()
    {
        if (!_primeRunning || !_primePaused) return;
        _primeWorker?.Resume();
        _primePaused = false;
        _primeStatus.Text = "Работает";
        UpdateButtons();
    }

    private void PauseFibonacci()
    {
        if (!_fibonacciRunning || _fibonacciPaused) return;
        _fibonacciWorker?.Pause();
        _fibonacciPaused = true;
        _fibonacciStatus.Text = "Пауза";
        UpdateButtons();
    }

    private void ResumeFibonacci()
    {
        if (!_fibonacciRunning || !_fibonacciPaused) return;
        _fibonacciWorker?.Resume();
        _fibonacciPaused = false;
        _fibonacciStatus.Text = "Работает";
        UpdateButtons();
    }

    private void UpdateButtons()
    {
        _stopPrimeButton.Enabled = _primeRunning;
        _pausePrimeButton.Enabled = _primeRunning && !_primePaused;
        _resumePrimeButton.Enabled = _primeRunning && _primePaused;

        _stopFibonacciButton.Enabled = _fibonacciRunning;
        _pauseFibonacciButton.Enabled = _fibonacciRunning && !_fibonacciPaused;
        _resumeFibonacciButton.Enabled = _fibonacciRunning && _fibonacciPaused;
    }
}
