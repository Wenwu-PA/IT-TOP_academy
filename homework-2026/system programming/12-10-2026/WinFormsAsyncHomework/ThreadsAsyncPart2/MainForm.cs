using System;
using System.Drawing;
using System.Windows.Forms;

namespace ThreadsAsyncPart2;

public sealed class MainForm : Form
{
    private readonly DancingBarsPage dancingPage = new();
    private readonly HorseRacePage racePage = new();
    private readonly FibonacciPage fibonacciPage = new();
    private readonly FileSearchPage filePage = new();
    private readonly FolderSearchPage folderPage = new();

    public MainForm()
    {
        Text = "Системное программирование — домашнее задание, часть 2";
        StartPosition = FormStartPosition.CenterScreen;
        Size = new Size(1040, 740);
        MinimumSize = new Size(880, 620);
        Font = new Font("Segoe UI", 10);

        var tabs = new TabControl { Dock = DockStyle.Fill, Padding = new Point(12, 8) };
        AddPage(tabs, "1. Прогресс-бары", dancingPage);
        AddPage(tabs, "2. Скачки", racePage);
        AddPage(tabs, "3. Фибоначчи", fibonacciPage);
        AddPage(tabs, "4. Поиск в файле", filePage);
        AddPage(tabs, "5. Поиск в папке", folderPage);
        Controls.Add(tabs);
    }

    private static void AddPage(TabControl tabs, string title, Control content)
    {
        var tab = new TabPage(title) { Padding = new Padding(8) };
        content.Dock = DockStyle.Fill;
        tab.Controls.Add(content);
        tabs.TabPages.Add(tab);
    }

    protected override void OnFormClosing(FormClosingEventArgs e)
    {
        dancingPage.Stop();
        racePage.Stop();
        fibonacciPage.Cancel();
        filePage.Cancel();
        folderPage.Cancel();
        base.OnFormClosing(e);
    }
}
