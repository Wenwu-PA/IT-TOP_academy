#include <iostream>

bool isPrime(int n) {
    if (n < 2) return false;
    else if (n == 2) return true;
    else if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int* removePrimes(int* arr, int size, int& newSize) {
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            count++;
        }
    }
    
    newSize = count;
    int* newArr = new int[newSize];
    
    int j = 0;
    for (int i = 0; i < size; i++) {
        if (!isPrime(arr[i])) {
            newArr[j] = arr[i];
            j++;
        }
    }
    
    return newArr;
}

int main() {
    int size;
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    
    int* arr = new int[size];
    
    std::cout << "Введите элементы массива:\n";
    for (int i = 0; i < size; i++) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
    
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
    
    int newSize;
    int* result = removePrimes(arr, size, newSize);
    
    std::cout << "Массив без простых чисел: ";
    for (int i = 0; i < newSize; i++) {
        std::cout << result[i] << " ";
    }
    std::cout << '\n';
    
    delete[] arr;
    delete[] result;
    
    return 0;
}