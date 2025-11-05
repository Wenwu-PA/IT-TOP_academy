#include <iostream>

int main() {
    int number;
    std::cout << "Введите число: ";
    std::cin >> number;
    
    std::cout << "Делители: ";
    for (int i = 1; i <= number; i++) {
        if (number % i == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}