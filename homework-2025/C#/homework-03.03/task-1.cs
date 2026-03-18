string text = "Вчера мама купила торт";
string wordToFind = "торт";
string wordToInsert = "большой";

// Находим позицию слова "торт"
int index = text.IndexOf(wordToFind);

if (index != -1)
{
    // Вставляем слово перед найденным словом
    string result = text.Insert(index, wordToInsert + " ");
    Console.WriteLine(result);
}
else
{
    Console.WriteLine("Слово не найдено");
}