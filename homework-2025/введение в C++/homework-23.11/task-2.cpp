#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    
    const int size = 5;
    int arr1[size];
    int arr2[size];
    int result[size];
    
    std::cout << "Первый массив: ";
    for (int i = 0; i < size; i++) {
        arr1[i] = std::rand() % 100;
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Второй массив: ";
    for (int i = 0; i < size; i++) {
        arr2[i] = std::rand() % 100;
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Результирующий массив: ";
    for (int i = 0; i < size; i++) {
        result[i] = arr1[i] + arr2[i];
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}