using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace SyncHomeworkModule4;

internal sealed class CasinoPage : UserControl, IStoppable
{
    private sealed record PlayerResult(int Id, int StartBalance, int EndBalance, int Rounds);

    private sealed class CasinoDay
    {
        public readonly object Sync = new();
        public readonly SemaphoreSlim Seats = new(5, 5);
        public readonly List<PlayerResult> Results = new();
        public readonly int TotalPlayers;
        public readonly string ReportPath;
        public readonly CancellationTokenSource Cancellation = new();
        public int NextPlayer = 1;
        public int Finished;

        public CasinoDay(int totalPlayers, string reportPath)
        {
            TotalPlayers = totalPlayers;
            ReportPath = reportPath;
        }
    }

    private readonly TextBox folderBox = new() { Width = 420 };
    private readonly Button startButton = UiHelpers.CreateButton("Начать игровой день");
    private readonly Label statusLabel = UiHelpers.CreateLabel("За столом одновременно до 5 игроков");
    private readonly TextBox log = UiHelpers.CreateLog();
    private readonly DataGridView resultsGrid = new()
    {
        Dock = DockStyle.Fill,
        ReadOnly = true,
        AllowUserToAddRows = false,
        AllowUserToDeleteRows = false,
        AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill,
        RowHeadersVisible = false
    };
    private CasinoDay? day;

    public CasinoPage()
    {
        folderBox.Text = Path.Combine(
            Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments), "SyncHomeworkModule4");

        var browseButton = UiHelpers.CreateButton("Обзор...");
        browseButton.Click += (_, _) =>
        {
            using var dialog = new FolderBrowserDialog();
            if (Directory.Exists(folderBox.Text))
                dialog.SelectedPath = folderBox.Text;
            if (dialog.ShowDialog(this) == DialogResult.OK)
                folderBox.Text = dialog.SelectedPath;
        };

        var top = UiHelpers.CreateToolbar();
        top.Controls.Add(UiHelpers.CreateLabel("Папка отчёта:"));
        top.Controls.Add(folderBox);
        top.Controls.Add(browseButton);
        top.Controls.Add(startButton);
        top.Controls.Add(statusLabel);

        resultsGrid.Columns.Add("player", "Игрок");
        resultsGrid.Columns.Add("initial", "Начальная сумма");
        resultsGrid.Columns.Add("final", "Конечная сумма");
        resultsGrid.Columns.Add("rounds", "Раундов");

        var content = new SplitContainer
        {
            Dock = DockStyle.Fill,
            Orientation = Orientation.Horizontal,
            Size = new System.Drawing.Size(950, 500),
            Panel1MinSize = 100,
            Panel2MinSize = 100,
            SplitterDistance = 250
        };
        content.Panel1.Controls.Add(resultsGrid);
        content.Panel2.Controls.Add(log);
        Controls.Add(content);
        Controls.Add(top);
        startButton.Click += (_, _) => Start();
    }

    private void Start()
    {
        if (day != null)
            return;

        string folder = folderBox.Text.Trim();
        if (folder.Length == 0)
        {
            MessageBox.Show("Укажите папку для отчёта.", "Проверка данных");
            return;
        }

        try
        {
            Directory.CreateDirectory(folder);
        }
        catch (Exception error) when (error is IOException or UnauthorizedAccessException or ArgumentException)
        {
            MessageBox.Show(error.Message, "Ошибка доступа к папке");
            return;
        }

        int count = Random.Shared.Next(20, 101);
        var currentDay = new CasinoDay(count, Path.Combine(folder, "casino_report.txt"));
        day = currentDay;
        startButton.Enabled = false;
        resultsGrid.Rows.Clear();
        log.Clear();
        statusLabel.Text = $"Игроков за день: {count}; завершили: 0";
        UiHelpers.WriteLog(this, log, $"Открытие стола: всего {count} игроков");

        // Five players start first. Each departing player starts a new Thread,
        // so the number of occupied seats never exceeds five.
        for (int i = 0; i < 5; i++)
            StartNextPlayer(currentDay);
    }

    private void StartNextPlayer(CasinoDay currentDay)
    {
        int playerId;
        lock (currentDay.Sync)
        {
            if (currentDay.Cancellation.IsCancellationRequested ||
                currentDay.NextPlayer > currentDay.TotalPlayers)
                return;

            playerId = currentDay.NextPlayer++;
        }

        var thread = new Thread(() => Play(currentDay, playerId))
        {
            IsBackground = true,
            Name = $"CasinoPlayer{playerId}"
        };
        thread.Start();
    }

    private void Play(CasinoDay currentDay, int playerId)
    {
        int initial = Random.Shared.Next(30, 151);
        int money = initial;
        int rounds = 0;
        bool entered = false;

        try
        {
            currentDay.Seats.Wait(currentDay.Cancellation.Token);
            entered = true;
            UiHelpers.WriteLog(this, log, $"Игрок {playerId} сел за стол с {initial} руб.");

            int maxRounds = Random.Shared.Next(2, 6);
            while (rounds < maxRounds && money > 0 &&
                   !currentDay.Cancellation.IsCancellationRequested)
            {
                int bet = Random.Shared.Next(1, money + 1);
                int chosen = Random.Shared.Next(0, 37);
                int roulette = Random.Shared.Next(0, 37);
                rounds++;

                if (chosen == roulette)
                {
                    // The assignment says the player's money doubles on a win.
                    money *= 2;
                    UiHelpers.WriteLog(this, log,
                        $"Игрок {playerId}: раунд {rounds}, число {chosen}, баланс удвоен: {money}");
                }
                else
                {
                    money -= bet;
                }
                Thread.Sleep(Random.Shared.Next(45, 100));
            }
        }
        catch (OperationCanceledException)
        {
            // The main form is closing.
        }
        finally
        {
            if (entered)
                currentDay.Seats.Release();

            var result = new PlayerResult(playerId, initial, money, rounds);
            int finished;
            lock (currentDay.Sync)
            {
                currentDay.Results.Add(result);
                currentDay.Finished++;
                finished = currentDay.Finished;
            }

            UiHelpers.Post(this, () =>
            {
                resultsGrid.Rows.Add(playerId, initial, money, rounds);
                statusLabel.Text = $"Игроков: {currentDay.TotalPlayers}; завершили: {finished}";
            });

            UiHelpers.WriteLog(this, log,
                $"Игрок {playerId} вышел: было {initial}, стало {money}, раундов {rounds}");

            if (!currentDay.Cancellation.IsCancellationRequested)
            {
                StartNextPlayer(currentDay);
                if (finished == currentDay.TotalPlayers)
                    FinishDay(currentDay);
            }
        }
    }

    private void FinishDay(CasinoDay currentDay)
    {
        try
        {
            PlayerResult[] results;
            lock (currentDay.Sync)
                results = currentDay.Results.OrderBy(value => value.Id).ToArray();

            var lines = new List<string>
            {
                $"Казино — отчёт за {DateTime.Now:dd.MM.yyyy HH:mm:ss}",
                $"Всего игроков: {results.Length}",
                "Формат: игрок [начальная сумма] [конечная сумма]",
                ""
            };

            foreach (PlayerResult result in results)
                lines.Add($"Игрок{result.Id} {result.StartBalance} {result.EndBalance}");

            File.WriteAllLines(currentDay.ReportPath, lines, Encoding.UTF8);
            UiHelpers.WriteLog(this, log, $"День завершён. Отчёт: {currentDay.ReportPath}");
        }
        catch (Exception error)
        {
            UiHelpers.WriteLog(this, log, $"Ошибка сохранения отчёта: {error.Message}");
        }
        finally
        {
            UiHelpers.Post(this, () =>
            {
                startButton.Enabled = true;
                statusLabel.Text = $"День окончен: {currentDay.TotalPlayers} игроков";
                day = null;
                currentDay.Seats.Dispose();
                currentDay.Cancellation.Dispose();
            });
        }
    }

    public void StopWork() => day?.Cancellation.Cancel();
}
