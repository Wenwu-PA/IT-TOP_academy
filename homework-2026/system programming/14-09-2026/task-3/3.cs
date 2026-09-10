using System;
using System.Runtime.InteropServices;
using System.Threading;

public class Win32Sound
{
    [DllImport("kernel32.dll", SetLastError = true)]
    public static extern bool Beep(uint dwFreq, uint dwDuration);

    [DllImport("user32.dll", SetLastError = true)]
    public static extern bool MessageBeep(uint uType);

    public const uint MB_OK = 0x00000000;
    public const uint MB_ICONHAND = 0x00000010;
    public const uint MB_ICONQUESTION = 0x00000020;
    public const uint MB_ICONEXCLAMATION = 0x00000030;
    public const uint MB_ICONASTERISK = 0x00000040;

    public static void Main()
    {
        Console.WriteLine("=== Демонстрация работы WinAPI звуковых функций ===");
        Console.WriteLine("Программа начнет воспроизведение последовательности звуков.\n");

        Console.WriteLine("[1/5] Воспроизведение: MessageBeep (Информация)");
        MessageBeep(MB_ICONASTERISK);
        Thread.Sleep(1500);

        Console.WriteLine("[2/5] Воспроизведение: Beep (Низкий тон, 400 Гц, 300 мс)");
        Beep(400, 300);
        Thread.Sleep(800);

        Console.WriteLine("[3/5] Воспроизведение: Beep (Средний тон, 800 Гц, 300 мс)");
        Beep(800, 300);
        Thread.Sleep(800);

        Console.WriteLine("[4/5] Воспроизведение: Beep (Высокий тон, 1200 Гц, 500 мс)");
        Beep(1200, 500);
        Thread.Sleep(1500);

        Console.WriteLine("[5/5] Воспроизведение: MessageBeep (Ошибка)");
        MessageBeep(MB_ICONHAND);

        Console.WriteLine("\n=== Последовательность завершена ===");
        Console.WriteLine("Нажмите любую клавишу для выхода...");
        Console.ReadKey();
    }
}
