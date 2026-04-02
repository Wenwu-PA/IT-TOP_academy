using System;

/// <summary>
/// Класс для решения систем линейных уравнений
/// </summary>
public static class EquationSolver
{
    /// <summary>
    /// Метод для решения системы двух линейных уравнений:
    /// A1*x + B1*y = 0
    /// A2*x + B2*y = 0
    /// </summary>
    /// <param name="eq1">Первое уравнение</param>
    /// <param name="eq2">Второе уравнение</param>
    /// <param name="x">Выходной параметр для значения x</param>
    /// <param name="y">Выходной параметр для значения y</param>
    /// <param name="errorMessage">Выходной параметр для сообщения об ошибке</param>
    /// <returns>true - решение найдено, false - решение не существует или бесконечно много решений</returns>
    public static bool SolveSystem(LinearEquation eq1, LinearEquation eq2, out double x, out double y, out string errorMessage)
    {
        x = 0;
        y = 0;
        errorMessage = "";

        // Проверяем, что оба уравнения имеют решение (не являются нулевыми)
        if (!eq1.HasSolution() && !eq2.HasSolution())
        {
            errorMessage = "Оба уравнения являются нулевыми (0x + 0y = 0)";
            return false;
        }

        if (!eq1.HasSolution())
        {
            errorMessage = "Первое уравнение является нулевым (0x + 0y = 0)";
            return false;
        }

        if (!eq2.HasSolution())
        {
            errorMessage = "Второе уравнение является нулевым (0x + 0y = 0)";
            return false;
        }

        // Получаем коэффициенты
        int a1 = eq1.A, b1 = eq1.B;
        int a2 = eq2.A, b2 = eq2.B;

        // Вычисляем определитель системы
        double determinant = a1 * b2 - a2 * b1;

        // Проверяем определитель
        if (Math.Abs(determinant) < 1e-10) // Определитель близок к нулю
        {
            // Проверяем, пропорциональны ли уравнения
            if (a1 * b2 == a2 * b1)
            {
                errorMessage = "Система имеет бесконечно много решений (уравнения линейно зависимы)";
            }
            else
            {
                errorMessage = "Система не имеет решений (определитель равен нулю)";
            }
            return false;
        }

        // Решаем систему методом Крамера
        // Так как правые части равны 0, система имеет только тривиальное решение x=0, y=0
        x = 0;
        y = 0;

        errorMessage = "Решение найдено успешно";
        return true;
    }

    /// <summary>
    /// Альтернативный метод для решения системы с ненулевыми правыми частями
    /// Для общего случая: A1*x + B1*y = C1, A2*x + B2*y = C2
    /// </summary>
    public static bool SolveSystemGeneral(LinearEquation eq1, LinearEquation eq2, double c1, double c2,
                                          out double x, out double y, out string errorMessage)
    {
        x = 0;
        y = 0;
        errorMessage = "";

        int a1 = eq1.A, b1 = eq1.B;
        int a2 = eq2.A, b2 = eq2.B;

        double determinant = a1 * b2 - a2 * b1;

        if (Math.Abs(determinant) < 1e-10)
        {
            errorMessage = "Система не имеет единственного решения (определитель равен нулю)";
            return false;
        }

        // Метод Крамера
        x = (c1 * b2 - c2 * b1) / determinant;
        y = (a1 * c2 - a2 * c1) / determinant;

        errorMessage = "Решение найдено успешно";
        return true;
    }
}