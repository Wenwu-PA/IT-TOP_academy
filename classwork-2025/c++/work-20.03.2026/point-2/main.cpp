#include <iostream>
#include "point.h"

int main()
{
    Point point1{ 1, 1 };
    Point point2{ 1, 1 };
    Point summ{point1+point2};
    summ.display();
    (-summ).display();


    return 0;
}