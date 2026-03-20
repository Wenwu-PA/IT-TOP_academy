#include <iostream>

int summ(int a,int x){
    return a + x;
}
void outputNumbers(int lim){
    for(int i{1}; i <= lim;i++){
        std::cout << i << " ";
    }
    std::cout << " ";
}