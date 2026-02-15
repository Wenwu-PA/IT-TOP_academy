#include <iostream>

int binarySearch(int arr[], int size, int key) {
    int left = 0;
    int right = size - 1;
    
    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        if (key < arr[mid]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    
    return -1;
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 45, 56, 67};
    int size = 10;
    
    int key = 23;
    std::cout << "\nИщем число " << key << std::endl;
    
    int result = binarySearch(arr, size, key);
    
    result = binarySearch(arr, size, key);
    
    if (result != -1) {
        std::cout << "Число " << key << " найдено на позиции " << result << std::endl;
    } else {
        std::cout << "Число " << key << " не найдено" << std::endl;
    }
    
    return 0;
}