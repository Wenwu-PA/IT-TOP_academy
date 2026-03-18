#include <iostream>
#include "point.h"
#include "rectangle.h"

int main(){
    Point point_default;
    Point point{5,20};

    Rectangle rec{5,5,200,100};
    std::cout << "Rectangle pointers: ";
    rec.print();

    std::cout << "Point on source: ";
    point_default.print();

    std::cout << "\n";

    std::cout << "Point in default: ";
    point.print();

    return 0;
}