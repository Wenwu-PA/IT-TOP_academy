#include <iostream>
#include "Point.h"

int main(){
    Point point_test{2,5};
    Point point_test2{5,6};
    point_test2.print();
    std::cout << &(point_test2.PI) << '\n';
    std::cout << &(point_test2.x) << '\n';
    return 0;
}