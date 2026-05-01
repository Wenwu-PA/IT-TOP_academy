using System;

namespace _20_04
{
    internal class Program
    {
        delegate void D1();
        delegate void D2(string s);
        delegate T D3<T, U>(T a, U b);

        static void OpenDoor() => Console.WriteLine("Дверь открыта");
        static void CloseWindow() => Console.WriteLine("Окно закрыто");
        static void StartHeating() => Console.WriteLine("Отопление включено");

        static void ShowStatus(string status) => Console.WriteLine($"Статус: {status}");
        static void NotifyUser(string message) => Console.WriteLine($"Уведомление: {message}");
        static void SaveLog(string entry) => Console.WriteLine($"Запись в лог: {entry}");

        static double CalculateTemp(double current, int delta) => current + delta;
        static double EnergyUsage(double power, double hours) => power * hours;
        static int CompareLevels(int a, int b) => a > b ? a : b;

        static void RunVoid(D1 d)
        {
            d();
        }

        static void RunString(D2 d, string value)
        {
            d(value);
        }

        static void RunCalc<T, U>(D3<T, U> d, T a, U b)
        {
            Console.WriteLine(d(a, b));
        }

        static void Main(string[] args)
        {
            D1 d = null;
            d += OpenDoor;
            d += CloseWindow;
            RunVoid(d);

            d += StartHeating;
            RunVoid(d);

            Console.WriteLine();

            D2 s = ShowStatus;
            RunString(s, "Система запущена");

            s = NotifyUser;
            RunString(s, "Проверка завершена");

            s = SaveLog;
            RunString(s, "Событие записано");

            Console.WriteLine();

            RunCalc<double, int>(CalculateTemp, 20.5, 3);
            RunCalc<double, double>(EnergyUsage, 1.5, 4.0);
            RunCalc<int, int>(CompareLevels, 9, 6);

            Console.WriteLine();
            Console.WriteLine("Нажмите любую клавишу...");
            Console.ReadKey();
        }
    }
}