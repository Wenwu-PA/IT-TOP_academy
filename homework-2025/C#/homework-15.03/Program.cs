using System;
using System.Collections.Generic;

class Student
{
    public string Name { get; set; }
    public string Group { get; set; }
    public Dictionary<string, int> Grades { get; set; }

    public Student(string name, string group)
    {
        Name = name;
        Group = group;
        Grades = new Dictionary<string, int>();
    }

    public void AddGrade(string subject, int grade)
    {
        if (grade >= 2 && grade <= 5)
        {
            Grades[subject] = grade;
        }
        else
        {
            Console.WriteLine("Оценка должна быть от 2 до 5");
        }
    }

    public double GetAverageGrade()
    {
        if (Grades.Count == 0) return 0;

        double sum = 0;
        foreach (var grade in Grades.Values)
        {
            sum += grade;
        }
        return sum / Grades.Count;
    }

    public override string ToString()
    {
        string result = $"Студент: {Name}, Группа: {Group}\nОценки:\n";

        if (Grades.Count == 0)
        {
            result += "  Оценок пока нет";
        }
        else
        {
            foreach (var grade in Grades)
            {
                result += $"  {grade.Key}: {grade.Value}\n";
            }
            result += $"Средний балл: {GetAverageGrade():F2}";
        }

        return result;
    }
}

class Program
{
    static void Main()
    {
        List<Student> students = new List<Student>();

        // Создаем студентов
        Student student1 = new Student("Иван Петров", "ИС-21");
        student1.AddGrade("Математика", 5);
        student1.AddGrade("Физика", 4);
        student1.AddGrade("Программирование", 5);

        Student student2 = new Student("Мария Сидорова", "ИС-21");
        student2.AddGrade("Математика", 4);
        student2.AddGrade("Физика", 5);
        student2.AddGrade("Программирование", 3);

        Student student3 = new Student("Алексей Иванов", "БИ-22");
        student3.AddGrade("Биология", 5);
        student3.AddGrade("Химия", 4);

        students.Add(student1);
        students.Add(student2);
        students.Add(student3);

        // Вывод списка студентов с использованием переопределенного ToString()
        Console.WriteLine("СПИСОК СТУДЕНТОВ:");
        Console.WriteLine("=================");

        foreach (var student in students)
        {
            Console.WriteLine(student);
            Console.WriteLine("-----------------");
        }
    }
}