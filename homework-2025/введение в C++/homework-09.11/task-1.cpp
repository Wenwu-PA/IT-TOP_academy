#include <iostream>

int main() {
    int number = 0;
    int choice = 0;
    
    std::cout << "Введите число: ";
    std::cin >> number;
    
    do {
        std::cout << "\n=== МЕНЮ ===\n";
        std::cout << "1 - Количество цифр в числе\n";
        std::cout << "2 - Сумма цифр\n";
        std::cout << "3 - Среднее арифметическое цифр\n";
        std::cout << "4 - Количество нулей в числе\n";
        std::cout << "0 - Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        
        int temp = number;
        int digitCount = 0;
        int digitSum = 0;
        int zeroCount = 0;
        
        while (temp != 0) {
            int digit = temp % 10;
            digitCount++;
            digitSum += digit;
            if (digit == 0) {
                zeroCount++;
            }
            temp = temp / 10;
        }
        
        switch (choice) {
            case 1:
                std::cout << "Количество цифр: " << digitCount << std::endl;
                break;
            case 2:
                std::cout << "Сумма цифр: " << digitSum << std::endl;
                break;
            case 3:
                if (digitCount > 0) {
                    double average = static_cast<double>(digitSum) / digitCount;
                    std::cout << "Среднее арифметическое: " << average << std::endl;
                } else {
                    std::cout << "Число не содержит цифр" << std::endl;
                }
                break;
            case 4:
                std::cout << "Количество нулей: " << zeroCount << std::endl;
                break;
            case 0:
                std::cout << "Выход..." << std::endl;
                break;
            default:
                std::cout << "Неверный выбор!" << std::endl;
        }
    } while (choice != 0);
    
    return 0;
}