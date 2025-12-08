#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    const int ROWS = 3;
    const int COLS = 4;
    
    int arr[ROWS][COLS];
    int temp[ROWS][COLS];
    
    std::srand(std::time(0));
    
    std::cout << "Исходный массив:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            arr[i][j] = std::rand() % 10;
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    
    int shiftCount;
    int direction;
    
    std::cout << "\nВведите количество сдвигов: ";
    std::cin >> shiftCount;
    
    std::cout << "Выберите направление сдвига:\n";
    std::cout << "1 - Влево\n";
    std::cout << "2 - Вправо\n";
    std::cout << "3 - Вверх\n";
    std::cout << "4 - Вниз\n";
    std::cout << "Ваш выбор: ";
    std::cin >> direction;
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            temp[i][j] = arr[i][j];
        }
    }
    
    switch (direction) {
        case 1:
            for (int s = 0; s < shiftCount; s++) {
                for (int i = 0; i < ROWS; i++) {
                    int first = temp[i][0];
                    for (int j = 0; j < COLS - 1; j++) {
                        temp[i][j] = temp[i][j + 1];
                    }
                    temp[i][COLS - 1] = first;
                }
            }
            break;
            
        case 2:
            for (int s = 0; s < shiftCount; s++) {
                for (int i = 0; i < ROWS; i++) {
                    int last = temp[i][COLS - 1];
                    for (int j = COLS - 1; j > 0; j--) {
                        temp[i][j] = temp[i][j - 1];
                    }
                    temp[i][0] = last;
                }
            }
            break;
            
        case 3:
            for (int s = 0; s < shiftCount; s++) {
                int firstRow[COLS];
                for (int j = 0; j < COLS; j++) {
                    firstRow[j] = temp[0][j];
                }
                for (int i = 0; i < ROWS - 1; i++) {
                    for (int j = 0; j < COLS; j++) {
                        temp[i][j] = temp[i + 1][j];
                    }
                }
                for (int j = 0; j < COLS; j++) {
                    temp[ROWS - 1][j] = firstRow[j];
                }
            }
            break;
            
        case 4:
            for (int s = 0; s < shiftCount; s++) {
                int lastRow[COLS];
                for (int j = 0; j < COLS; j++) {
                    lastRow[j] = temp[ROWS - 1][j];
                }
                for (int i = ROWS - 1; i > 0; i--) {
                    for (int j = 0; j < COLS; j++) {
                        temp[i][j] = temp[i - 1][j];
                    }
                }
                for (int j = 0; j < COLS; j++) {
                    temp[0][j] = lastRow[j];
                }
            }
            break;
            
        default:
            std::cout << "Ошибка: неверный выбор направления!" << std::endl;
            return 1;
    }
    
    std::cout << "\nМассив после сдвига:\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            std::cout << temp[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    
    return 0;
}