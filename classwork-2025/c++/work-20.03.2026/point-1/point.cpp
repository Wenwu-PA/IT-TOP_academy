#include <iostream>
#include "point.h"
#include <cmath> // для std::sqrt
void Point::display() const
{
    std::cout << x << ", " << y << '\n';
}

void Point::read()
{
    std::cout << "Введите x и y для точки: ";
    std::cin >> x >> y;
}

bool Point::isEqual(const Point& p1, const Point& p2)
{
    return p1.x == p2.x && p1.y == p2.y;
}

bool Point::operator==(const Point& p2)
{
    return x == p2.x && y == p2.y;
}

Point Point::add(const Point& p1, const Point& p2)
{
    return Point{ p1.x + p2.x, p1.y + p2.y };
}

Point Point::operator+(const Point& p2)
{
    return Point{ x + p2.x, y + p2.y };
    //return add(*this, p2);
}

Point Point::mult(const Point& p, double value)
{
    return Point{ p.x * value, p.y * value };
}

double Point::operator%(const Point& p2)
{
    return std::sqrt((x - p2.x) * (y - p2.y));
}

// double Point::distance(const Point& p1, const Point& p2)
// {
//     return std::sqrt((p1.x - p2.x) * (p1.x - p2.x) +
//                      (p1.y - p2.y) * (p1.y - p2.y));
// }

// double Point::length(const Point& p)
// {
//     return std::sqrt(p.x * p.x + p.y * p.y);
// }
double Point::operator!()
{
    return std::sqrt(x * x + y * y);
}