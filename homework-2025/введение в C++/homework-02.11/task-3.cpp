#include <iostream>

int main() {
    int number;
    std::cout << "Введите число: ";
    std::cin >> number;
    
    int result = 0;
    int multiplier = 1;
    
    while (number != 0) {
        int digit = number % 10;
        if (digit != 3 && digit != 6) {
            result = result + digit * multiplier;
            multiplier *= 10;
        }
        number = number / 10;
    }
    
    std::cout << "3) " << result << std::endl;
    return 0;
}