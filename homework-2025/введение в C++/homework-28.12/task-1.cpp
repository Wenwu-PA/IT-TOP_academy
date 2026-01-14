#include <iostream>

// Функция распределения динамической памяти
int* allocateArray(int size) {
    return new int[size];
}

// Функция инициализации динамического массива
void initArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}

// Функция печати динамического массива
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}

// Функция удаления динамического массива
void deleteArray(int* arr) {
    delete[] arr;
}

// Функция добавления элемента в конец массива
int* addToEnd(int* arr, int& size, int value) {
    int* newArr = new int[size + 1];
    
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    
    newArr[size] = value;
    size++;
    
    delete[] arr;
    return newArr;
}

// Функция вставки элемента по указанному индексу
int* insertAtIndex(int* arr, int& size, int index, int value) {
    if (index < 0 || index > size) {
        return arr;
    }
    
    int* newArr = new int[size + 1];
    
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    
    newArr[index] = value;
    
    for (int i = index; i < size; i++) {
        newArr[i + 1] = arr[i];
    }
    
    size++;
    delete[] arr;
    return newArr;
}

// Функция удаления элемента по указанному индексу
int* removeAtIndex(int* arr, int& size, int index) {
    if (index < 0 || index >= size) {
        return arr;
    }
    
    int* newArr = new int[size - 1];
    
    for (int i = 0; i < index; i++) {
        newArr[i] = arr[i];
    }
    
    for (int i = index + 1; i < size; i++) {
        newArr[i - 1] = arr[i];
    }
    
    size--;
    delete[] arr;
    return newArr;
}

int main() {
    int size = 5;
    
    int* arr = allocateArray(size);
    
    initArray(arr, size);
    std::cout << "Инициализированный массив: ";
    printArray(arr, size);
    
    for (int i = 0; i < size; i++) {
        arr[i] =+ 1;
    }
    std::cout << "Заполненный массив: ";
    printArray(arr, size);
    
    arr = addToEnd(arr, size, 6);
    std::cout << "После добавления в конец: ";
    printArray(arr, size);

    arr = insertAtIndex(arr, size, 2, 99);
    std::cout << "После вставки 99 на индекс 2: ";
    printArray(arr, size);

    arr = removeAtIndex(arr, size, 3);
    std::cout << "После удаления элемента с индексом 3: ";
    printArray(arr, size);

    deleteArray(arr);
    
    return 0;
}