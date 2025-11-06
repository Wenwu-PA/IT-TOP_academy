#include <iostream>

int sum(int a, int b){

    int c{a + b};

    return c;
}

int divv(int a, int b){

    int c{a - b};

    return c;
}

int multip(int a, int b){

    int c{a * b};

    return c;
}
int  division(int a, int b){

    int c{a / b};

    return c;
}


void swap(int& a,int& b){
    int c{a};
    a = b;
    b = c;
    
}

void main(){
    int a{};
    int b{};

    std::cout << "input a and b - ";
    std::cin >> a >> b;
    swap(a,b);

    std::cout << "swap a and b - " << a << " " << b << "\n";
    std::cout << "summ a and b - " << sum(a,b) << "\n";
    std::cout << "div a and b - " << divv(a,b) << "\n";
    std::cout << "multiplication a and b - " << multip(a,b) << "\n";
    std::cout << "division a and b - " << division(a,b) << "\n";
}
