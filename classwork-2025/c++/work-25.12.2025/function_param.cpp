#include <iostream>

int sum(int a,int b){
    return a + b;
}

int main(){
    std::cout << sum(5,6) << "\n";

    int (*func)(int,int);
    func = sum;

    std::cout << func(5,6) << '\n'; 

    return 0;
}