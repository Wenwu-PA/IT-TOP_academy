#include "PhoneBook.h"
#include <cstdlib>

Abonent::Abonent() {
    fullName = new char[1];
    fullName[0] = '\0';
    homePhone[0] = '\0';
    workPhone[0] = '\0';
    mobilePhone[0] = '\0';
    additionalInfo[0] = '\0';
}

Abonent::Abonent(const char* name, const char* home, const char* work, 
                 const char* mobile, const char* info) {
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
    strcpy(homePhone, home);
    strcpy(workPhone, work);
    strcpy(mobilePhone, mobile);
    strcpy(additionalInfo, info);
}

Abonent::Abonent(const Abonent& other) {
    fullName = new char[strlen(other.fullName) + 1];
    strcpy(fullName, other.fullName);
    strcpy(homePhone, other.homePhone);
    strcpy(workPhone, other.workPhone);
    strcpy(mobilePhone, other.mobilePhone);
    strcpy(additionalInfo, other.additionalInfo);
}

Abonent::~Abonent() {
    delete[] fullName;
}

void Abonent::setFullName(const char* name) {
    delete[] fullName;
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
}

void Abonent::display() const {
    std::cout << "\n=== Информация об абоненте ===" << std::endl;
    std::cout << "ФИО: " << (fullName[0] ? fullName : "Не указано") << std::endl;
    std::cout << "Домашний телефон: " << (homePhone[0] ? homePhone : "Не указан") << std::endl;
    std::cout << "Рабочий телефон: " << (workPhone[0] ? workPhone : "Не указан") << std::endl;
    std::cout << "Мобильный телефон: " << (mobilePhone[0] ? mobilePhone : "Не указан") << std::endl;
    std::cout << "Дополнительная информация: " << (additionalInfo[0] ? additionalInfo : "Отсутствует") << std::endl;
}

void Abonent::edit() {
    char buffer[200];
    
    std::cout << "\n=== Редактирование абонента ===" << std::endl;
    std::cout << "Введите новое ФИО: ";
    std::cin >> buffer;
    if(buffer[0] != '\0') {
        setFullName(buffer);
    }
    
    std::cout << "Введите новый домашний телефон: ";
    std::cin >> buffer;
    if(buffer[0] != '\0') strcpy(homePhone, buffer);
    
    std::cout << "Введите новый рабочий телефон: ";
    std::cin >> buffer;
    if(buffer[0] != '\0') strcpy(workPhone, buffer);
    
    std::cout << "Введите новый мобильный телефон: ";
    std::cin >> buffer;
    if(buffer[0] != '\0') strcpy(mobilePhone, buffer);
    
    std::cout << "Введите новую дополнительную информацию: ";
    std::cin >> buffer;
    if(buffer[0] != '\0') strcpy(additionalInfo, buffer);
}

void Abonent::saveToFile(std::ofstream& file) const {
    size_t nameLength = strlen(fullName);
    file.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
    file.write(fullName, nameLength);
    file.write(homePhone, sizeof(homePhone));
    file.write(workPhone, sizeof(workPhone));
    file.write(mobilePhone, sizeof(mobilePhone));
    file.write(additionalInfo, sizeof(additionalInfo));
}

void Abonent::loadFromFile(std::ifstream& file) {
    size_t nameLength;
    file.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
    
    delete[] fullName;
    fullName = new char[nameLength + 1];
    file.read(fullName, nameLength);
    fullName[nameLength] = '\0';
    
    file.read(homePhone, sizeof(homePhone));
    file.read(workPhone, sizeof(workPhone));
    file.read(mobilePhone, sizeof(mobilePhone));
    file.read(additionalInfo, sizeof(additionalInfo));
}

PhoneBook::PhoneBook() : capacity(10), count(0) {
    abonents = new Abonent[capacity];
}

PhoneBook::~PhoneBook() {
    delete[] abonents;
}

void PhoneBook::resize() {
    capacity *= 2;
    Abonent* newAbonents = new Abonent[capacity];
    for(int i = 0; i < count; i++) {
        newAbonents[i] = abonents[i];
    }
    delete[] abonents;
    abonents = newAbonents;
}

void PhoneBook::addAbonent() {
    char name[200], home[20], work[20], mobile[20], info[200];
    
    std::cout << "\n=== Добавление нового абонента ===" << std::endl;
    std::cout << "Введите ФИО: ";
    std::cin >> name;
    
    std::cout << "Введите домашний телефон: ";
    std::cin >> home;
    
    std::cout << "Введите рабочий телефон: ";
    std::cin >> work;
    
    std::cout << "Введите мобильный телефон: ";
    std::cin >> mobile;
    
    std::cout << "Введите дополнительную информацию: ";
    std::cin >> info;
    
    if(count >= capacity) {
        resize();
    }
    
    abonents[count] = Abonent(name, home, work, mobile, info);
    count++;
    std::cout << "Абонент успешно добавлен!" << std::endl;
}

void PhoneBook::removeAbonent(int index) {
    if(index < 0 || index >= count) {
        std::cout << "Неверный индекс!" << std::endl;
        return;
    }
    
    for(int i = index; i < count - 1; i++) {
        abonents[i] = abonents[i + 1];
    }
    count--;
    std::cout << "Абонент удален!" << std::endl;
}

void PhoneBook::removeAbonent(const char* name) {
    for(int i = 0; i < count; i++) {
        if(strcmp(abonents[i].getFullName(), name) == 0) {
            removeAbonent(i);
            return;
        }
    }
    std::cout << "Абонент с ФИО \"" << name << "\" не найден!" << std::endl;
}

void PhoneBook::searchByName(const char* name) const {
    bool found = false;
    for(int i = 0; i < count; i++) {
        if(strcmp(abonents[i].getFullName(), name) == 0) {
            std::cout << "\nАбонент найден:" << std::endl;
            abonents[i].display();
            found = true;
        }
    }
    
    if(!found) {
        std::cout << "Абоненты с ФИО \"" << name << "\" не найдены!" << std::endl;
    }
}

void PhoneBook::displayAll() const {
    if(count == 0) {
        std::cout << "\nТелефонная книга пуста!" << std::endl;
        return;
    }
    
    std::cout << "\n========== ТЕЛЕФОННАЯ КНИГА ==========" << std::endl;
    std::cout << "Всего абонентов: " << count << std::endl;
    for(int i = 0; i < count; i++) {
        std::cout << "\n--- Абонент #" << i + 1 << " ---";
        abonents[i].display();
    }
}

void PhoneBook::saveToFile(const char* filename) const {
    std::ofstream file(filename, std::ios::binary);
    if(!file.is_open()) {
        std::cout << "Ошибка открытия файла для записи!" << std::endl;
        return;
    }
    
    file.write(reinterpret_cast<const char*>(&count), sizeof(count));
    
    for(int i = 0; i < count; i++) {
        abonents[i].saveToFile(file);
    }
    
    file.close();
    std::cout << "Данные успешно сохранены в файл \"" << filename << "\"" << std::endl;
}

void PhoneBook::loadFromFile(const char* filename) {
    std::ifstream file(filename, std::ios::binary);
    if(!file.is_open()) {
        std::cout << "Ошибка открытия файла для чтения!" << std::endl;
        return;
    }
    
    int newCount;
    file.read(reinterpret_cast<char*>(&newCount), sizeof(newCount));
    
    delete[] abonents;
    capacity = newCount > 10 ? newCount * 2 : 10;
    abonents = new Abonent[capacity];
    count = newCount;
    
    for(int i = 0; i < count; i++) {
        abonents[i].loadFromFile(file);
    }
    
    file.close();
    std::cout << "Данные успешно загружены из файла \"" << filename << "\"" << std::endl;
}