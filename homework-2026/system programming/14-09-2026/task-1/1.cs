using System;
using System.Runtime.InteropServices;

public class Win32
{
    [DllImport("user32.dll", CharSet = CharSet.Unicode)]
    public static extern int MessageBox(
        IntPtr hWnd,
        string text,
        string caption,
        uint type
    );

    public const uint MB_OK = 0x00000000;
    public const uint MB_OKCANCEL = 0x00000001;
    public const uint MB_ICONINFORMATION = 0x00000040;
    public const int IDOK = 1;
    public const int IDCANCEL = 2;
}

public class Program
{
    public static void Main()
    {
        Win32.MessageBox(
            IntPtr.Zero,
            "Имя: Артемий", 
            "Обо мне: Часть 1",
            Win32.MB_OK | Win32.MB_ICONINFORMATION
        );

        Win32.MessageBox(
            IntPtr.Zero,
            "Возраст: 17 лет\nСтатус: Студент 3 курса", 
            "Обо мне: Часть 2",
            Win32.MB_OK | Win32.MB_ICONINFORMATION
        );

        int res = Win32.MessageBox(
            IntPtr.Zero,
            "Увлекаюсь сетевым взаимодействием.\nВсё супер?",
            "Обо мне: Часть 3",
            Win32.MB_OKCANCEL | Win32.MB_ICONINFORMATION
        );

        if (res == Win32.IDOK)
            Console.WriteLine("Вы нажали OK: Данные подтверждены.");
        else if (res == Win32.IDCANCEL)
            Console.WriteLine("Вы нажали Отмена или закрыли окно: Данные требуют изменения.");
            
        Console.ReadLine();
    }
}