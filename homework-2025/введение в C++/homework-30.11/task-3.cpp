#include <iostream>

void flipStack(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

int findMaxIndex(int arr[], int n) {
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void pancakeSort(int arr[], int size) {
    for (int currSize = size; currSize > 1; currSize--) {
        int maxIndex = findMaxIndex(arr, currSize);
        
        if (maxIndex != currSize - 1) {
            if (maxIndex != 0) {
                flipStack(arr, maxIndex + 1);
            }
            flipStack(arr, currSize);
        }
    }
}

int main() {
    int size;
    std::cout << "Введите количество оладий: ";
    std::cin >> size;
    
    int pancakes[size];
    std::cout << "Введите радиусы оладий: ";
    for (int i = 0; i < size; i++) {
        std::cin >> pancakes[i];
    }
    
    std::cout << "Исходная стопка: ";
    for (int i = 0; i < size; i++) {
        std::cout << pancakes[i] << " ";
    }
    std::cout << std::endl;
    
    pancakeSort(pancakes, size);
    
    std::cout << "Отсортированная стопка: ";
    for (int i = 0; i < size; i++) {
        std::cout << pancakes[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}