#include <iostream>
#include "Date.h"

int main() {
    std::cout << "=== Демонстрация класса Date ===\n";
    Date d1(28, 2, 2020);
    Date d2(1, 3, 2020);
    std::cout << "d1 = " << d1 << std::endl;
    std::cout << "d2 = " << d2 << std::endl;

    std::cout << "\nПрефиксный ++d1: " << ++d1 << std::endl;
    std::cout << "d1 теперь: " << d1 << std::endl;

    std::cout << "\nПостфиксный d2--: " << d2-- << std::endl;
    std::cout << "d2 теперь: " << d2 << std::endl;

    std::cout << "\nd1 == d2? " << (d1 == d2 ? "да" : "нет") << std::endl;
    std::cout << "d1 < d2?  " << (d1 < d2  ? "да" : "нет") << std::endl;

    std::cout << "\nНомер дня в году для " << d1 << " = " << d1() << std::endl;

    d1 += 5;
    std::cout << "d1 += 5 => " << d1 << std::endl;
    d1 -= 3;
    std::cout << "d1 -= 3 => " << d1 << std::endl;

    Date d3;
    std::cout << "\nВведите дату в формате ДД.ММ.ГГГГ: ";
    std::cin >> d3;
    std::cout << "Вы ввели: " << d3 << std::endl;

    Date d4 = d1;
    std::cout << "\nd4 (копия d1): " << d4 << std::endl;
    std::cout << "d4++: " << d4++ << " -> после: " << d4 << std::endl;
    std::cout << "--d4: " << --d4 << std::endl;

    return 0;
}