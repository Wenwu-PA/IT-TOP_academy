#include <iostream>
#include "point.h"
#include "Fraction.h"

int main(){
    // Point p1{2,5};
    // Point p2{0,5};
    // Point p3{5,5};
    // if ((bool)p1){p1.show();};
    // if ((bool)p2){p2.show();};
    // if ((bool)p3){p3.show();};

    // const int pointsCount{3};
    // Point points[pointsCount]{ {0,0}, {26,1}, {0,25}};

    // bool isZero{false};

    // for(Point* point{points}, *pointsEnd{points + pointsCount};
    //     point != pointsEnd; point++ ){
    //     isZero = *point;
    //     if(isZero){
    //         std::cout<< "Zero point detected" << "\n";
    //     }
    //     else{
    //         point->show();
    //     }
    // }

    // Point p{26,7};
    // Point pconv{};
    
    // Point3D p3d{5,-8,54};
    // Point3D p3dConv{};

    // pconv = (Point)p3d;
    // p3dConv = (Point3D)p;

    // pconv.show();
    

    Fraction f2{2,3};
    Fraction f1{1,2};

    Fraction sum{};
    sum = f1 + f2;
    
    sum.print();

    return 0;

}