#include <iostream>
#include "Array.h"

int main(){
    Array arr1{10};
    Array arr2;

    for (int i{}; i < arr1.len();i++){
        arr1[i] = i;
    }
    for (int i{}; i < arr2.len();i++){
        arr2[i] = i + 10;

    }

    std::cout << "Size array 1: " << arr1 << '\n';
    std::cout << "Size array 2: " << arr2 << '\n';

    if (arr1 == arr2){
        std::cout << "Array 1 and 2 not equal" << '\n';
    }
    else{
        std::cout << "Array 1 and 2 equal" << '\n';
    }

    Array arr3 {arr1};
    std::cout << "Size array: 3" << arr3.len()<< '\n';
    std::cout << "Array 3: " << arr3 << "\n";



    return 0;
}