#include <iostream>

void printArr(int arr[],int len);

int main(){
    const int len{5};

    int arr[len]{1,0,-5,34,6};

    printArr(arr,len);

    return 0;
}

void printArr(int* arr,int len)
{
    for (int i{}; i < len; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
