using System;

/// <summary>
/// Структура для хранения коэффициентов линейного уравнения Ax + By = 0
/// </summary>
public struct LinearEquation
{
    // Коэффициенты уравнения
    public int A { get; set; }
    public int B { get; set; }

    /// <summary>
    /// Конструктор для создания уравнения с заданными коэффициентами
    /// </summary>
    public LinearEquation(int a, int b)
    {
        A = a;
        B = b;
    }

    /// <summary>
    /// Статический метод для парсинга строки с коэффициентами
    /// </summary>
    /// <param name="input">Строка с двумя целыми числами, разделенными пробелом</param>
    /// <returns>Объект LinearEquation с распарсенными коэффициентами</returns>
    /// <exception cref="ArgumentException">Выбрасывается при некорректном формате ввода</exception>
    public static LinearEquation My_Parse(string input)
    {
        if (string.IsNullOrWhiteSpace(input))
        {
            throw new ArgumentException("Строка не может быть пустой или содержать только пробелы");
        }

        // Разделяем строку по пробелам
        string[] parts = input.Trim().Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

        if (parts.Length != 2)
        {
            throw new ArgumentException($"Некорректный формат ввода. Ожидается 2 числа, получено {parts.Length}");
        }

        // Парсим числа
        if (!int.TryParse(parts[0], out int a))
        {
            throw new ArgumentException($"Некорректное значение коэффициента A: '{parts[0]}'");
        }

        if (!int.TryParse(parts[1], out int b))
        {
            throw new ArgumentException($"Некорректное значение коэффициента B: '{parts[1]}'");
        }

        return new LinearEquation(a, b);
    }

    /// <summary>
    /// Переопределение метода ToString для удобного вывода
    /// </summary>
    public override string ToString()
    {
        return $"{A}x + {B}y = 0";
    }

    /// <summary>
    /// Метод для проверки, является ли уравнение нулевым (все коэффициенты равны 0)
    /// </summary>
    public bool IsZero()
    {
        return A == 0 && B == 0;
    }

    /// <summary>
    /// Метод для проверки, имеет ли уравнение решение
    /// </summary>
    public bool HasSolution()
    {
        return !(A == 0 && B == 0);
    }
}