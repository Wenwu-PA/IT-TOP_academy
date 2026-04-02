using System;

/// <summary>
/// Тестовый класс для проверки работы структуры LinearEquation
/// </summary>
public static class LinearEquationTests
{
    public static void RunTests()
    {
        Console.WriteLine("\n=== ТЕСТИРОВАНИЕ СТРУКТУРЫ LINEAREQUATION ===");
        Console.WriteLine(new string('=', 60));

        TestMyParse();
        TestToString();
        TestIsZero();
        TestHasSolution();
        TestInvalidInputs();
    }

    private static void TestMyParse()
    {
        Console.WriteLine("\n1. Тестирование метода My_Parse():");
        Console.WriteLine(new string('-', 40));

        string[] validInputs = { "3 5", "2 -4", "  0   7  ", "-3 5", "1 0", "0 0" };

        foreach (string input in validInputs)
        {
            try
            {
                LinearEquation eq = LinearEquation.My_Parse(input);
                Console.WriteLine($"  ✓ '{input}' -> {eq}");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"  ✗ '{input}' -> Ошибка: {ex.Message}");
            }
        }
    }

    private static void TestToString()
    {
        Console.WriteLine("\n2. Тестирование метода ToString():");
        Console.WriteLine(new string('-', 40));

        LinearEquation eq1 = new LinearEquation(3, 5);
        LinearEquation eq2 = new LinearEquation(-2, 4);
        LinearEquation eq3 = new LinearEquation(0, 7);

        Console.WriteLine($"  Коэффициенты (3, 5) -> {eq1}");
        Console.WriteLine($"  Коэффициенты (-2, 4) -> {eq2}");
        Console.WriteLine($"  Коэффициенты (0, 7) -> {eq3}");
    }

    private static void TestIsZero()
    {
        Console.WriteLine("\n3. Тестирование метода IsZero():");
        Console.WriteLine(new string('-', 40));

        LinearEquation eq1 = new LinearEquation(0, 0);
        LinearEquation eq2 = new LinearEquation(3, 5);

        Console.WriteLine($"  Уравнение {eq1} -> IsZero() = {eq1.IsZero()}");
        Console.WriteLine($"  Уравнение {eq2} -> IsZero() = {eq2.IsZero()}");
    }

    private static void TestHasSolution()
    {
        Console.WriteLine("\n4. Тестирование метода HasSolution():");
        Console.WriteLine(new string('-', 40));

        LinearEquation eq1 = new LinearEquation(0, 0);
        LinearEquation eq2 = new LinearEquation(3, 5);
        LinearEquation eq3 = new LinearEquation(0, 7);

        Console.WriteLine($"  Уравнение {eq1} -> HasSolution() = {eq1.HasSolution()}");
        Console.WriteLine($"  Уравнение {eq2} -> HasSolution() = {eq2.HasSolution()}");
        Console.WriteLine($"  Уравнение {eq3} -> HasSolution() = {eq3.HasSolution()}");
    }

    private static void TestInvalidInputs()
    {
        Console.WriteLine("\n5. Тестирование некорректных входных данных:");
        Console.WriteLine(new string('-', 40));

        string[] invalidInputs = { "abc def", "1 2 3", "5", "", "   ", "1.5 2", "a b" };

        foreach (string input in invalidInputs)
        {
            try
            {
                LinearEquation eq = LinearEquation.My_Parse(input);
                Console.WriteLine($"  ✗ '{input}' -> {eq} (не должно было сработать)");
            }
            catch (Exception ex)
            {
                Console.WriteLine($"  ✓ '{input}' -> Ошибка: {ex.Message}");
            }
        }
    }
}

/// <summary>
/// Тестовый класс для проверки работы EquationSolver
/// </summary>
public static class EquationSolverTests
{
    public static void RunTests()
    {
        Console.WriteLine("\n\n=== ТЕСТИРОВАНИЕ КЛАССА EQUATIONSOLVER ===");
        Console.WriteLine(new string('=', 60));

        // Демонстрация работы с вводом пользователя
        DemonstrateUserInput();

        // Запуск основных тестов
        TestSystemWithZeroRightSide();
        TestSystemWithGeneralRightSide();
        TestEdgeCases();
    }

    /// <summary>
    /// Демонстрация работы с пользовательским вводом
    /// </summary>
    private static void DemonstrateUserInput()
    {
        Console.WriteLine("\n0. Демонстрация работы с пользовательским вводом:");
        Console.WriteLine(new string('-', 60));

        try
        {
            Console.Write("  Введите первое число: ");
            int x = Convert.ToInt32(Console.ReadLine());

            Console.Write("  Введите второе число: ");
            int y = Convert.ToInt32(Console.ReadLine());

            Console.Write("  Введите третье число: ");
            int z = Convert.ToInt32(Console.ReadLine());

            // Пример вычисления (исправленный - вместо ** используем Math.Pow)
            double squareOfX = Math.Pow(x, 2);
            double sum = x + y + z;
            double product = x * y * z;

            Console.WriteLine($"  Квадрат первого числа: {squareOfX}");
            Console.WriteLine($"  Сумма чисел: {sum}");
            Console.WriteLine($"  Произведение чисел: {product}");
        }
        catch (FormatException)
        {
            Console.WriteLine("  Ошибка: Введите корректные целые числа!");
        }
        catch (Exception ex)
        {
            Console.WriteLine($"  Ошибка: {ex.Message}");
        }
    }

    /// <summary>
    /// Тестирование решения систем с нулевыми правыми частями
    /// </summary>
    private static void TestSystemWithZeroRightSide()
    {
        Console.WriteLine("\n1. Тестирование решения систем с нулевыми правыми частями:");
        Console.WriteLine(new string('-', 60));
        Console.WriteLine("Система вида: A1*x + B1*y = 0");
        Console.WriteLine("              A2*x + B2*y = 0\n");

        // Тест 1: Система с единственным решением (0, 0)
        Console.WriteLine("Тест 1.1: Система с единственным решением");
        LinearEquation eq1_1 = new LinearEquation(2, 3);
        LinearEquation eq2_1 = new LinearEquation(4, 5);

        Console.WriteLine($"  Уравнение 1: {eq1_1}");
        Console.WriteLine($"  Уравнение 2: {eq2_1}");

        if (EquationSolver.SolveSystem(eq1_1, eq2_1, out double x1, out double y1, out string error1))
        {
            Console.WriteLine($"  ✓ Решение: x = {x1}, y = {y1}");
            Console.WriteLine($"    Проверка: {eq1_1.A}*{x1} + {eq1_1.B}*{y1} = {eq1_1.A * x1 + eq1_1.B * y1}");
            Console.WriteLine($"    Проверка: {eq2_1.A}*{x1} + {eq2_1.B}*{y1} = {eq2_1.A * x1 + eq2_1.B * y1}");
        }
        else
        {
            Console.WriteLine($"  ✗ Ошибка: {error1}");
        }

        // Тест 2: Система с пропорциональными уравнениями
        Console.WriteLine("\nТест 1.2: Система с пропорциональными уравнениями");
        LinearEquation eq1_2 = new LinearEquation(2, 4);
        LinearEquation eq2_2 = new LinearEquation(1, 2);

        Console.WriteLine($"  Уравнение 1: {eq1_2}");
        Console.WriteLine($"  Уравнение 2: {eq2_2}");

        if (EquationSolver.SolveSystem(eq1_2, eq2_2, out double x2, out double y2, out string error2))
        {
            Console.WriteLine($"  ✓ Решение: x = {x2}, y = {y2}");
        }
        else
        {
            Console.WriteLine($"  ✓ Ошибка (ожидаемо): {error2}");
        }

        // Тест 3: Система с нулевыми уравнениями
        Console.WriteLine("\nТест 1.3: Система с нулевыми уравнениями");
        LinearEquation eq1_3 = new LinearEquation(0, 0);
        LinearEquation eq2_3 = new LinearEquation(1, 2);

        Console.WriteLine($"  Уравнение 1: {eq1_3}");
        Console.WriteLine($"  Уравнение 2: {eq2_3}");

        if (EquationSolver.SolveSystem(eq1_3, eq2_3, out double x3, out double y3, out string error3))
        {
            Console.WriteLine($"  ✓ Решение: x = {x3}, y = {y3}");
        }
        else
        {
            Console.WriteLine($"  ✓ Ошибка (ожидаемо): {error3}");
        }

        // Тест 4: Система с противоречивыми уравнениями
        Console.WriteLine("\nТест 1.4: Система с противоречивыми уравнениями");
        LinearEquation eq1_4 = new LinearEquation(2, 3);
        LinearEquation eq2_4 = new LinearEquation(4, 6);

        Console.WriteLine($"  Уравнение 1: {eq1_4}");
        Console.WriteLine($"  Уравнение 2: {eq2_4}");

        if (EquationSolver.SolveSystem(eq1_4, eq2_4, out double x4, out double y4, out string error4))
        {
            Console.WriteLine($"  ✓ Решение: x = {x4}, y = {y4}");
        }
        else
        {
            Console.WriteLine($"  ✓ Ошибка (ожидаемо): {error4}");
        }
    }

    /// <summary>
    /// Тестирование решения систем с произвольными правыми частями
    /// </summary>
    private static void TestSystemWithGeneralRightSide()
    {
        Console.WriteLine("\n2. Тестирование решения систем с произвольными правыми частями:");
        Console.WriteLine(new string('-', 60));
        Console.WriteLine("Система вида: A1*x + B1*y = C1");
        Console.WriteLine("              A2*x + B2*y = C2\n");

        // Тест 1: Система с ненулевыми правыми частями
        Console.WriteLine("Тест 2.1: Система с ненулевыми правыми частями");
        LinearEquation eq1 = new LinearEquation(2, 3);
        LinearEquation eq2 = new LinearEquation(4, 5);
        double c1 = 5, c2 = 6;

        Console.WriteLine($"  {eq1}, правая часть = {c1}");
        Console.WriteLine($"  {eq2}, правая часть = {c2}");

        if (EquationSolver.SolveSystemGeneral(eq1, eq2, c1, c2, out double x, out double y, out string error))
        {
            Console.WriteLine($"  ✓ Решение: x = {x:F2}, y = {y:F2}");
            Console.WriteLine($"    Проверка: {eq1.A}*{x:F2} + {eq1.B}*{y:F2} = {eq1.A * x + eq1.B * y:F2} (должно быть {c1})");
            Console.WriteLine($"    Проверка: {eq2.A}*{x:F2} + {eq2.B}*{y:F2} = {eq2.A * x + eq2.B * y:F2} (должно быть {c2})");
        }
        else
        {
            Console.WriteLine($"  ✗ Ошибка: {error}");
        }

        // Тест 2: Система с вырожденной матрицей
        Console.WriteLine("\nТест 2.2: Система с вырожденной матрицей");
        LinearEquation eq3 = new LinearEquation(2, 4);
        LinearEquation eq4 = new LinearEquation(1, 2);
        double c3 = 3, c4 = 1.5;

        Console.WriteLine($"  {eq3}, правая часть = {c3}");
        Console.WriteLine($"  {eq4}, правая часть = {c4}");

        if (EquationSolver.SolveSystemGeneral(eq3, eq4, c3, c4, out double x2, out double y2, out string error2))
        {
            Console.WriteLine($"  ✓ Решение: x = {x2:F2}, y = {y2:F2}");
        }
        else
        {
            Console.WriteLine($"  ✓ Ошибка (ожидаемо): {error2}");
        }

        // Тест 3: Система с нулевым решением
        Console.WriteLine("\nТест 2.3: Система с нулевым решением");
        LinearEquation eq5 = new LinearEquation(2, 3);
        LinearEquation eq6 = new LinearEquation(4, 5);
        double c5 = 0, c6 = 0;

        Console.WriteLine($"  {eq5}, правая часть = {c5}");
        Console.WriteLine($"  {eq6}, правая часть = {c6}");

        if (EquationSolver.SolveSystemGeneral(eq5, eq6, c5, c6, out double x3, out double y3, out string error3))
        {
            Console.WriteLine($"  ✓ Решение: x = {x3:F2}, y = {y3:F2}");
        }
        else
        {
            Console.WriteLine($"  ✗ Ошибка: {error3}");
        }
    }

    /// <summary>
    /// Тестирование граничных случаев
    /// </summary>
    private static void TestEdgeCases()
    {
        Console.WriteLine("\n3. Тестирование граничных случаев:");
        Console.WriteLine(new string('-', 60));

        // Тест 1: Уравнения с нулевыми коэффициентами
        Console.WriteLine("\nТест 3.1: Уравнения с нулевыми коэффициентами");
        LinearEquation eq1 = new LinearEquation(0, 5);
        LinearEquation eq2 = new LinearEquation(3, 0);

        Console.WriteLine($"  Уравнение 1: {eq1}");
        Console.WriteLine($"  Уравнение 2: {eq2}");

        if (EquationSolver.SolveSystem(eq1, eq2, out double x1, out double y1, out string error1))
        {
            Console.WriteLine($"  ✓ Решение: x = {x1}, y = {y1}");
        }
        else
        {
            Console.WriteLine($"  ✗ Ошибка: {error1}");
        }

        // Тест 2: Отрицательные коэффициенты
        Console.WriteLine("\nТест 3.2: Отрицательные коэффициенты");
        LinearEquation eq3 = new LinearEquation(-2, 3);
        LinearEquation eq4 = new LinearEquation(4, -5);

        Console.WriteLine($"  Уравнение 1: {eq3}");
        Console.WriteLine($"  Уравнение 2: {eq4}");

        if (EquationSolver.SolveSystem(eq3, eq4, out double x2, out double y2, out string error2))
        {
            Console.WriteLine($"  ✓ Решение: x = {x2}, y = {y2}");
        }
        else
        {
            Console.WriteLine($"  ✗ Ошибка: {error2}");
        }

        // Тест 3: Большие коэффициенты
        Console.WriteLine("\nТест 3.3: Большие коэффициенты");
        LinearEquation eq5 = new LinearEquation(1000, 2000);
        LinearEquation eq6 = new LinearEquation(3000, 4000);

        Console.WriteLine($"  Уравнение 1: {eq5}");
        Console.WriteLine($"  Уравнение 2: {eq6}");

        if (EquationSolver.SolveSystem(eq5, eq6, out double x3, out double y3, out string error3))
        {
            Console.WriteLine($"  ✓ Решение: x = {x3}, y = {y3}");
        }
        else
        {
            Console.WriteLine($"  ✓ Ошибка (ожидаемо): {error3}");
        }

        // Тест 4: Единичные коэффициенты
        Console.WriteLine("\nТест 3.4: Единичные коэффициенты");
        LinearEquation eq7 = new LinearEquation(1, 1);
        LinearEquation eq8 = new LinearEquation(1, -1);

        Console.WriteLine($"  Уравнение 1: {eq7}");
        Console.WriteLine($"  Уравнение 2: {eq8}");

        if (EquationSolver.SolveSystem(eq7, eq8, out double x4, out double y4, out string error4))
        {
            Console.WriteLine($"  ✓ Решение: x = {x4}, y = {y4}");
        }
        else
        {
            Console.WriteLine($"  ✗ Ошибка: {error4}");
        }
    }
}