#include <iostream>

int main (){
    int x{ 150 };


    //указатель =  pointer (px)
    int* px{ &x };

    std::cout << "test pointer in x " << px << "\n";
    std::cout << "test pointer in x " << *px << "\n";

    *px = 20;
    std::cout << x << "\n";



    return 0;
}