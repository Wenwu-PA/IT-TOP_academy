using System;

namespace _16_04
{
    public class DateNotTodayException : ApplicationException
    {
        public DateNotTodayException(string message) : base(message) { }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            while (true)
            {
                Console.Write("Введите сегодняшнюю дату: ");
                string input = Console.ReadLine();

                try
                {
                    if (!DateTime.TryParse(input, out DateTime userDate))
                    {
                        Console.WriteLine("Неверный формат даты!");
                        continue;
                    }
                    if (userDate.Date != DateTime.Today)
                    {
                        throw new DateNotTodayException("Введённая дата не совпадает с сегодняшней!");
                    }
                    Console.WriteLine("Дата введена правильно!");
                    break;
                }
                catch (DateNotTodayException ex)
                {
                    Console.WriteLine($"Ошибка: {ex.Message}");
                }
            }
            Console.WriteLine("Нажмите любую клавишу для выхода...");
            Console.ReadKey();
        }
    }
}