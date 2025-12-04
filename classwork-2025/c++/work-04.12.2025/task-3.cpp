#include <iostream>

void printArr(int arr[],int len);
void swap(int* x, int* y);
void swap2(int &x, int &y);

int main(){
    const int len{5};

    int arr[len]{1,0,-5,34,6};
    //printArr(arr,len);

    int a{5};
    int b{8};

    std::cout << a << " " << b << "\n";
    swap (&a,&b);
    std::cout << "swap 1 - " << a << " " << b << "\n";
    swap2 (a,b);
    std::cout << "swap 2 - " << a << " " << b << "\n";

    


    return 0;
}

void swap(int* x,int* y){
    int t{*x};
    *x = *y;
    *y = t;

}
void swap2(int &x,int &y){
    int t{x};
    x = y;
    y = t;

}

void printArr(int* arr,int len)
{
    for (int i{}; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
