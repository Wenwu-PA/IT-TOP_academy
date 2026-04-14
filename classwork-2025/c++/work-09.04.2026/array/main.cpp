#include <iostream>
#include "array.h"

int main(){
    Array arr1{arrayFactory(10)};
    std::cout << arr1 << "\n";

    Array arr2{arr1};
    std::cout << arr2 << '\n';

    return 0;
    
};
