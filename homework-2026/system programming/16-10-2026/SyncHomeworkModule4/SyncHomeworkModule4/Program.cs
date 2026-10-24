using System;
using System.Threading;
using System.Windows.Forms;

namespace SyncHomeworkModule4;

internal static class Program
{
    [STAThread]
    private static void Main()
    {
        ApplicationConfiguration.Initialize();

        // Each named mutex represents one permitted application instance.
        // Unlike a semaphore, an abandoned mutex is recovered if an app crashes.
        Mutex? instanceMutex = null;
        int instanceNumber = 0;

        for (int i = 1; i <= 3; i++)
        {
            Mutex candidate = new(false, $@"Local\SyncHomeworkModule4_Instance_{i}");
            bool acquired;

            try
            {
                acquired = candidate.WaitOne(0);
            }
            catch (AbandonedMutexException)
            {
                acquired = true;
            }

            if (acquired)
            {
                instanceMutex = candidate;
                instanceNumber = i;
                break;
            }

            candidate.Dispose();
        }

        if (instanceMutex == null)
        {
            MessageBox.Show(
                "Разрешено запускать не более трёх копий приложения.",
                "Лимит экземпляров",
                MessageBoxButtons.OK,
                MessageBoxIcon.Information);
            return;
        }

        try
        {
            Application.Run(new MainForm(instanceNumber));
        }
        finally
        {
            // Main() and Application.Run execute on the same UI thread.
            instanceMutex.ReleaseMutex();
            instanceMutex.Dispose();
        }
    }
}
