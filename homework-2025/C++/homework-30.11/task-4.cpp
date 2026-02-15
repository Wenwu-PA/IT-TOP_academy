#include <iostream>
#include <cstdlib>
#include <ctime>

int bubbleSort(int arr[], int size) {
    int swaps = 0;
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return swaps;
}

int selectionSort(int arr[], int size) {
    int swaps = 0;
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            swaps++;
        }
    }
    return swaps;
}

void copyArray(int source[], int dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = source[i];
    }
}

int main() {
    std::srand(std::time(0));
    const int size = 1000;
    const int tests = 10;
    
    int arr1[size];
    int arr2[size];
    
    int totalBubbleSwaps = 0;
    int totalSelectionSwaps = 0;
    
    for (int test = 0; test < tests; test++) {
        for (int i = 0; i < size; i++) {
            arr1[i] = std::rand() % 10000;
        }
        
        copyArray(arr1, arr2, size);
        
        int bubbleSwaps = bubbleSort(arr1, size);
        int selectionSwaps = selectionSort(arr2, size);
        
        totalBubbleSwaps += bubbleSwaps;
        totalSelectionSwaps += selectionSwaps;
        
        std::cout << "Тест " << test + 1 << ": ";
        std::cout << "Пузырьком: " << bubbleSwaps << " перестановок, ";
        std::cout << "Выбором: " << selectionSwaps << " перестановок" << std::endl;
    }
    
    double avgBubble = static_cast<double>(totalBubbleSwaps) / tests;
    double avgSelection = static_cast<double>(totalSelectionSwaps) / tests;
    
    std::cout << "Среднее число перестановок:" << std::endl;
    std::cout << "Пузырьковая сортировка: " << avgBubble << std::endl;
    std::cout << "Сортировка выбором: " << avgSelection << std::endl;
    
    return 0;
}