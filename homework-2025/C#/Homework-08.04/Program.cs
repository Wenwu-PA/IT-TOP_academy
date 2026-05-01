using System;

// Интерфейсы
interface ISquare
{
    double GetSquare();
}

interface IPerimetr
{
    double GetPerimetr();
}

// Абстрактный класс
abstract class Shape
{
    public abstract string Name { get; }
}

// Квадрат
class Square : Shape, ISquare, IPerimetr
{
    private double side;

    public Square(double side)
    {
        this.side = side;
    }

    public override string Name => "Квадрат";

    public double GetSquare()
    {
        return side * side;
    }

    public double GetPerimetr()
    {
        return 4 * side;
    }

    public double Side => side;
}

// Круг
class Circle : Shape, ISquare, IPerimetr
{
    private double radius;

    public Circle(double radius)
    {
        this.radius = radius;
    }

    public override string Name => "Круг";

    public double GetSquare()
    {
        return Math.PI * radius * radius;
    }

    public double GetPerimetr()
    {
        return 2 * Math.PI * radius;
    }

    public double Radius => radius;
}

// Треугольник
class Triangle : Shape, ISquare, IPerimetr
{
    private double a, b, c;

    public Triangle(double a, double b, double c)
    {
        // Проверка существования треугольника
        if (a + b <= c || a + c <= b || b + c <= a)
            throw new ArgumentException("Треугольник с такими сторонами не существует");

        this.a = a;
        this.b = b;
        this.c = c;
    }

    public override string Name => "Треугольник";

    public double GetSquare()
    {
        double p = (a + b + c) / 2;
        return Math.Sqrt(p * (p - a) * (p - b) * (p - c));
    }

    public double GetPerimetr()
    {
        return a + b + c;
    }

    public double A => a;
    public double B => b;
    public double C => c;
}

class Program
{
    static void Main()
    {
        // Создание экземпляров
        Square square = new Square(5);
        Circle circle = new Circle(3);
        Triangle triangle = new Triangle(3, 4, 5); // валидный треугольник

        // Вывод информации о квадрате
        Console.WriteLine($"{square.Name}: сторона = {square.Side}, площадь = {square.GetSquare()}, периметр = {square.GetPerimetr()}");

        // Вывод информации о круге
        Console.WriteLine($"{circle.Name}: радиус = {circle.Radius}, площадь = {circle.GetSquare()}, периметр = {circle.GetPerimetr()}");

        // Вывод информации о треугольнике
        Console.WriteLine($"{triangle.Name}: стороны = {triangle.A}, {triangle.B}, {triangle.C}, площадь = {triangle.GetSquare()}, периметр = {triangle.GetPerimetr()}");
    }
}