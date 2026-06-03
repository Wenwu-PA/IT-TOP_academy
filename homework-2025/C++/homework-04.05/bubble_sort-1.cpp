#include <iostream>

// Поиск максимума в массиве
template <typename T>
T maxInArray(const T* arr, size_t size) {
    T maxVal = arr[0];
    for (size_t i = 1; i < size; ++i)
        if (arr[i] > maxVal) maxVal = arr[i];
    return maxVal;
}

// Поиск минимума в массиве
template <typename T>
T minInArray(const T* arr, size_t size) {
    T minVal = arr[0];
    for (size_t i = 1; i < size; ++i)
        if (arr[i] < minVal) minVal = arr[i];
    return minVal;
}

// Пузырьковая сортировка (по возрастанию)
template <typename T>
void bubbleSort(T* arr, size_t size) {
    for (size_t i = 0; i < size - 1; ++i)
        for (size_t j = 0; j < size - i - 1; ++j)
            if (arr[j] > arr[j + 1]) {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}

// Двоичный поиск (массив должен быть отсортирован по возрастанию)
template <typename T>
int binarySearch(const T* arr, size_t size, const T& value) {
    int left = 0, right = static_cast<int>(size) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == value) return mid;
        else if (arr[mid] < value) left = mid + 1;
        else right = mid - 1;
    }
    return -1;  // не найдено
}

// Замена элемента массива по индексу
template <typename T>
void replaceElement(T* arr, size_t index, const T& newValue) {
    arr[index] = newValue;
}

// --- Пример использования ---
int main() {
    int arr[] = {5, 2, 8, 1, 9, 3};
    size_t size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Исходный массив: ";
    for (size_t i = 0; i < size; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;

    std::cout << "Максимум: " << maxInArray(arr, size) << std::endl;
    std::cout << "Минимум: " << minInArray(arr, size) << std::endl;

    bubbleSort(arr, size);
    std::cout << "Отсортированный массив: ";
    for (size_t i = 0; i < size; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;

    int searchVal = 8;
    int pos = binarySearch(arr, size, searchVal);
    if (pos != -1)
        std::cout << "Элемент " << searchVal << " найден на позиции " << pos << std::endl;
    else
        std::cout << "Элемент " << searchVal << " не найден" << std::endl;

    replaceElement(arr, 2, 100);
    std::cout << "После замены arr[2] на 100: ";
    for (size_t i = 0; i < size; ++i) std::cout << arr[i] << " ";
    std::cout << std::endl;

    return 0;
}