#include <iostream>

int main() {
    int cellSize;
    std::cout << "Введите размер клетки: ";
    std::cin >> cellSize;
    
    for (int row = 0; row < 8; row++) {
        for (int i = 0; i < cellSize; i++) {
            for (int col = 0; col < 8; col++) {
                char symbol = ((row + col) % 2 == 0) ? '#' : ' ';
                for (int j = 0; j < cellSize; j++) {
                    std::cout << symbol;
                }
            }
            std::cout << std::endl;
        }
    }
    
    return 0;
}