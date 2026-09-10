using System;
using System.Runtime.InteropServices;

public class Win32
{
    [DllImport("user32.dll")]
    public static extern int MessageBox(
        IntPtr hWnd,
        string text,
        string caption,
        uint type
    );
}

public class HelloWorld
{
    public static void Main()
    {
        const uint MB_OKCANCEL = 0x00000001;        // две кнопки: ОК и Отмена
        const uint MB_ICONINFORMATION = 0x00000040; // синий круг с воскл.знаком
        const int IDOK = 1;
        const int IDCANCEL = 2;

        int res = Win32.MessageBox(
            IntPtr.Zero,
            "Привет мир!",
            "Пример использования механизма Platform Invoke",
            MB_OKCANCEL | MB_ICONINFORMATION
        );

        if (res == IDOK)
            Console.WriteLine("Вы нажали OK");
        else if (res == IDCANCEL)
            Console.WriteLine("Вы нажали Отмена или закрыли окно");
    }
}