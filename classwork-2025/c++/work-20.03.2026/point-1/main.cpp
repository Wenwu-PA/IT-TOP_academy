#include <iostream>
#include "point.h"

int main()
{
    Point point1{ 1, 1 };
    Point point2;
    Point point3{ 1, 1 };

    // тест сравнения точек
    if (point1 == point3)
    {
        std::cout << "Точка point1 равна точке point3\n";
    }

    // тест вывода точки
    std::cout << "point1: ";
    point1.display();
    //std::cout << "point1: " << point1;

    // тест получения координат от пользователя
    point2.read();
    std::cout << "point2: ";
    point2.display();
    // std::cin >> point2;

    // тест сложения двух точек
    std::cout << "point2 + point1 = ";
    Point::add(point2, point1).display();
    std::cout << "point2 + point1 = ";
    (point1 + point2).display();

    // тест определения расстояния между двумя точками
    std::cout << "Расстояние между ";
    point1.display();
    std::cout << " и ";
    point2.display();
    // std::cout << " равно " << Point::distance(point1, point2) << "\n";
    std::cout << " равно " << point1 % point2 << "\n";

    std::cout << "length point 1: ";
    std::cout << !point1 << '\n';
    std::cout << "length point 2: ";
    std::cout << !point2 << '\n';

    return 0;
}