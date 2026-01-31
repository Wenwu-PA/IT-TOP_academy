#include <iostream>

int main() {
    char str[100];
    char symbol;
    
    std::cout << "Введите строку: ";
    std::cin >> str;
    
    std::cout << "Введите символ для удаления: ";
    std::cin >> symbol;
    
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != symbol) {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
    
    std::cout << "Результат: " << str << '\n';
    
    return 0;
}