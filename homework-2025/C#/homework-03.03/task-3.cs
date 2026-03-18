// Исходный массив
int[] array = { 1, 0, 3, 0, 5, 0, 7, 0, 9 };

Console.WriteLine("Исходный массив:");
Console.WriteLine(string.Join(", ", array));

// Счетчик для позиции вставки не-нулевых элементов
int nonZeroIndex = 0;

// Перемещаем все не-нулевые элементы в начало
for (int i = 0; i < array.Length; i++)
{
    if (array[i] != 0)
    {
        array[nonZeroIndex] = array[i];
        nonZeroIndex++;
    }
}

// Заполняем оставшуюся часть массива значениями -1
for (int i = nonZeroIndex; i < array.Length; i++)
{
    array[i] = -1;
}

Console.WriteLine("Результат:");
Console.WriteLine(string.Join(", ", array));