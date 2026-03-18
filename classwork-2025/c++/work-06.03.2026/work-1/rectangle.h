#pragma once
#include "point.h"

class Rectangle{
    Point x;
    int with;
    int height;
public:
    Rectangle(): x{0,0}, with{20}, height{20}
    {};
    Rectangle(int xP,int yP, int withP, int heightP): x{xP,yP}, with{withP}, height{heightP}
    {};
    
    void print(){
        x.print();
        std::cout << " " << with << ' ' << height;
        std::cout << "\n";

    }
};