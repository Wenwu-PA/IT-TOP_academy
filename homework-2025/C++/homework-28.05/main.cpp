#include <iostream>
#include "Dog.h"
#include "Cat.h"
#include "Parrot.h"
#include "BitString.h"

int main() {
    // Задание 1: животные
    std::cout << "=== Домашние животные ===\n";
    Dog dog("Шарик");
    Cat cat("Мурка");
    Parrot parrot("Кеша");
    dog.display();
    cat.display();
    parrot.display();

    // Задание 2: строки
    std::cout << "\n=== Строки ===\n";
    String s1("Hello");
    String s2("World");
    String s3 = s1 + s2;
    std::cout << "s1+s2 = " << s3.c_str() << std::endl;
    s1 += "!";
    std::cout << "s1 += ! -> " << s1.c_str() << std::endl;
    String s4("Hello");
    std::cout << "s1 == s4? " << (s1 == s4 ? "Да" : "Нет") << std::endl;

    // Битовая строка
    std::cout << "\n=== Битовые строки ===\n";
    BitString b1("1010");   // +10 (если 4 бита, то 1010 = -6? но мы используем знаковый разряд)
    BitString b2("0101");   // +5
    std::cout << "b1 = " << b1.c_str() << " (int: " << b1.toInt() << ")\n";
    std::cout << "b2 = " << b2.c_str() << " (int: " << b2.toInt() << ")\n";
    BitString b3 = b1 + b2;
    std::cout << "b1 + b2 = " << b3.c_str() << " (int: " << b3.toInt() << ")\n";

    b1.changeSign();
    std::cout << "Изменение знака b1 -> " << b1.c_str() << " (int: " << b1.toInt() << ")\n";

    BitString b4("101010"); // недопустимые символы
    std::cout << "b4 (недопустимые) = " << b4.c_str() << " (пусто? " << (b4.size() == 0 ? "да" : "нет") << ")\n";

    return 0;
}