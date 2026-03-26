#include <iostream>
#include "point.h"
#include <cmath> // для std::sqrt

void Point::display() const
{
    std::cout << x << ", " << y << '\n';
}

Point operator+(const Point& p1,const Point& p2)
{
    return Point{ p1.x + p2.x, p2.y + p2.y };
}
Point operator-(const Point& p)
{
    return Point{ -p.x, -p.y };
}
Point operator-(const Point& p1,double value)
{
    return Point{ p1.x * value, p1.y * value };
}


