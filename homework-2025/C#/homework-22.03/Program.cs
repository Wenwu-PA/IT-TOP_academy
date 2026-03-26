using System;

class Program
{
    static void Main()
    {
        Console.WriteLine("╔══════════════════════════════════════════════════════════════╗");
        Console.WriteLine("║     ПРОГРАММА ДЛЯ РАБОТЫ С ЛИНЕЙНЫМИ УРАВНЕНИЯМИ            ║");
        Console.WriteLine("╚══════════════════════════════════════════════════════════════╝");

        // Запуск тестов для структуры LinearEquation
        LinearEquationTests.RunTests();

        // Запуск тестов для класса EquationSolver
        EquationSolverTests.RunTests();

        Console.WriteLine("\n\n═══════════════════════════════════════════════════════════════");
        Console.WriteLine("Все тесты завершены. Нажмите любую клавишу для выхода...");
        Console.ReadKey();
    }
}