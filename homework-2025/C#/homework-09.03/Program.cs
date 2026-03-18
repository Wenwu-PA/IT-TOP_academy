using System;

public class MyClass
{
    public int Number;
    public string Name;
    public bool IsStudent;
    public MyClass()
    {
        Number = 0;
        Name = "Не указано";
        IsStudent = false;
    }
    public MyClass(int number)
    {
        Number = number;
        Name = "Не указано";
        IsStudent = false;
    }
    public MyClass(int number, string name)
    {
        Number = number;
        Name = name;
        IsStudent = false;
    }

    public MyClass(int number, string name, bool isStudent)
    {
        Number = number;
        Name = name;
        IsStudent = isStudent;
    }
    public void PrintInfo()
    {
        Console.WriteLine($"Номер: {Number}");
        Console.WriteLine($"Имя: {Name}");
        Console.WriteLine($"Студент: {(IsStudent ? "Да" : "Нет")}");
    }
}

class Program
{
    static void Main(string[] args)
    {
        Console.WriteLine("Создание экземпляров класса разными конструкторами:\n");
        MyClass obj1 = new MyClass();
        Console.WriteLine("Объект 1 (конструктор по умолчанию):");
        obj1.PrintInfo();
        MyClass obj2 = new MyClass(1001);
        Console.WriteLine("Объект 2 (конструктор с параметром Number):");
        obj2.PrintInfo();
        MyClass obj3 = new MyClass(1002, "Иван Петров");
        Console.WriteLine("Объект 3 (конструктор с параметрами Number и Name):");
        obj3.PrintInfo();
        MyClass obj4 = new MyClass(1003, "Мария Сидорова", true);
        Console.WriteLine("Объект 4 (конструктор со всеми параметрами):");
        obj4.PrintInfo();

        Console.ReadKey();
    }
}