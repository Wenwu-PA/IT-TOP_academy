using System;
using System.Threading;
using System.Windows.Forms;

namespace SyncHomeworkModule4;

internal sealed class SemaphorePage : UserControl, IStoppable
{
    private readonly Button startButton = UiHelpers.CreateButton("Запустить 10 потоков");
    private readonly Label statusLabel = UiHelpers.CreateLabel("Ожидание запуска");
    private readonly TextBox log = UiHelpers.CreateLog();
    private CancellationTokenSource? cancellation;

    public SemaphorePage()
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
        statusLabel.Text = "Работают потоки...";

        var source = new CancellationTokenSource();
        cancellation = source;
        var semaphore = new SemaphoreSlim(3, 3);
        int remaining = 10;
        int active = 0;

        for (int number = 1; number <= 10; number++)
        {
            int workerNumber = number;
            var thread = new Thread(() =>
            {
                bool entered = false;

                try
                {
                    semaphore.Wait(source.Token);
                    entered = true;
                    int current = Interlocked.Increment(ref active);
                    UiHelpers.WriteLog(this, log,
                        $"Поток {workerNumber} (ID {Environment.CurrentManagedThreadId}), активных: {current}");

                    for (int i = 0; i < 8; i++)
                    {
                        source.Token.ThrowIfCancellationRequested();
                        int value = Random.Shared.Next(0, 1000);
                        UiHelpers.WriteLog(this, log, $"  Поток {workerNumber}: {value}");
                        Thread.Sleep(Random.Shared.Next(70, 160));
                    }
                }
                catch (OperationCanceledException)
                {
                    // Stopping the form cancels any workers waiting for a seat.
                }
                finally
                {
                    if (entered)
                    {
                        Interlocked.Decrement(ref active);
                        semaphore.Release();
                        UiHelpers.WriteLog(this, log, $"Поток {workerNumber} завершился");
                    }

                    if (Interlocked.Decrement(ref remaining) == 0)
                    {
                        UiHelpers.Post(this, () =>
                        {
                            statusLabel.Text = "Все потоки завершены";
                            startButton.Enabled = true;
                            cancellation = null;
                            source.Dispose();
                            semaphore.Dispose();
                        });
                    }
                }
            });

            thread.IsBackground = true;
            thread.Start();
        }
    }

    public void StopWork() => cancellation?.Cancel();
}
