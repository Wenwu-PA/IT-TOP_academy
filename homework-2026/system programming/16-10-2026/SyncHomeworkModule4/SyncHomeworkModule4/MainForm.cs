using System;
using System.Drawing;
using System.Windows.Forms;

namespace SyncHomeworkModule4;

public sealed class MainForm : Form
{
    private readonly IStoppable[] workers;

    public MainForm(int instanceNumber)
    {
        Text = "Системное программирование — модуль 4: синхронизация";
        StartPosition = FormStartPosition.CenterScreen;
        Size = new Size(1100, 740);
        MinimumSize = new Size(900, 600);
        Font = new Font("Segoe UI", 10);

        var semaphores = new SemaphorePage();
        var mutexSequence = new MutexSequencePage();
        var pipeline = new FilePipelinePage();
        var casino = new CasinoPage();

        workers = [semaphores, mutexSequence, pipeline, casino];

        var tabs = new TabControl { Dock = DockStyle.Fill };
        tabs.TabPages.Add(CreateTab("1. Семафор", semaphores));
        tabs.TabPages.Add(CreateTab("2. Мьютекс", mutexSequence));
        tabs.TabPages.Add(CreateTab("3. Три копии", new InstancesPage(instanceNumber)));
        tabs.TabPages.Add(CreateTab("4–5. Файлы", pipeline));
        tabs.TabPages.Add(CreateTab("6. Казино", casino));
        Controls.Add(tabs);

        FormClosing += (_, _) =>
        {
            foreach (var worker in workers)
                worker.StopWork();
        };
    }

    private static TabPage CreateTab(string title, Control content)
    {
        var page = new TabPage(title) { Padding = new Padding(8) };
        content.Dock = DockStyle.Fill;
        page.Controls.Add(content);
        return page;
    }
}
