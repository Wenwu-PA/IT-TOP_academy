using System;
using System.ComponentModel;
using System.Drawing;
using System.Windows.Forms;

namespace ThreadsAsyncPart2;

internal static class UiHelpers
{
    // Фоновым потокам нельзя напрямую менять элементы формы.
    public static void Post(Control control, Action action)
    {
        if (control.IsDisposed || !control.IsHandleCreated)
            return;

        try
        {
            control.BeginInvoke((MethodInvoker)(() =>
            {
                if (!control.IsDisposed)
                    action();
            }));
        }
        // ObjectDisposedException наследуется от InvalidOperationException.
        catch (InvalidOperationException) { } // Окно уже закрывается.
    }

    public static Label MakeLabel(string text, int width = 110)
    {
        return new Label
        {
            Text = text,
            Width = width,
            AutoSize = false,
            Height = 30,
            TextAlign = ContentAlignment.MiddleLeft,
            Margin = new Padding(5, 5, 5, 5)
        };
    }

    public static Button MakeButton(string text, int width = 125)
    {
        return new Button
        {
            Text = text,
            Width = width,
            Height = 32,
            Margin = new Padding(5),
            AutoSize = false
        };
    }

    public static FlowLayoutPanel MakeToolbar(int height = 55)
    {
        return new FlowLayoutPanel
        {
            Dock = DockStyle.Top,
            Height = height,
            Padding = new Padding(7, 7, 7, 0),
            WrapContents = false,
            AutoScroll = true
        };
    }
}

// Стандартный ProgressBar в Windows не всегда позволяет изменить цвет.
// Поэтому для первого задания рисуем цветной прогресс-бар сами.
internal sealed class ColorProgressBar : Control
{
    private int progress;
    private Color barColor = Color.SteelBlue;

    [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
    public int Progress
    {
        get => progress;
        set
        {
            progress = Math.Clamp(value, 0, 100);
            Invalidate();
        }
    }

    [DesignerSerializationVisibility(DesignerSerializationVisibility.Hidden)]
    public Color BarColor
    {
        get => barColor;
        set
        {
            barColor = value;
            Invalidate();
        }
    }

    public ColorProgressBar()
    {
        SetStyle(ControlStyles.AllPaintingInWmPaint |
                 ControlStyles.OptimizedDoubleBuffer |
                 ControlStyles.UserPaint, true);
        Height = 28;
    }

    protected override void OnPaint(PaintEventArgs e)
    {
        base.OnPaint(e);
        e.Graphics.Clear(Color.FromArgb(229, 234, 240));

        var filledWidth = (int)(ClientSize.Width * (progress / 100.0));
        using var brush = new SolidBrush(barColor);
        e.Graphics.FillRectangle(brush, 0, 0, filledWidth, ClientSize.Height);

        TextRenderer.DrawText(e.Graphics, $"{progress}%", Font, ClientRectangle,
            Color.Black, TextFormatFlags.HorizontalCenter | TextFormatFlags.VerticalCenter);
    }
}
