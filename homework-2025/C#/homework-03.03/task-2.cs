string animals = "dog, cat, elephant, tiger, bear, zebra";
string wordToFind = "elephant";
string wordToInsert = "rabbit";

// Находим позицию слова "elephant"
int index = animals.IndexOf(wordToFind);

if (index != -1)
{
    // Вставляем слово после найденного слова
    // + длина слова, чтобы вставить после него
    int insertPosition = index + wordToFind.Length;
    string result = animals.Insert(insertPosition, ", " + wordToInsert);
    Console.WriteLine(result);
}
else
{
    Console.WriteLine("Слово не найдено");
}