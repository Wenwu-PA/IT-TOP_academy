using System;
using System.Windows.Forms;

namespace ThreadsAsyncPart2;

internal static class Program
{
    [STAThread]
    private static void Main()
    {
        ApplicationConfiguration.Initialize();
        Application.Run(new MainForm());
    }
}
