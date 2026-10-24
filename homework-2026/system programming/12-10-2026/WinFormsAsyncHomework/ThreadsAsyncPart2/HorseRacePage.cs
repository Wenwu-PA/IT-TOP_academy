using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Threading;
using System.Windows.Forms;

namespace ThreadsAsyncPart2;

internal sealed class HorseRacePage : UserControl
{
    private readonly string[] horseNames = { "Лошадь 1", "Лошадь 2", "Лошадь 3", "Лошадь 4", "Лошадь 5" };
    private readonly List<ProgressBar> bars = new();
    private readonly List<Thread> threads = new();
    private readonly List<RaceResult> results = new();
    private readonly object resultsLock = new();
    private readonly Button startButton = UiHelpers.MakeButton("Старт гонки", 145);
    private readonly Button resetButton = UiHelpers.MakeButton("Сброс", 110);
    private readonly Label status = UiHelpers.MakeLabel("Нажмите «Старт гонки»", 400);
    private readonly DataGridView resultsTable = new();
    private CancellationTokenSource? tokenSource;

    private sealed record RaceResult(int Place, string Horse, double Seconds);

    public HorseRacePage()
    {
        var toolbar = UiHelpers.MakeToolbar();
        toolbar.Controls.Add(startButton);
        toolbar.Controls.Add(resetButton);
        toolbar.Controls.Add(status);

        var raceTrack = new TableLayoutPanel
        {
            Dock = DockStyle.Top, Height = 260,
            ColumnCount = 2, RowCount = 5, Padding = new Padding(14)
        };
        raceTrack.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 145));
        raceTrack.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 100));
        for (int i = 0; i < 5; i++)
        {
            raceTrack.RowStyles.Add(new RowStyle(SizeType.Percent, 20));
            raceTrack.Controls.Add(UiHelpers.MakeLabel(horseNames[i], 135), 0, i);
            var bar = new ProgressBar
            {
                Dock = DockStyle.Fill,
                Minimum = 0, Maximum = 100,
                Style = ProgressBarStyle.Continuous,
                Margin = new Padding(4, 12, 14, 12)
            };
            raceTrack.Controls.Add(bar, 1, i);
            bars.Add(bar);
        }

        var resultsTitle = new Label
        {
            Dock = DockStyle.Top, Height = 38,
            Text = "Результаты скачек", Font = new Font("Segoe UI", 11, FontStyle.Bold),
            TextAlign = ContentAlignment.MiddleLeft, Padding = new Padding(14, 0, 0, 0)
        };
        resultsTable.Dock = DockStyle.Fill;
        resultsTable.ReadOnly = true;
        resultsTable.AllowUserToAddRows = false;
        resultsTable.AllowUserToDeleteRows = false;
        resultsTable.RowHeadersVisible = false;
        resultsTable.AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode.Fill;
        resultsTable.SelectionMode = DataGridViewSelectionMode.FullRowSelect;
        resultsTable.Columns.Add("place", "Место");
        resultsTable.Columns.Add("horse", "Лошадь");
        resultsTable.Columns.Add("time", "Время, сек.");

        // В DockStyle.Top порядок добавления обратный, поэтому используем контейнер.
        var top = new Panel { Dock = DockStyle.Top, Height = 315 };
        top.Controls.Add(raceTrack);
        top.Controls.Add(resultsTitle);
        resultsTitle.Dock = DockStyle.Bottom;

        Controls.Add(resultsTable);
        Controls.Add(top);
        Controls.Add(toolbar);
        startButton.Click += (_, _) => Start();
        resetButton.Click += (_, _) => Reset();
    }

    private void Start()
    {
        Stop();
        foreach (var bar in bars)
            bar.Value = 0;
        resultsTable.Rows.Clear();
        lock (resultsLock)
            results.Clear();

        var source = new CancellationTokenSource();
        tokenSource = source;
        var token = source.Token;
        var stopwatch = Stopwatch.StartNew();

        startButton.Enabled = false;
        status.Text = "Гонка идёт...";

        for (int i = 0; i < 5; i++)
        {
            int horseIndex = i;
            var thread = new Thread(() => RunHorse(horseIndex, stopwatch, token))
            {
                IsBackground = true,
                Name = $"Horse-{i + 1}"
            };
            threads.Add(thread);
            thread.Start();
        }
    }

    private void RunHorse(int index, Stopwatch stopwatch, CancellationToken token)
    {
        int progress = 0;
        while (progress < 100 && !token.IsCancellationRequested)
        {
            // При каждом шаге и прирост, и задержка случайны.
            progress = Math.Min(100, progress + Random.Shared.Next(1, 8));
            int shownProgress = progress;
            UiHelpers.Post(this, () =>
            {
                if (!token.IsCancellationRequested)
                    bars[index].Value = shownProgress;
            });

            if (token.WaitHandle.WaitOne(Random.Shared.Next(65, 170)))
                return;
        }

        if (token.IsCancellationRequested)
            return;

        List<RaceResult>? finalResults = null;
        lock (resultsLock)
        {
            results.Add(new RaceResult(results.Count + 1, horseNames[index], stopwatch.Elapsed.TotalSeconds));
            if (results.Count == 5)
                finalResults = results.OrderBy(r => r.Place).ToList();
        }

        if (finalResults is not null)
        {
            UiHelpers.Post(this, () =>
            {
                if (token.IsCancellationRequested)
                    return;

                resultsTable.Rows.Clear();
                foreach (var result in finalResults)
                    resultsTable.Rows.Add(result.Place, result.Horse, result.Seconds.ToString("F2"));
                status.Text = "Финиш! Результаты отсортированы по местам.";
                startButton.Enabled = true;
            });
        }
    }

    private void Reset()
    {
        Stop();
        foreach (var bar in bars)
            bar.Value = 0;
        resultsTable.Rows.Clear();
        status.Text = "Готово к новой гонке";
    }

    public void Stop()
    {
        if (tokenSource is not null)
        {
            tokenSource.Cancel();
            foreach (var thread in threads)
                thread.Join();
            threads.Clear();
            tokenSource.Dispose();
            tokenSource = null;
        }
        startButton.Enabled = true;
    }
}
