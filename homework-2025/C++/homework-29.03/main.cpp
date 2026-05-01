#include <iostream>
#include "Building.h"
#include "Human.h"


int main() {
    Building building(3, 2); // 3 этажа, 2 квартиры на этаже

    Human h1("Иванов Иван Иванович", 30);
    Human h2("Петрова Мария Сергеевна", 25);
    Human h3("Сидоров Алексей Владимирович", 40);

    building.addResidentToApartment(1, 1, h1);
    building.addResidentToApartment(1, 1, h2);
    building.addResidentToApartment(2, 2, h3);

    std::cout << "\n=== Информация о доме ===" << std::endl;
    building.display();

    // Добавление жильца через интерактивный ввод
    std::cout << "\n=== Добавление нового жильца в квартиру 1-2 ===" << std::endl;
    Human h4;
    h4.input();
    building.addResidentToApartment(1, 2, h4);

    std::cout << "\n=== Обновленная информация ===" << std::endl;
    building.display();

    // Тест конструктора копирования
    Building buildingCopy = building;
    std::cout << "\n=== Копия дома (проверка конструктора копирования) ===" << std::endl;
    buildingCopy.display();

    return 0;
}