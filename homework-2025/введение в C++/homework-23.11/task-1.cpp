#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(std::time(0));
    
    int source[10];
    int dest1[5];
    int dest2[5];
    
    std::cout << "Исходный массив: ";
    for (int i = 0; i < 10; i++) {
        source[i] = std::rand() % 100;
        std::cout << source[i] << " ";
    }
    std::cout << std::endl;
    
    for (int i = 0; i < 5; i++) {
        dest1[i] = source[i];
    }
    
    for (int i = 0; i < 5; i++) {
        dest2[i] = source[i + 5];
    }
    
    std::cout << "Первый массив: ";
    for (int i = 0; i < 5; i++) {
        std::cout << dest1[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Второй массив: ";
    for (int i = 0; i < 5; i++) {
        std::cout << dest2[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}