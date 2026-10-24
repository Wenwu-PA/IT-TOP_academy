using System;
using System.Collections.Generic;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;

namespace ThreadsAsyncPart2;

internal sealed class DancingBarsPage : UserControl
{
    private readonly NumericUpDown countInput = new()
    {
        Minimum = 1, Maximum = 30, Value = 5, Width = 65, Margin = new Padding(5, 6, 8, 5)
    };
    private readonly Button startButton = UiHelpers.MakeButton("Старт");
    private readonly Button stopButton = UiHelpers.MakeButton("Стоп");
    private readonly Label status = UiHelpers.MakeLabel("Готово к запуску", 260);
    private readonly FlowLayoutPanel barsPanel = new()
    {
        Dock = DockStyle.Fill,
        FlowDirection = FlowDirection.TopDown,
        WrapContents = false,
        AutoScroll = true,
        Padding = new Padding(12)
    };
    private readonly List<Thread> threads = new();
    private CancellationTokenSource? tokenSource;

    public DancingBarsPage()
    {
        var toolbar = UiHelpers.MakeToolbar();
        toolbar.Controls.Add(UiHelpers.MakeLabel("Количество:", 110));
        toolbar.Controls.Add(countInput);
        toolbar.Controls.Add(startButton);
        toolbar.Controls.Add(stopButton);
        toolbar.Controls.Add(status);

        stopButton.Enabled = false;
        startButton.Click += (_, _) => Start();
        stopButton.Click += (_, _) => Stop();
        barsPanel.Resize += (_, _) => AdjustWidths();

        Controls.Add(barsPanel);
        Controls.Add(toolbar);
    }

    private void Start()
    {
        Stop();
        barsPanel.Controls.Clear();
        var source = new CancellationTokenSource();
        tokenSource = source;
        var token = source.Token;

        for (int i = 0; i < (int)countInput.Value; i++)
        {
            var row = new TableLayoutPanel
            {
                Height = 43, Width = Math.Max(400, barsPanel.ClientSize.Width - 45),
                RowCount = 1, ColumnCount = 2, Margin = new Padding(0, 4, 0, 4)
            };
            row.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 95));
            row.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 100));
            row.Controls.Add(UiHelpers.MakeLabel($"Бар {i + 1}", 90), 0, 0);

            var bar = new ColorProgressBar { Dock = DockStyle.Fill, Margin = new Padding(5) };
            row.Controls.Add(bar, 1, 0);
            barsPanel.Controls.Add(row);

            // У каждого прогресс-бара собственный Thread.
            var thread = new Thread(() => FillBar(bar, token))
            {
                IsBackground = true,
                Name = $"ProgressBar-{i + 1}"
            };
            threads.Add(thread);
            thread.Start();
        }

        startButton.Enabled = false;
        stopButton.Enabled = true;
        countInput.Enabled = false;
        status.Text = "Прогресс-бары двигаются";
    }

    private void FillBar(ColorProgressBar bar, CancellationToken token)
    {
        int progress = 0;
        var color = RandomColor();

        while (!token.IsCancellationRequested)
        {
            progress = Math.Min(100, progress + Random.Shared.Next(1, 9));
            int shownProgress = progress;
            Color shownColor = color;

            UiHelpers.Post(this, () =>
            {
                if (!token.IsCancellationRequested && !bar.IsDisposed)
                {
                    bar.Progress = shownProgress;
                    bar.BarColor = shownColor;
                }
            });

            if (token.WaitHandle.WaitOne(Random.Shared.Next(60, 170)))
                break;

            if (progress == 100)
            {
                progress = 0;
                color = RandomColor();
            }
        }
    }

    private static Color RandomColor() => Color.FromArgb(
        Random.Shared.Next(45, 215),
        Random.Shared.Next(45, 215),
        Random.Shared.Next(45, 215));

    private void AdjustWidths()
    {
        foreach (Control row in barsPanel.Controls)
            row.Width = Math.Max(400, barsPanel.ClientSize.Width - 45);
    }

    public void Stop()
    {
        if (tokenSource is null)
            return;

        tokenSource.Cancel();
        foreach (var thread in threads)
            thread.Join();

        threads.Clear();
        tokenSource.Dispose();
        tokenSource = null;
        startButton.Enabled = true;
        stopButton.Enabled = false;
        countInput.Enabled = true;
        status.Text = "Остановлено";
    }
}
