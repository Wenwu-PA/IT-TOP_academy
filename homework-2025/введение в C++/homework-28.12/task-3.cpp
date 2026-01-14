#include <iostream>

void separateArray(int arr[], int size, 
                   int*& posArr, int& posCount,
                   int*& negArr, int& negCount,
                   int*& zeroArr, int& zeroCount) {
    
    posCount = 0;
    negCount = 0;
    zeroCount = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) posCount++;
        else if (arr[i] < 0) negCount++;
        else zeroCount++;
    }
    
    posArr = new int[posCount];
    negArr = new int[negCount];
    zeroArr = new int[zeroCount];
    
    int posIndex = 0;
    int negIndex = 0;
    int zeroIndex = 0;
    
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            posArr[posIndex] = arr[i];
            posIndex++;
        }
        else if (arr[i] < 0) {
            negArr[negIndex] = arr[i];
            negIndex++;
        }
        else {
            zeroArr[zeroIndex] = arr[i];
            zeroIndex++;
        }
    }
}

int main() {
    const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size;
    
    std::cout << "Введите размер массива: ";
    std::cin >> size;
    
    if (size > MAX_SIZE) size = MAX_SIZE;
    
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
    
    int* posArr = nullptr;
    int* negArr = nullptr;
    int* zeroArr = nullptr;
    int posCount, negCount, zeroCount;
    
    separateArray(arr, size, posArr, posCount, negArr, negCount, zeroArr, zeroCount);
    
    std::cout << "Положительные (" << posCount << "): ";
    for (int i = 0; i < posCount; i++) {
        std::cout << posArr[i] << " ";
    }
    std::cout << '\n';
    
    std::cout << "Отрицательные (" << negCount << "): ";
    for (int i = 0; i < negCount; i++) {
        std::cout << negArr[i] << " ";
    }
    std::cout << '\n';
    
    std::cout << "Нули (" << zeroCount << "): ";
    for (int i = 0; i < zeroCount; i++) {
        std::cout << zeroArr[i] << " ";
    }
    std::cout << '\n';
    
    delete[] posArr;
    delete[] negArr;
    delete[] zeroArr;
    
    return 0;
}