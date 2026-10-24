using System;
using System.Drawing;
using System.Windows.Forms;

namespace SyncHomeworkModule4;

internal interface IStoppable
{
    void StopWork();
}

internal static class UiHelpers
{
    public static void Post(Control owner, Action action)
    {
        if (owner.IsDisposed || !owner.IsHandleCreated)
            return;

        try
        {
            owner.BeginInvoke(action);
        }
        catch (InvalidOperationException)
        {
            // The form may have been closed just before BeginInvoke.
        }
    }

    public static void WriteLog(Control owner, TextBox log, string message)
    {
        Post(owner, () =>
        {
            if (!log.IsDisposed)
                log.AppendText($"[{DateTime.Now:HH:mm:ss}] {message}{Environment.NewLine}");
        });
    }

    public static TextBox CreateLog()
    {
        return new TextBox
        {
            Dock = DockStyle.Fill,
            Multiline = true,
            ReadOnly = true,
            ScrollBars = ScrollBars.Vertical,
            Font = new Font("Consolas", 10),
            BackColor = Color.White,
            WordWrap = false
        };
    }

    public static FlowLayoutPanel CreateToolbar()
    {
        return new FlowLayoutPanel
        {
            Dock = DockStyle.Top,
            AutoSize = true,
            AutoSizeMode = AutoSizeMode.GrowAndShrink,
            Padding = new Padding(12),
            WrapContents = true
        };
    }

    public static Label CreateLabel(string text)
    {
        return new Label
        {
            Text = text,
            AutoSize = true,
            TextAlign = ContentAlignment.MiddleLeft,
            Margin = new Padding(8, 9, 6, 5)
        };
    }

    public static Button CreateButton(string text)
    {
        return new Button
        {
            Text = text,
            AutoSize = true,
            Height = 34,
            Margin = new Padding(8, 3, 4, 3)
        };
    }
}
