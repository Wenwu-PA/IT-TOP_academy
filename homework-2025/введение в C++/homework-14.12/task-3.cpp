#include <iostream>
#include <string>

int binaryToDecimalSimple(const std::string& binary) {
    int decimal = 0;
    int power = 1;

    for (int i = binary.length() - 1; i >= 0; i--) {
        char digit = binary[i];
        
        if (digit == '1') {
            decimal += power;
        } else if (digit != '0') {
            std::cout << "Ошибка: недопустимый символ '" << digit << "'" << '\n';
            return -1;
        }
        
        power *= 2;
    }
    
    return decimal;
}

int main() {
    std::string binaryNumber;
    
    std::cout << "Введите двоичное число: ";
    std::cin >> binaryNumber;
    
    int decimal2 = binaryToDecimalSimple(binaryNumber);
    if (decimal2 != -1) {
        std::cout << binaryNumber << " (двоичное) = " << decimal2 << " (десятичное) [простой метод]" << std::endl;
    }
    return 0;
}