using System;
using System.Runtime.InteropServices;

public class Win32Controller
{
    [DllImport("user32.dll", CharSet = CharSet.Unicode, SetLastError = true)]
    public static extern IntPtr FindWindow(string lpClassName, string lpWindowName);

    [DllImport("user32.dll", CharSet = CharSet.Unicode)]
    public static extern IntPtr SendMessage(IntPtr hWnd, uint Msg, IntPtr wParam, string lParam);

    [DllImport("user32.dll", CharSet = CharSet.Unicode)]
    public static extern IntPtr SendMessage(IntPtr hWnd, uint Msg, IntPtr wParam, IntPtr lParam);

    public const uint WM_SETTEXT = 0x000C;
    public const uint WM_CLOSE = 0x0010;
    public const uint WM_SYSCOMMAND = 0x0112;
    public static readonly IntPtr SC_MINIMIZE = (IntPtr)0xF020;

    public static void Main()
    {
        Console.WriteLine("=== Управление окнами через WinAPI ===");
        Console.WriteLine("Для теста откройте обычный Блокнот (Notepad).");
        Console.WriteLine("Если он пустой, его заголовок обычно: \"Без имени — Блокнот\"");
        Console.Write("\nВведите точный заголовок искомого окна: ");
        
        string targetTitle = Console.ReadLine();

        IntPtr hWnd = Win32Controller.FindWindow(null, targetTitle);

        if (hWnd == IntPtr.Zero)
        {
            Console.WriteLine($"\n[Ошибка] Окно с заголовком \"{targetTitle}\" не найдено.");
            Console.WriteLine("Проверьте раскладку клавиатуры и точность написания заголовка.");
            return;
        }

        Console.WriteLine($"[Успех] Окно найдено! Handle (hWnd): {hWnd}");
        Console.WriteLine("\nВыберите действие:");
        Console.WriteLine("1. Изменить заголовок окна");
        Console.WriteLine("2. Закрыть окно");
        Console.WriteLine("3. Свернуть окно (мой вариант)");
        Console.Write("Ваш выбор (1-3): ");

        string choice = Console.ReadLine();

        switch (choice)
        {
            case "1":
                Console.Write("Введите новый заголовок окна: ");
                string newTitle = Console.ReadLine();
                
                Win32Controller.SendMessage(hWnd, WM_SETTEXT, IntPtr.Zero, newTitle);
                Console.WriteLine("Заголовок успешно изменен!");
                break;

            case "2":
                Win32Controller.SendMessage(hWnd, WM_CLOSE, IntPtr.Zero, IntPtr.Zero);
                Console.WriteLine("Окну отправлена команда на закрытие.");
                break;

            case "3":
                Win32Controller.SendMessage(hWnd, WM_SYSCOMMAND, SC_MINIMIZE, IntPtr.Zero);
                Console.WriteLine("Окно свернуто в панель задач.");
                break;

            default:
                Console.WriteLine("Неверный выбор.");
                break;
        }

        Console.WriteLine("\nНажмите любую клавишу для выхода...");
        Console.ReadKey();
    }
}