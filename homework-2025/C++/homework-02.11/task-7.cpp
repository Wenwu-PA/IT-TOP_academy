#include <iostream>

int main() {
    int num1 = 0;
    int num2 = 0;
    
    std::cout << "Введите первое число: ";
    std::cin >> num1;
    std::cout << "Введите второе число: ";
    std::cin >> num2;
    
    std::cout << "Общие делители: ";
    for (int i = 1; i <= num1 && i <= num2; i++) {
        if (num1 % i == 0 && num2 % i == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}