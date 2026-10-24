using System;
using System.Collections.Generic;
using System.Drawing;
using System.Numerics;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ThreadsAsyncPart2;

internal sealed class FibonacciPage : UserControl
{
    private readonly TextBox limitInput = new() { Width = 230, Text = "1000", Margin = new Padding(5, 7, 10, 5) };
    private readonly Button startButton = UiHelpers.MakeButton("Посчитать", 130);
    private readonly Button cancelButton = UiHelpers.MakeButton("Отмена", 110);
    private readonly Label status = UiHelpers.MakeLabel("Введите верхнюю границу", 480);
    private readonly TextBox output = new()
    {
        Dock = DockStyle.Fill, Multiline = true, ReadOnly = true,
        ScrollBars = ScrollBars.Vertical, Font = new Font("Consolas", 10)
    };
    private CancellationTokenSource? tokenSource;

    public FibonacciPage()
    {
        var toolbar = UiHelpers.MakeToolbar();
        toolbar.Controls.Add(UiHelpers.MakeLabel("Граница:", 90));
        toolbar.Controls.Add(limitInput);
        toolbar.Controls.Add(startButton);
        toolbar.Controls.Add(cancelButton);
        toolbar.Controls.Add(status);

        cancelButton.Enabled = false;
        startButton.Click += async (_, _) => await CalculateAsync();
        cancelButton.Click += (_, _) => Cancel();

        Controls.Add(output);
        Controls.Add(toolbar);
    }

    private async Task CalculateAsync()
    {
        if (!BigInteger.TryParse(limitInput.Text.Trim(), out var limit) || limit < 0)
        {
            MessageBox.Show("Укажите целое неотрицательное число.", "Неверная граница",
                MessageBoxButtons.OK, MessageBoxIcon.Warning);
            return;
        }

        if (limit.ToString().Length > 300)
        {
            MessageBox.Show("Введите число длиной не более 300 цифр.", "Слишком большое число",
                MessageBoxButtons.OK, MessageBoxIcon.Warning);
            return;
        }

        var source = new CancellationTokenSource();
        tokenSource = source;
        startButton.Enabled = false;
        cancelButton.Enabled = true;
        limitInput.Enabled = false;
        output.Clear();
        status.Text = "Вычисление...";

        try
        {
            // Сама генерация выполняется в пуле потоков, а форма не блокируется.
            var numbers = await Task.Run(() => Generate(limit, source.Token), source.Token);
            output.Lines = numbers.ConvertAll(x => x.ToString()).ToArray();
            status.Text = $"Готово. Всего чисел: {numbers.Count}";
        }
        catch (OperationCanceledException)
        {
            status.Text = "Вычисление отменено";
        }
        finally
        {
            if (!IsDisposed)
            {
                startButton.Enabled = true;
                cancelButton.Enabled = false;
                limitInput.Enabled = true;
            }
            if (ReferenceEquals(tokenSource, source))
                tokenSource = null;
            source.Dispose();
        }
    }

    private static List<BigInteger> Generate(BigInteger limit, CancellationToken token)
    {
        var numbers = new List<BigInteger>();
        BigInteger a = 0;
        BigInteger b = 1;

        while (a <= limit)
        {
            token.ThrowIfCancellationRequested();
            numbers.Add(a);
            (a, b) = (b, a + b);
        }
        return numbers;
    }

    public void Cancel() => tokenSource?.Cancel();
}
