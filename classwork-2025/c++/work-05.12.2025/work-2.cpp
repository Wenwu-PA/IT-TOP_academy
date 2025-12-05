#include <iostream>

int& sum(int a,int b){
    int res{a+b};
    int& resref{res};

    return resref;
}

int& rf(int index);
const int rows{10};
const int colms{2};
int a[rows][colms];

void swap(int* a,int* b){
    int temp{*a};
    *a = *b;
    *b = temp;
}

void swap_ref(int& a,int& b){
    int temp{a};
    a = b;
    b = temp;
}

int main(){

    int b(26);
    int x{15};
    int& xref{x};

    for (int i{};i<rows;i++){
        std::cout << "Input " << i << '\n';
        int b{};
        std::cin >> b;
        a[i][0] = b;
        rf(i) = b;
    }
    for (int i{};i<rows;i++){
        std::cout << a[i][0] << "\t" << rf(i) << '\n';
    }

    std::cout << "not swap: "<< x << b <<"\n";

    swap(&x,&b);

    std::cout << "swap: "<< x << b <<"\n";

    swap_ref(x,b);

    std::cout << "swap: "<< x << b <<"\n";

    std::cout << "summ = " << sum(8,12);

    return 0;
}

int& rf(int index){


    return a[index][1];
}