using System;
using System.Threading;
using System.Windows.Forms;

namespace SyncHomeworkModule4;

internal sealed class MutexSequencePage : UserControl, IStoppable
{
    private readonly Button startButton = UiHelpers.CreateButton("Запустить два потока");
    private readonly Label statusLabel = UiHelpers.CreateLabel("Сначала 0–20, затем 10–0");
    private readonly TextBox log = UiHelpers.CreateLog();
    private CancellationTokenSource? cancellation;

    public MutexSequencePage()
    {
        var top = UiHelpers.CreateToolbar();
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

        log.Clear();
        startButton.Enabled = false;
        statusLabel.Text = "Работа идёт...";

        var source = new CancellationTokenSource();
        cancellation = source;
        var mutex = new Mutex();
        var firstStarted = new ManualResetEventSlim(false);
        int remaining = 2;

        void Complete()
        {
            if (Interlocked.Decrement(ref remaining) != 0)
                return;

            UiHelpers.Post(this, () =>
            {
                statusLabel.Text = "Оба потока завершены";
                startButton.Enabled = true;
                cancellation = null;
                firstStarted.Dispose();
                mutex.Dispose();
                source.Dispose();
            });
        }

        var first = new Thread(() =>
        {
            bool owned = false;
            try
            {
                mutex.WaitOne();
                owned = true;
                firstStarted.Set();
                UiHelpers.WriteLog(this, log, "Первый поток получил мьютекс");

                for (int i = 0; i <= 20; i++)
                {
                    if (source.IsCancellationRequested)
                        break;
                    UiHelpers.WriteLog(this, log, $"Первый: {i}");
                    Thread.Sleep(55);
                }
            }
            finally
            {
                if (owned)
                    mutex.ReleaseMutex();
                firstStarted.Set();
                Complete();
            }
        }) { IsBackground = true };

        var second = new Thread(() =>
        {
            bool owned = false;
            try
            {
                firstStarted.Wait();
                mutex.WaitOne();
                owned = true;
                UiHelpers.WriteLog(this, log, "Второй поток получил мьютекс");

                for (int i = 10; i >= 0; i--)
                {
                    if (source.IsCancellationRequested)
                        break;
                    UiHelpers.WriteLog(this, log, $"Второй: {i}");
                    Thread.Sleep(55);
                }
            }
            finally
            {
                if (owned)
                    mutex.ReleaseMutex();
                Complete();
            }
        }) { IsBackground = true };

        first.Start();
        second.Start();
    }

    public void StopWork() => cancellation?.Cancel();
}
