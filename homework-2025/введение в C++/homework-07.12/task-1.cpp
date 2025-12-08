#include <iostream>

int main() {
    const int MAX_ROWS = 10;
    const int MAX_COLS = 10;
    
    int rows, cols;
    int startValue;
    int arr[MAX_ROWS][MAX_COLS];
    
    std::cout << "Введите количество строк (не более " << MAX_ROWS << "): ";
    std::cin >> rows;
    
    std::cout << "Введите количество столбцов (не более " << MAX_COLS << "): ";
    std::cin >> cols;
    
    std::cout << "Введите начальное число: ";
    std::cin >> startValue;
    
    if (rows > MAX_ROWS || cols > MAX_COLS) {
        std::cout << "Ошибка: размеры превышают максимально допустимые!" << "\n";
        return 1;
    }
    
    int currentValue = startValue;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = currentValue;
            currentValue *= 2;
        }
    }
    
    // Вывод массива на экран
    std::cout << "\nСозданный массив:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << "\n";
    }
    
    return 0;
}