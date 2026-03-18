#include "String.h"
#include <iostream>

int main() {
    std::cout << "Количество объектов: " << String::getObjectCount() << '\n';

    String s1;
    std::cout << "\nСоздана строка s1 (по умолчанию 80 символов)" << '\n';
    std::cout << "Количество объектов: " << String::getObjectCount() << '\n';

    String s2(50);
    std::cout << "\nСоздана строка s2 (50 символов)" << '\n';
    std::cout << "Количество объектов: " << String::getObjectCount() << '\n';

    String s3("Привет, мир!");
    std::cout << "\nСоздана строка s3 с инициализацией" << '\n';
    s3.output();
    std::cout << "Количество объектов: " << String::getObjectCount() << '\n';

    std::cout << "\n=== Ввод строки с клавиатуры ===" << '\n';
    s1.input();
    s1.output();

    String s4 = s3;
    std::cout << "\nСоздана копия s3 (s4)" << '\n';
    s4.output();
    std::cout << "Количество объектов: " << String::getObjectCount() << '\n';

    return 0;
}