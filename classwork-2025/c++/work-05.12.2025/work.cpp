#include <iostream>

int main(){

    int x{12};
    int* px{&x};
    //константный указатель
    int* const px2{&x};
    *px2 = 50;

    //указатель на константу
    const int* px3{&x};
    px3 = &x;

    const int* const px4{&x};
    


    return 0;
}