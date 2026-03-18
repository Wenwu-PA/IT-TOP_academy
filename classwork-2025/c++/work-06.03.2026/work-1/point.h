#pragma once
#include <iostream>
class Point{
    int x;
    int y;
    public:
        Point(): x{0}, y{0}
        {};
        Point(int xP, int yP): x{xP}, y{yP}{}
        ~Point()
        {};
        void print()
        {
            std::cout << x << " " << y;
        };

};