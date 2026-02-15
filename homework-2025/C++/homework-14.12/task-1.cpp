#include <iostream>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    const int SIZE = 10;
    int arr[SIZE];
    std::cout << "Введите " << SIZE << " чисел:\n";
    for (int i = 0; i < SIZE; i++) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
    }
    std::cout << "\nВаш массив: ";
    for (int i = 0; i < SIZE; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
    int key;
    std::cout << "\nКакое число ищем? ";
    std::cin >> key;
    
    int result = linearSearch(arr, SIZE, key);
    
    if (result != -1) {
        std::cout << "Число " << key << " найдено на позиции " << result << std::endl;
    } else {
        std::cout << "Число " << key << " не найдено в массиве" << std::endl;
    }
    
    return 0;
}