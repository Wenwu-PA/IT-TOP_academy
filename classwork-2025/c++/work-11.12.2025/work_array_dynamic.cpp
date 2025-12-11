#include <iostream>

void printArr(int* arr,int len);


int main(){
    const int len{5};
    int arr[len]{32,5,0,-76,3};

    int len2{};
    std::cout << "input len in array2" << '\n';
    std::cin >> len2;
    int* arr2 = new int[len2]{};
    std::cout << "input num in array2" << '\n';
    for (int i{};i <len2;i++){
        std::cin >> arr2[i];
    }
    std::cout << "print array2" << "\n";
    printArr(arr2,len2);
    delete[] arr2;

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
