using System;
using System.Drawing;
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ThreadsAsyncPart2;

internal sealed class FileSearchPage : UserControl
{
    private readonly TextBox fileInput = new() { Dock = DockStyle.Fill };
    private readonly TextBox wordInput = new() { Dock = DockStyle.Fill };
    private readonly Button browseButton = UiHelpers.MakeButton("Обзор...", 100);
    private readonly Button searchButton = UiHelpers.MakeButton("Найти", 120);
    private readonly Button cancelButton = UiHelpers.MakeButton("Отмена", 110);
    private readonly Label status = new()
    {
        Dock = DockStyle.Top, Height = 65, Padding = new Padding(12),
        Text = "Укажите текстовый файл и искомое слово", Font = new Font("Segoe UI", 11)
    };
    private CancellationTokenSource? tokenSource;

    public FileSearchPage()
    {
        var fields = new TableLayoutPanel
        {
            Dock = DockStyle.Top, Height = 110, ColumnCount = 3, RowCount = 2,
            Padding = new Padding(10)
        };
        fields.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 105));
        fields.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 100));
        fields.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 115));
        fields.RowStyles.Add(new RowStyle(SizeType.Absolute, 42));
        fields.RowStyles.Add(new RowStyle(SizeType.Absolute, 42));
        fields.Controls.Add(UiHelpers.MakeLabel("Путь к файлу:", 105), 0, 0);
        fields.Controls.Add(fileInput, 1, 0);
        fields.Controls.Add(browseButton, 2, 0);
        fields.Controls.Add(UiHelpers.MakeLabel("Слово:", 105), 0, 1);
        fields.Controls.Add(wordInput, 1, 1);

        var toolbar = UiHelpers.MakeToolbar();
        toolbar.Controls.Add(searchButton);
        toolbar.Controls.Add(cancelButton);
        cancelButton.Enabled = false;

        var info = new Label
        {
            Dock = DockStyle.Fill, Padding = new Padding(16), AutoSize = false,
            Text = "Поиск выполняется асинхронно.\n" +
                   "Подсчитываются отдельные слова без учёта регистра.\n" +
                   "Например, слово «кот» не будет найдено внутри слова «котик»."
        };

        Controls.Add(info);
        Controls.Add(status);
        Controls.Add(toolbar);
        Controls.Add(fields);

        browseButton.Click += (_, _) => Browse();
        searchButton.Click += async (_, _) => await SearchAsync();
        cancelButton.Click += (_, _) => Cancel();
    }

    private void Browse()
    {
        using var dialog = new OpenFileDialog
        {
            Title = "Выберите файл", Filter = "Текстовые файлы|*.txt;*.csv;*.log;*.md;*.json;*.xml|Все файлы|*.*"
        };
        if (dialog.ShowDialog(this) == DialogResult.OK)
            fileInput.Text = dialog.FileName;
    }

    private async Task SearchAsync()
    {
        var path = fileInput.Text.Trim();
        var word = wordInput.Text.Trim();
        if (word.Length == 0 || !File.Exists(path))
        {
            MessageBox.Show("Укажите существующий файл и непустое слово.", "Проверка данных",
                MessageBoxButtons.OK, MessageBoxIcon.Warning);
            return;
        }

        var source = new CancellationTokenSource();
        tokenSource = source;
        SetBusy(true);
        status.Text = "Поиск в файле...";

        try
        {
            // Task.Run не позволяет обработке строк тормозить поток интерфейса.
            var count = await Task.Run(
                () => WordSearch.CountInFileAsync(path, word, source.Token), source.Token);
            status.Text = $"Слово «{word}» встретилось {count} раз(а).";
        }
        catch (OperationCanceledException)
        {
            status.Text = "Поиск отменён";
        }
        catch (Exception ex) when (ex is IOException or UnauthorizedAccessException)
        {
            status.Text = $"Ошибка чтения файла: {ex.Message}";
        }
        finally
        {
            if (!IsDisposed)
                SetBusy(false);
            if (ReferenceEquals(tokenSource, source))
                tokenSource = null;
            source.Dispose();
        }
    }

    private void SetBusy(bool busy)
    {
        searchButton.Enabled = !busy;
        browseButton.Enabled = !busy;
        cancelButton.Enabled = busy;
        fileInput.Enabled = !busy;
        wordInput.Enabled = !busy;
    }

    public void Cancel() => tokenSource?.Cancel();
}
