#include <iostream>

int main() {
    char str[100];
    int pos;
    char symbol;
    
    std::cout << "Введите строку: ";
    std::cin >> str;
    
    std::cout << "Введите позицию для вставки: ";
    std::cin >> pos;
    
    std::cout << "Введите символ для вставки: ";
    std::cin >> symbol;
    
    int len = 0;
    while (str[len] != '\0') len++;
    
    for (int i = len; i >= pos; i--) {
        str[i + 1] = str[i];
    }
    
    str[pos] = symbol;
    
    std::cout << "Результат: " << str << '\n';
    
    return 0;
}