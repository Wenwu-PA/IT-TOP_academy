#include <iostream>
#include <cstdlib>
#include <ctime>
#include "function.h"

// Реализация функций для целых чисел
void FillArrayInt(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }
}

void ShowArrayInt(int arr[], int size) {
    std::cout << "Массив целых чисел: ";
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int FindMinInt(int arr[], int size) {
    int min = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int FindMaxInt(int arr[], int size) {
    int max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void SortArrayInt(int arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void EditElementInt(int arr[], int size) {
    int index, value;
    std::cout << "Введите индекс элемента для редактирования (0-" << size-1 << "): ";
    std::cin >> index;
    if(index >= 0 && index < size) {
        std::cout << "Введите новое значение: ";
        std::cin >> value;
        arr[index] = value;
        std::cout << "Элемент изменен" << std::endl;
    } else {
        std::cout << "Неверный индекс" << std::endl;
    }
}

// Реализация функций для действительных чисел
void FillArrayDouble(double arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = (rand() % 1000) / 10.0;
    }
}

void ShowArrayDouble(double arr[], int size) {
    std::cout << "Массив действительных чисел: ";
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

double FindMinDouble(double arr[], int size) {
    double min = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

double FindMaxDouble(double arr[], int size) {
    double max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void SortArrayDouble(double arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void EditElementDouble(double arr[], int size) {
    int index;
    double value;
    std::cout << "Введите индекс элемента для редактирования (0-" << size-1 << "): ";
    std::cin >> index;
    if(index >= 0 && index < size) {
        std::cout << "Введите новое значение: ";
        std::cin >> value;
        arr[index] = value;
        std::cout << "Элемент изменен" << std::endl;
    } else {
        std::cout << "Неверный индекс" << std::endl;
    }
}

// Реализация функций для символов
void FillArrayChar(char arr[], int size) {
    for(int i = 0; i < size; i++) {
        arr[i] = 'a' + rand() % 26;
    }
}

void ShowArrayChar(char arr[], int size) {
    std::cout << "Массив символов: ";
    for(int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

char FindMinChar(char arr[], int size) {
    char min = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

char FindMaxChar(char arr[], int size) {
    char max = arr[0];
    for(int i = 1; i < size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

void SortArrayChar(char arr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                char temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void EditElementChar(char arr[], int size) {
    int index;
    char value;
    std::cout << "Введите индекс элемента для редактирования (0-" << size-1 << "): ";
    std::cin >> index;
    if(index >= 0 && index < size) {
        std::cout << "Введите новое значение (символ): ";
        std::cin >> value;
        arr[index] = value;
        std::cout << "Элемент изменен" << std::endl;
    } else {
        std::cout << "Неверный индекс" << std::endl;
    }
}