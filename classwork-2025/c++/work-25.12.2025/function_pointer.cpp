#include <iostream>

int summ(int a,int b){
    return a + b;
}
int sub(int a,int b){
    return a - b;
}
int sud(int a,int b){
    return a / b;
}
int sus(int a,int b){
    return a * b;
}
int execOper(int a,int b,int (*f)(int,int)){
    return f(a,b);
}

int main(){

    int (*func)(int,int);

    func = summ;

    int a{6};
    int b{10};
    std::cout << func(a,b) << '\n';

    func = sub;
    std::cout << func(a,b) << '\n';

    std::cout << execOper(a,b,sud) << '\n';
    std::cout << execOper(a,b,sus) << '\n';

    return 0;
}
