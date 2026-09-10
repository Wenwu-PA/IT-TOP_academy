using System;
using System.Runtime.InteropServices;

public class Win32
{
    [DllImport("user32.dll")]
    public static extern IntPtr SendMessage(
        IntPtr hWnd, uint msg, int wParam, int lParam);
    [DllImport("user32.dll")]
    public static extern IntPtr FindWindow(string className, string windowName);
}

public class MyProgram
{
    public static void Main()
    {
        IntPtr hWnd = Win32.FindWindow(null, "Калькулятор");
        if (hWnd == IntPtr.Zero)
        {
            Console.WriteLine("Окно калькулятора не найдено!");
        }
        else
        {
            const uint WM_CLOSE = 0x0010; // приказ закрыть окно
            Win32.SendMessage(hWnd, WM_CLOSE, 0, 0);
            Console.WriteLine("Окно калькулятора найдено и закрыто!");
        }
    }
}