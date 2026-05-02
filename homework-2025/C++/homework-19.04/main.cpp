#include <iostream>
#include "String.h"

int main() {
    std::cout << "=== Демонстрация String (конструктор переноса и перегрузки) ===\n";

    String s1("Hello");
    s1.output();

    // Конструктор переноса
    String s2(std::move(s1));
    std::cout << "\nПосле переноса s1:\n";
    s1.output();   // теперь выведет пустую строку (длина 0)
    std::cout << "s2:\n";
    s2.output();

    // Перегрузка []
    std::cout << "\ns2[1] = " << s2[1] << std::endl;
    s2[0] = 'h';
    std::cout << "После s2[0] = 'h':\n";
    s2.output();

    // Перегрузка ()
    int idx = s2('l');
    std::cout << "\nПозиция 'l' в \"" << s2.c_str() << "\": " << idx << std::endl;
    idx = s2('z');
    std::cout << "Позиция 'z': " << idx << std::endl;

    // Преобразование в int
    int len = static_cast<int>(s2);
    std::cout << "\nДлина строки s2: " << len << std::endl;

    return 0;
}