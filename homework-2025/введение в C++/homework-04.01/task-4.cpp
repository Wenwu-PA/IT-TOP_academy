#include <iostream>

int main() {
    char str[100];
    
    std::cout << "Введите строку: ";
    std::cin >> str;
    
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.') {
            str[i] = '!';
        }
    }
    
    std::cout << "Результат: " << str << '\n';
    
    return 0;
}