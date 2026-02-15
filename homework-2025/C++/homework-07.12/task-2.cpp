#include <iostream>

int main() {
    const int ROWS = 3;
    const int COLS = 4;
    
    int startValue;
    int arr[ROWS][COLS];
    
    std::cout << "Введите начальное число: ";
    std::cin >> startValue;
    
    int currentValue = startValue;
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = currentValue;
            currentValue += 1;
        }
    }
    
    std::cout << "\nСозданный массив (" << ROWS << "x" << COLS << "):\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << '\n';
    }
    
    return 0;
}