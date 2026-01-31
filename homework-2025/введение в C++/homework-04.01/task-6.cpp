#include <iostream>

int main() {
    char str[100];
    
    std::cout << "Введите строку: ";
    std::cin >> str;
    
    int letters = 0;
    int digits = 0;
    int others = 0;
    
    for (int i = 0; str[i] != '\0'; i++) {
        int code = str[i];
        if (code >= 48 && code <= 57) {
            digits++;
        }
        else if (code >= 65 && code <= 90) {
            letters++;
        }
        else if (code >= 97 && code <= 122) {
            letters++;
        }
        else {
            others++;
        }
    }
    
    std::cout << "Букв: " << letters << '\n';
    std::cout << "Цифр: " << digits << '\n';
    std::cout << "Других символов: " << others << '\n';
    
    return 0;
}