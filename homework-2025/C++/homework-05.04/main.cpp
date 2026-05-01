// main.cpp
#include "Reservoir.h"
#include <fstream>
#include <cstdlib>
#include <limits>

void clearInput() {
    std::cin.clear();
    std::cin.ignore(10000, '\n');
}

void printMenu() {
    std::cout << "\n========== МЕНЮ ==========" << std::endl;
    std::cout << "1. Добавить водоем" << std::endl;
    std::cout << "2. Удалить водоем (по индексу)" << std::endl;
    std::cout << "3. Показать все водоемы" << std::endl;
    std::cout << "4. Найти водоем по названию" << std::endl;
    std::cout << "5. Сравнить площадь двух водоемов (одного типа)" << std::endl;
    std::cout << "6. Проверить тип водоемов" << std::endl;
    std::cout << "7. Сохранить в текстовый файл" << std::endl;
    std::cout << "8. Загрузить из текстового файла" << std::endl;
    std::cout << "9. Сохранить в бинарный файл" << std::endl;
    std::cout << "10. Загрузить из бинарного файла" << std::endl;
    std::cout << "11. Редактировать водоем" << std::endl;
    std::cout << "0. Выход" << std::endl;
    std::cout << "Ваш выбор: ";
}

void saveToTextFile(Reservoir* reservoirs, int count, const char* filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return;
    }

    file << count << std::endl;
    for (int i = 0; i < count; i++) {
        file << reservoirs[i].getName() << std::endl;
        file << reservoirs[i].getType() << std::endl;
        file << reservoirs[i].getWidth() << std::endl;
        file << reservoirs[i].getLength() << std::endl;
        file << reservoirs[i].getMaxDepth() << std::endl;
    }

    file.close();
    std::cout << "Данные сохранены в текстовый файл: " << filename << std::endl;
}

void loadFromTextFile(Reservoir*& reservoirs, int& count, int& capacity, const char* filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return;
    }

    int newCount;
    file >> newCount;
    file.ignore();

    delete[] reservoirs;
    capacity = newCount + 5;
    reservoirs = new Reservoir[capacity];
    count = newCount;

    for (int i = 0; i < count; i++) {
        char nameBuffer[200];
        int typeInt;
        double width, length, maxDepth;

        file.getline(nameBuffer, 200);
        file >> typeInt;
        file >> width;
        file >> length;
        file >> maxDepth;
        file.ignore();

        reservoirs[i] = Reservoir(nameBuffer, static_cast<ReservoirType>(typeInt), width, length, maxDepth);
    }

    file.close();
    std::cout << "Данные загружены из текстового файла: " << filename << std::endl;
}

void saveToBinaryFile(Reservoir* reservoirs, int count, const char* filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(&count), sizeof(count));

    for (int i = 0; i < count; i++) {
        int nameLength = strlen(reservoirs[i].getName()) + 1;
        file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        file.write(reservoirs[i].getName(), nameLength);

        int type = reservoirs[i].getType();
        file.write(reinterpret_cast<const char*>(&type), sizeof(type));

        double width = reservoirs[i].getWidth();
        double length = reservoirs[i].getLength();
        double maxDepth = reservoirs[i].getMaxDepth();

        file.write(reinterpret_cast<const char*>(&width), sizeof(width));
        file.write(reinterpret_cast<const char*>(&length), sizeof(length));
        file.write(reinterpret_cast<const char*>(&maxDepth), sizeof(maxDepth));
    }

    file.close();
    std::cout << "Данные сохранены в бинарный файл: " << filename << std::endl;
}

void loadFromBinaryFile(Reservoir*& reservoirs, int& count, int& capacity, const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cout << "Ошибка открытия файла!" << std::endl;
        return;
    }

    int newCount;
    file.read(reinterpret_cast<char*>(&newCount), sizeof(newCount));

    delete[] reservoirs;
    capacity = newCount + 5;
    reservoirs = new Reservoir[capacity];
    count = newCount;

    for (int i = 0; i < count; i++) {
        int nameLength;
        file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));

        char* nameBuffer = new char[nameLength];
        file.read(nameBuffer, nameLength);

        int type;
        file.read(reinterpret_cast<char*>(&type), sizeof(type));

        double width, length, maxDepth;
        file.read(reinterpret_cast<char*>(&width), sizeof(width));
        file.read(reinterpret_cast<char*>(&length), sizeof(length));
        file.read(reinterpret_cast<char*>(&maxDepth), sizeof(maxDepth));

        reservoirs[i] = Reservoir(nameBuffer, static_cast<ReservoirType>(type), width, length, maxDepth);
        delete[] nameBuffer;
    }

    file.close();
    std::cout << "Данные загружены из бинарного файла: " << filename << std::endl;
}

int main() {
    int capacity = 10;
    int count = 0;
    Reservoir* reservoirs = new Reservoir[capacity];

    int choice;
    char filename[100];
    char searchName[200];

    do {
        printMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            clearInput();
            std::cout << "Ошибка! Введите число." << std::endl;
            continue;
        }

        switch (choice) {
            case 1: {
                if (count >= capacity) {
                    capacity += 5;
                    Reservoir* newReservoirs = new Reservoir[capacity];
                    for (int i = 0; i < count; i++) {
                        newReservoirs[i] = reservoirs[i];
                    }
                    delete[] reservoirs;
                    reservoirs = newReservoirs;
                }
                std::cin.ignore();
                reservoirs[count].input();
                count++;
                std::cout << "Водоем успешно добавлен!" << std::endl;
                break;
            }

            case 2: {
                if (count == 0) {
                    std::cout << "Нет водоемов для удаления!" << std::endl;
                    break;
                }
                int index;
                std::cout << "Введите индекс водоема для удаления (1-" << count << "): ";
                std::cin >> index;
                if (index < 1 || index > count) {
                    std::cout << "Неверный индекс!" << std::endl;
                    break;
                }
                for (int i = index - 1; i < count - 1; i++) {
                    reservoirs[i] = reservoirs[i + 1];
                }
                count--;
                std::cout << "Водоем удален!" << std::endl;
                break;
            }

            case 3: {
                if (count == 0) {
                    std::cout << "Нет водоемов для отображения!" << std::endl;
                    break;
                }
                std::cout << "\n========== ВСЕ ВОДОЕМЫ ==========" << std::endl;
                for (int i = 0; i < count; i++) {
                    std::cout << "\n--- Водоем #" << i + 1 << " ---";
                    reservoirs[i].display();
                }
                break;
            }

            case 4: {
                if (count == 0) {
                    std::cout << "Нет водоемов для поиска!" << std::endl;
                    break;
                }
                std::cin.ignore();
                std::cout << "Введите название для поиска: ";
                std::cin.getline(searchName, 200);
                bool found = false;
                for (int i = 0; i < count; i++) {
                    if (strcmp(reservoirs[i].getName(), searchName) == 0) {
                        std::cout << "\nВодоем найден (индекс " << i + 1 << "):";
                        reservoirs[i].display();
                        found = true;
                    }
                }
                if (!found) {
                    std::cout << "Водоем с названием \"" << searchName << "\" не найден!" << std::endl;
                }
                break;
            }

            case 5: {
                if (count < 2) {
                    std::cout << "Недостаточно водоемов для сравнения!" << std::endl;
                    break;
                }
                int idx1, idx2;
                std::cout << "Введите индекс первого водоема (1-" << count << "): ";
                std::cin >> idx1;
                std::cout << "Введите индекс второго водоема (1-" << count << "): ";
                std::cin >> idx2;
                if (idx1 < 1 || idx1 > count || idx2 < 1 || idx2 > count) {
                    std::cout << "Неверный индекс!" << std::endl;
                    break;
                }
                if (!reservoirs[idx1 - 1].sameType(reservoirs[idx2 - 1])) {
                    std::cout << "Водоемы разных типов! Сравнение невозможно." << std::endl;
                    break;
                }
                if (reservoirs[idx1 - 1].compareSurfaceArea(reservoirs[idx2 - 1])) {
                    std::cout << "Площадь первого водоема больше" << std::endl;
                } else {
                    std::cout << "Площадь второго водоема больше или равна" << std::endl;
                }
                break;
            }

            case 6: {
                if (count < 2) {
                    std::cout << "Недостаточно водоемов для проверки!" << std::endl;
                    break;
                }
                int idx1, idx2;
                std::cout << "Введите индекс первого водоема (1-" << count << "): ";
                std::cin >> idx1;
                std::cout << "Введите индекс второго водоема (1-" << count << "): ";
                std::cin >> idx2;
                if (idx1 < 1 || idx1 > count || idx2 < 1 || idx2 > count) {
                    std::cout << "Неверный индекс!" << std::endl;
                    break;
                }
                if (reservoirs[idx1 - 1].sameType(reservoirs[idx2 - 1])) {
                    std::cout << "Водоемы относятся к одному типу" << std::endl;
                } else {
                    std::cout << "Водоемы относятся к разным типам" << std::endl;
                }
                break;
            }

            case 7: {
                std::cout << "Введите имя текстового файла: ";
                std::cin >> filename;
                saveToTextFile(reservoirs, count, filename);
                break;
            }

            case 8: {
                std::cout << "Введите имя текстового файла: ";
                std::cin >> filename;
                loadFromTextFile(reservoirs, count, capacity, filename);
                break;
            }

            case 9: {
                std::cout << "Введите имя бинарного файла: ";
                std::cin >> filename;
                saveToBinaryFile(reservoirs, count, filename);
                break;
            }

            case 10: {
                std::cout << "Введите имя бинарного файла: ";
                std::cin >> filename;
                loadFromBinaryFile(reservoirs, count, capacity, filename);
                break;
            }

            case 11: {
                if (count == 0) {
                    std::cout << "Нет водоемов для редактирования!" << std::endl;
                    break;
                }
                int index;
                std::cout << "Введите индекс водоема для редактирования (1-" << count << "): ";
                std::cin >> index;
                if (index < 1 || index > count) {
                    std::cout << "Неверный индекс!" << std::endl;
                    break;
                }
                std::cin.ignore();
                std::cout << "\n=== Редактирование водоема ===" << std::endl;
                reservoirs[index - 1].input();
                std::cout << "Водоем успешно отредактирован!" << std::endl;
                break;
            }

            case 0: {
                std::cout << "Программа завершена. До свидания!" << std::endl;
                break;
            }

            default: {
                std::cout << "Неверный выбор! Попробуйте снова." << std::endl;
                break;
            }
        }
    } while (choice != 0);

    delete[] reservoirs;
    return 0;
}