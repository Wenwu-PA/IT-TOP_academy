#include <iostream>
#include <string>

void sortMobile(std::string mobiles[], std::string homes[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (mobiles[j] > mobiles[j + 1]) {
                std::string temp_mobile = mobiles[j];
                std::string temp_home = homes[j];
                mobiles[j] = mobiles[j + 1];
                homes[j] = homes[j + 1];
                mobiles[j + 1] = temp_mobile;
                homes[j + 1] = temp_home;
            }
        }
    }
}

void sortHome(std::string mobiles[], std::string homes[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (homes[j] > homes[j + 1]) {
                std::string temp_mobile = mobiles[j];
                std::string temp_home = homes[j];
                mobiles[j] = mobiles[j + 1];
                homes[j] = homes[j + 1];
                mobiles[j + 1] = temp_mobile;
                homes[j + 1] = temp_home;
            }
        }
    }
}

void printData(std::string mobiles[], std::string homes[], int size) {
    std::cout << "Мобильные номера\tДомашние номера" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << mobiles[i] << "\t\t" << homes[i] << std::endl;
    }
}

int main() {
    const int size = 5;
    std::string mobiles[size] = {"+79123456789", "+79098765432", "+79234567890", "+79112223344", "+79051112233"};
    std::string homes[size] = {"123-45-67", "234-56-78", "345-67-89", "456-78-90", "567-89-01"};
    
    int choice;
    do {
        std::cout << "\nМеню:" << std::endl;
        std::cout << "1 - Отсортировать по номерам мобильных" << std::endl;
        std::cout << "2 - Отсортировать по домашним номерам телефонов" << std::endl;
        std::cout << "3 - Вывести пользовательские данные" << std::endl;
        std::cout << "4 - Выход" << std::endl;
        std::cout << "Выберите действие: ";
        std::cin >> choice;
        
        switch (choice) {
            case 1:
                sortMobile(mobiles, homes, size);
                std::cout << "Данные отсортированы по мобильным номерам" << std::endl;
                break;
            case 2:
                sortHome(mobiles, homes, size);
                std::cout << "Данные отсортированы по домашним номерам" << std::endl;
                break;
            case 3:
                printData(mobiles, homes, size);
                break;
            case 4:
                std::cout << "Выход из программы" << std::endl;
                break;
            default:
                std::cout << "Неверный выбор" << std::endl;
        }
    } while (choice != 4);
    
    return 0;
}