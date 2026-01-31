#include <iostream>

int main() {
    char str[100];
    char symbol;
    
    std::cout << "Введите строку: ";
    std::cin >> str;
    
    std::cout << "Введите искомый символ: ";
    std::cin >> symbol;
    
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == symbol) {
            count++;
        }
    }
    
    std::cout << "Символ '" << symbol << "' встречается " << count << " раз\n";
    
    return 0;
}