#include "Overcoat.h"
#include "Flat.h"
#include <iostream>

void clearInput() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

void printOvercoatMenu() {
    std::cout << "\n===== МЕНЮ (Верхняя одежда) =====\n";
    std::cout << "1. Добавить пальто\n";
    std::cout << "2. Показать все пальто\n";
    std::cout << "3. Сравнить типы одежды (==)\n";
    std::cout << "4. Сравнить по цене (>)\n";
    std::cout << "5. Присвоить один объект другому (=)\n";
    std::cout << "6. Редактировать пальто\n";
    std::cout << "0. Назад\n";
    std::cout << "Ваш выбор: ";
}

void printFlatMenu() {
    std::cout << "\n===== МЕНЮ (Квартиры) =====\n";
    std::cout << "1. Добавить квартиру\n";
    std::cout << "2. Показать все квартиры\n";
    std::cout << "3. Сравнить площади квартир (==)\n";
    std::cout << "4. Сравнить по цене (>)\n";
    std::cout << "5. Присвоить один объект другому (=)\n";
    std::cout << "6. Редактировать квартиру\n";
    std::cout << "0. Назад\n";
    std::cout << "Ваш выбор: ";
}

int main() {
    int mainChoice;

    do {
        std::cout << "\n========== ГЛАВНОЕ МЕНЮ ==========\n";
        std::cout << "1. Работа с верхней одеждой\n";
        std::cout << "2. Работа с квартирами\n";
        std::cout << "0. Выход\n";
        std::cout << "Ваш выбор: ";
        std::cin >> mainChoice;

        if (std::cin.fail()) {
            clearInput();
            std::cout << "Ошибка! Введите число.\n";
            continue;
        }

        if (mainChoice == 1) {
            int capacity = 10;
            int count = 0;
            Overcoat* overcoats = new Overcoat[capacity];
            int subChoice;

            do {
                printOvercoatMenu();
                std::cin >> subChoice;

                if (std::cin.fail()) {
                    clearInput();
                    std::cout << "Ошибка! Введите число.\n";
                    continue;
                }

                switch (subChoice) {
                    case 1: {
                        if (count >= capacity) {
                            capacity += 5;
                            Overcoat* newArray = new Overcoat[capacity];
                            for (int i = 0; i < count; i++) {
                                newArray[i] = overcoats[i];
                            }
                            delete[] overcoats;
                            overcoats = newArray;
                        }
                        std::cin.ignore();
                        overcoats[count].input();
                        count++;
                        std::cout << "Пальто успешно добавлено!\n";
                        break;
                    }

                    case 2: {
                        if (count == 0) {
                            std::cout << "Нет добавленных пальто!\n";
                            break;
                        }
                        std::cout << "\n===== СПИСОК ПАЛЬТО =====\n";
                        for (int i = 0; i < count; i++) {
                            std::cout << i + 1 << ". ";
                            overcoats[i].display();
                        }
                        break;
                    }

                    case 3: {
                        if (count < 2) {
                            std::cout << "Нужно минимум 2 пальто для сравнения!\n";
                            break;
                        }
                        int idx1, idx2;
                        std::cout << "Введите номер первого пальто (1-" << count << "): ";
                        std::cin >> idx1;
                        std::cout << "Введите номер второго пальто (1-" << count << "): ";
                        std::cin >> idx2;
                        if (idx1 < 1 || idx1 > count || idx2 < 1 || idx2 > count) {
                            std::cout << "Неверный номер!\n";
                            break;
                        }
                        if (overcoats[idx1 - 1] == overcoats[idx2 - 1]) {
                            std::cout << "Типы одежды одинаковые\n";
                        } else {
                            std::cout << "Типы одежды разные\n";
                        }
                        break;
                    }

                    case 4: {
                        if (count < 2) {
                            std::cout << "Нужно минимум 2 пальто для сравнения!\n";
                            break;
                        }
                        int idx1, idx2;
                        std::cout << "Введите номер первого пальто (1-" << count << "): ";
                        std::cin >> idx1;
                        std::cout << "Введите номер второго пальто (1-" << count << "): ";
                        std::cin >> idx2;
                        if (idx1 < 1 || idx1 > count || idx2 < 1 || idx2 > count) {
                            std::cout << "Неверный номер!\n";
                            break;
                        }
                        if (overcoats[idx1 - 1] > overcoats[idx2 - 1]) {
                            std::cout << "Первое пальто дороже второго\n";
                        } else {
                            std::cout << "Первое пальто дешевле или равно второму\n";
                        }
                        break;
                    }

                    case 5: {
                        if (count == 0) {
                            std::cout << "Нет пальто для присваивания!\n";
                            break;
                        }
                        int src, dest;
                        std::cout << "Введите номер исходного пальто (1-" << count << "): ";
                        std::cin >> src;
                        std::cout << "Введите номер целевого пальто (1-" << count << "): ";
                        std::cin >> dest;
                        if (src < 1 || src > count || dest < 1 || dest > count) {
                            std::cout << "Неверный номер!\n";
                            break;
                        }
                        overcoats[dest - 1] = overcoats[src - 1];
                        std::cout << "Присваивание выполнено!\n";
                        break;
                    }

                    case 6: {
                        if (count == 0) {
                            std::cout << "Нет пальто для редактирования!\n";
                            break;
                        }
                        int idx;
                        std::cout << "Введите номер пальто для редактирования (1-" << count << "): ";
                        std::cin >> idx;
                        if (idx < 1 || idx > count) {
                            std::cout << "Неверный номер!\n";
                            break;
                        }
                        std::cin.ignore();
                        overcoats[idx - 1].input();
                        std::cout << "Пальто успешно отредактировано!\n";
                        break;
                    }

                    case 0:
                        std::cout << "Возврат в главное меню...\n";
                        break;

                    default:
                        std::cout << "Неверный выбор!\n";
                }
            } while (subChoice != 0);

            delete[] overcoats;
        }
        else if (mainChoice == 2) {
            int capacity = 10;
            int count = 0;
            Flat* flats = new Flat[capacity];
            int subChoice;

            do {
                printFlatMenu();
                std::cin >> subChoice;

                if (std::cin.fail()) {
                    clearInput();
                    std::cout << "Ошибка! Введите число.\n";
                    continue;
                }

                switch (subChoice) {
                    case 1: {
                        if (count >= capacity) {
                            capacity += 5;
                            Flat* newArray = new Flat[capacity];
                            for (int i = 0; i < count; i++) {
                                newArray[i] = flats[i];
                            }
                            delete[] flats;
                            flats = newArray;
                        }
                        std::cin.ignore();
                        flats[count].input();
                        count++;
                        std::cout << "Квартира успешно добавлена!\n";
                        break;
                    }

                    case 2: {
                        if (count == 0) {
                            std::cout << "Нет добавленных квартир!\n";
                            break;
                        }
                        std::cout << "\n===== СПИСОК КВАРТИР =====\n";
                        for (int i = 0; i < count; i++) {
                            std::cout << i + 1 << ". ";
                            flats[i].display();
                        }
                        break;
                    }

                    case 3: {
                        if (count < 2) {
                            std::cout << "Нужно минимум 2 квартиры для сравнения!\n";
                            break;
                        }
                        int idx1, idx2;
                        std::cout << "Введите номер первой квартиры (1-" << count << "): ";
                        std::cin >> idx1;
                        std::cout << "Введите номер второй квартиры (1-" << count << "): ";
                        std::cin >> idx2;
                        if (idx1 < 1 || idx1 > count || idx2 < 1 || idx2 > count) {
                            std::cout << "Неверный номер!\n";
                            break;
                        }
                        if (flats[idx1 - 1] == flats[idx2 - 1]) {
                            std::cout << "Площади квартир равны\n";
                        } else {
                            std::cout << "Площади квартир не равны\n";
                        }
                        break;
                    }

                    case 4: {
                        if (count < 2) {
                            std::cout << "Нужно минимум 2 квартиры для сравнения!\n";
                            break;
                        }
                        int idx1, idx2;
                        std::cout << "Введите номер первой квартиры (1-" << count << "): ";
                        std::cin >> idx1;
                        std::cout << "Введите номер второй квартиры (1-" << count << "): ";
                        std::cin >> idx2;
                        if (idx1 < 1 || idx1 > count || idx2 < 1 || idx2 > count) {
                            std::cout << "Неверный номер!\n";
                            break;
                        }
                        if (flats[idx1 - 1] > flats[idx2 - 1]) {
                            std::cout << "Первая квартира дороже второй\n";
                        } else {
                            std::cout << "Первая квартира дешевле или равна второй\n";
                        }
                        break;
                    }

                    case 5: {
                        if (count == 0) {
                            std::cout << "Нет квартир для присваивания!\n";
                            break;
                        }
                        int src, dest;
                        std::cout << "Введите номер исходной квартиры (1-" << count << "): ";
                        std::cin >> src;
                        std::cout << "Введите номер целевой квартиры (1-" << count << "): ";
                        std::cin >> dest;
                        if (src < 1 || src > count || dest < 1 || dest > count) {
                            std::cout << "Неверный номер!\n";
                            break;
                        }
                        flats[dest - 1] = flats[src - 1];
                        std::cout << "Присваивание выполнено!\n";
                        break;
                    }

                    case 6: {
                        if (count == 0) {
                            std::cout << "Нет квартир для редактирования!\n";
                            break;
                        }
                        int idx;
                        std::cout << "Введите номер квартиры для редактирования (1-" << count << "): ";
                        std::cin >> idx;
                        if (idx < 1 || idx > count) {
                            std::cout << "Неверный номер!\n";
                            break;
                        }
                        std::cin.ignore();
                        flats[idx - 1].input();
                        std::cout << "Квартира успешно отредактирована!\n";
                        break;
                    }

                    case 0:
                        std::cout << "Возврат в главное меню...\n";
                        break;

                    default:
                        std::cout << "Неверный выбор!\n";
                }
            } while (subChoice != 0);

            delete[] flats;
        }

    } while (mainChoice != 0);

    std::cout << "Программа завершена. До свидания!\n";
    return 0;
}