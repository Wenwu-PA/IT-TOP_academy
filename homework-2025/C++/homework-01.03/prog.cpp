#include <iostream>
#include <cstdlib>
#include <ctime>

// Определяем тип данных: INTEGER, DOUBLE или CHAR

#define INTEGER

#include "function.h"

int main() {
    srand(time(NULL));
    
    const int SIZE = 10;
    
    #ifdef INTEGER
        int arr[SIZE];
    #endif
    
    #ifdef DOUBLE
        double arr[SIZE];
    #endif
    
    #ifdef CHAR
        char arr[SIZE];
    #endif
    
    // Используем обобщенные имена функций
    FillArray(arr, SIZE);
    
    std::cout << "Исходный массив:" << std::endl;
    ShowArray(arr, SIZE);
    
    std::cout << "Минимальный элемент: " << FindMin(arr, SIZE) << std::endl;
    std::cout << "Максимальный элемент: " << FindMax(arr, SIZE) << std::endl;
    
    EditElement(arr, SIZE);
    std::cout << "Массив после редактирования:" << std::endl;
    ShowArray(arr, SIZE);
    
    SortArray(arr, SIZE);
    std::cout << "Массив после сортировки:" << std::endl;
    ShowArray(arr, SIZE);
    
    return 0;
}