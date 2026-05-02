using System;
using System.Threading;

// Делегат для событий гонки
public delegate void RaceEventHandler(string message);

// Класс гонки спортивных автомобилей (полноценная реализация)
public class SportsCarRace
{
    // События этапов гонки
    public event RaceEventHandler OnStart;
    public event RaceEventHandler OnProgress;
    public event RaceEventHandler OnFinish;

    // Запуск гонки
    public void Run()
    {
        // Старт
        OnStart?.Invoke("Спортивные автомобили вышли на старт!");

        // Имитация прохождения трассы (5 этапов)
        for (int i = 1; i <= 5; i++)
        {
            Thread.Sleep(500); // пауза 0.5 сек
            OnProgress?.Invoke($"Спортивные автомобили проходят трассу... этап {i}/5");
        }

        // Финиш
        OnFinish?.Invoke("Спортивные автомобили пришли к финишу!");
    }
}

class Program
{
    static void Main()
    {
        while (true)
        {
            Console.Clear();
            Console.WriteLine("===== МЕНЮ ГОНОК =====");
            Console.WriteLine("1. Гонки спортивных автомобилей");
            Console.WriteLine("2. Гонки легковых автомобилей (заглушка)");
            Console.WriteLine("3. Гонки грузовых автомобилей (заглушка)");
            Console.WriteLine("4. Гонки автобусов (заглушка)");
            Console.WriteLine("0. Выход");
            Console.Write("Ваш выбор: ");
            string choice = Console.ReadLine();

            switch (choice)
            {
                case "1":
                    // Создаём гонку и подписываемся на события
                    SportsCarRace race = new SportsCarRace();
                    race.OnStart += (msg) => Console.WriteLine(msg);
                    race.OnProgress += (msg) => Console.WriteLine(msg);
                    race.OnFinish += (msg) => Console.WriteLine(msg);

                    Console.WriteLine("\n=== ГОНКА НАЧАЛАСЬ ===");
                    race.Run();
                    Console.WriteLine("=== ГОНКА ЗАВЕРШЕНА ===\n");
                    Console.WriteLine("Нажмите любую клавишу для продолжения...");
                    Console.ReadKey();
                    break;

                case "2":
                    Console.WriteLine("\n[Заглушка] Гонки легковых автомобилей пока не реализованы.\n");
                    Console.WriteLine("Нажмите любую клавишу...");
                    Console.ReadKey();
                    break;

                case "3":
                    Console.WriteLine("\n[Заглушка] Гонки грузовых автомобилей пока не реализованы.\n");
                    Console.WriteLine("Нажмите любую клавишу...");
                    Console.ReadKey();
                    break;

                case "4":
                    Console.WriteLine("\n[Заглушка] Гонки автобусов пока не реализованы.\n");
                    Console.WriteLine("Нажмите любую клавишу...");
                    Console.ReadKey();
                    break;

                case "0":
                    Console.WriteLine("Выход из программы...");
                    return;

                default:
                    Console.WriteLine("Неверный ввод. Попробуйте снова.");
                    Thread.Sleep(1000);
                    break;
            }
        }
    }
}