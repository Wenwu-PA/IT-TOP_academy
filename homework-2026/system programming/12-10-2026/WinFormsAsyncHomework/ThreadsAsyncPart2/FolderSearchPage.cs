using System;
using System.Collections.Generic;
using System.IO;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ThreadsAsyncPart2;

internal sealed class FolderSearchPage : UserControl
{
    private readonly TextBox folderInput = new() { Dock = DockStyle.Fill };
    private readonly TextBox wordInput = new() { Dock = DockStyle.Fill };
    private readonly Button browseButton = UiHelpers.MakeButton("Обзор...", 100);
    private readonly Button searchButton = UiHelpers.MakeButton("Найти", 120);
    private readonly Button cancelButton = UiHelpers.MakeButton("Отмена", 110);
    private readonly Label status = UiHelpers.MakeLabel("Поиск по всем вложенным папкам", 530);
    private readonly DataGridView resultsTable = new()
    {
        Dock = DockStyle.Fill, ReadOnly = true,
        AllowUserToAddRows = false, AllowUserToDeleteRows = false,
        RowHeadersVisible = false, AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill,
        SelectionMode = DataGridViewSelectionMode.FullRowSelect
    };
    private CancellationTokenSource? tokenSource;

    private sealed record FileResult(string Name, string Path, long Count);
    private sealed record SearchSummary(int Files, long Occurrences, int Skipped);

    public FolderSearchPage()
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
        fields.Controls.Add(UiHelpers.MakeLabel("Папка:", 105), 0, 0);
        fields.Controls.Add(folderInput, 1, 0);
        fields.Controls.Add(browseButton, 2, 0);
        fields.Controls.Add(UiHelpers.MakeLabel("Слово:", 105), 0, 1);
        fields.Controls.Add(wordInput, 1, 1);

        var toolbar = UiHelpers.MakeToolbar();
        toolbar.Controls.Add(searchButton);
        toolbar.Controls.Add(cancelButton);
        toolbar.Controls.Add(status);
        cancelButton.Enabled = false;

        resultsTable.Columns.Add("name", "Название файла");
        resultsTable.Columns.Add("path", "Путь к файлу");
        resultsTable.Columns.Add("count", "Количество вхождений");
        resultsTable.Columns[0].FillWeight = 25;
        resultsTable.Columns[1].FillWeight = 60;
        resultsTable.Columns[2].FillWeight = 25;

        Controls.Add(resultsTable);
        Controls.Add(toolbar);
        Controls.Add(fields);

        browseButton.Click += (_, _) => Browse();
        searchButton.Click += async (_, _) => await SearchAsync();
        cancelButton.Click += (_, _) => Cancel();
    }

    private void Browse()
    {
        using var dialog = new FolderBrowserDialog { Description = "Выберите директорию для поиска" };
        if (dialog.ShowDialog(this) == DialogResult.OK)
            folderInput.Text = dialog.SelectedPath;
    }

    private async Task SearchAsync()
    {
        var folder = folderInput.Text.Trim();
        var word = wordInput.Text.Trim();
        if (word.Length == 0 || !Directory.Exists(folder))
        {
            MessageBox.Show("Укажите существующую папку и непустое слово.", "Проверка данных",
                MessageBoxButtons.OK, MessageBoxIcon.Warning);
            return;
        }

        var source = new CancellationTokenSource();
        tokenSource = source;
        resultsTable.Rows.Clear();
        SetBusy(true);
        status.Text = "Поиск...";
        // Progress переносит данные на UI-поток для добавления строк.
        var progress = new Progress<FileResult>(result =>
        {
            if (!IsDisposed && !resultsTable.IsDisposed)
                resultsTable.Rows.Add(result.Name, result.Path, result.Count);
        });

        try
        {
            var summary = await Task.Run(() => SearchFolderAsync(folder, word, progress, source.Token),
                source.Token);
            status.Text = $"Файлов: {summary.Files}; вхождений: {summary.Occurrences}; ошибок: {summary.Skipped}";
        }
        catch (OperationCanceledException)
        {
            status.Text = $"Поиск отменён. Просмотрено файлов: {resultsTable.RowCount}";
        }
        catch (Exception ex) when (ex is IOException or UnauthorizedAccessException)
        {
            status.Text = $"Ошибка доступа к папке: {ex.Message}";
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

    private static async Task<SearchSummary> SearchFolderAsync(
        string folder, string word, IProgress<FileResult> progress, CancellationToken token)
    {
        int files = 0;
        int skipped = 0;
        long occurrences = 0;
        var options = new EnumerationOptions
        {
            RecurseSubdirectories = true,
            IgnoreInaccessible = true,
            // Не переходим по ссылкам на директории: избегаем циклов.
            AttributesToSkip = FileAttributes.ReparsePoint,
            ReturnSpecialDirectories = false
        };

        foreach (var path in Directory.EnumerateFiles(folder, "*", options))
        {
            token.ThrowIfCancellationRequested();
            try
            {
                long count = await WordSearch.CountInFileAsync(path, word, token);
                files++;
                occurrences += count;
                progress.Report(new FileResult(Path.GetFileName(path), path, count));
            }
            catch (Exception ex) when (ex is IOException or UnauthorizedAccessException)
            {
                skipped++;
            }
        }

        return new SearchSummary(files, occurrences, skipped);
    }

    private void SetBusy(bool busy)
    {
        searchButton.Enabled = !busy;
        browseButton.Enabled = !busy;
        cancelButton.Enabled = busy;
        folderInput.Enabled = !busy;
        wordInput.Enabled = !busy;
    }

    public void Cancel() => tokenSource?.Cancel();
}
