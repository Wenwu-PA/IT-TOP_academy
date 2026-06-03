#include <iostream>
#include "Array.h"

struct Point{
    int x;
    int y;

    Point operator+(Point p2){
        return {x + p2.x, y + p2.y};
    }
    friend std::ostream&  operator<<(std::ostream& out, Point p);
};
std::ostream& operator<<(std::ostream& out, Point p){
    out << "(" << p.x << "," << p.y << ")" << "\n";
    return out;
}

bool operator>(Point p1,Point p2){
    return (p1.x + p1.y > p2.x + p2.x);
} 

int main(){


    Array<Point> pointArray;
    pointArray.print();

    const size_t sz{ Array<Point>::getSize()};
    for (size_t i{sz}; i > 0;i--){
        pointArray.setItem(sz - i, Point{(int)i, (int)i});
    }
    pointArray.print();

    pointArray.sort();
    pointArray.print();



    return 0;

}