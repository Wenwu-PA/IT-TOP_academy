#include <iostream>
#include "point.h"

int main(){
    Point p0;
    Point p1{13,56};
    p0.setX(10);
    p0.setY(20);

    p0.show();
    p1.show();
    return 0;
}