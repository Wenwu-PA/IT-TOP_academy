#include <iostream>
void printArr(int* arr,int len);

int main(){
    const int len{10000};
    int arr[len]{};
    int len_user{};

    std::cout << "input len in array" << '\n';
    std::cin >> len_user;
    std::cout << "input num in array" << '\n';
    for (int i{};i <len_user;i++){
        std::cin >> arr[i];
    }
    std::cout << "print array" << "\n";
    printArr(arr,len_user);
    delete[] arr;

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