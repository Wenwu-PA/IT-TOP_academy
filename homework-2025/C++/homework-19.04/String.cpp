#include "String.h"
#include <cstring>
#include <iostream>

int String::objectCount = 0;

// Конструктор по умолчанию (с размером 80)
String::String() : String(80) {}

String::String(int size) : length(size) {
    str = new char[length + 1];
    str[0] = '\0';
    objectCount++;
}

String::String(const char* input) : length(std::strlen(input)) {
    str = new char[length + 1];
    std::strcpy(str, input);
    objectCount++;
}

String::String(const String& other) : length(other.length) {
    str = new char[length + 1];
    std::strcpy(str, other.str);
    objectCount++;
}

String::~String() {
    delete[] str;
    objectCount--;
}

void String::input() {
    char buffer[1000];
    std::cout << "Введите строку: ";
    std::cin.getline(buffer, 1000);
    
    delete[] str;
    length = std::strlen(buffer);
    str = new char[length + 1];
    std::strcpy(str, buffer);
}

void String::output() const {
    std::cout << "Строка: " << str << std::endl;
    std::cout << "Длина: " << length << std::endl;
}

int String::getObjectCount() {
    return objectCount;
}

const char* String::c_str() const {
    return str;
}

// ========== НОВЫЕ МЕТОДЫ ==========

// Конструктор переноса (сохраняет перемещённый объект в пустом корректном состоянии)
String::String(String&& other) noexcept
    : str(other.str), length(other.length)
{
    // Делаем other пустой строкой, а не nullptr
    other.str = new char[1];
    other.str[0] = '\0';
    other.length = 0;
    // objectCount не меняем, т.к. объект не создаётся заново
}

// Оператор присваивания с переносом
String& String::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] str;               // освобождаем свои ресурсы
        str = other.str;
        length = other.length;
        // Оставляем other в пустом корректном состоянии
        other.str = new char[1];
        other.str[0] = '\0';
        other.length = 0;
    }
    return *this;
}

// Перегрузка [] (неконстантная)
char& String::operator[](int index) {
    if (index < 0 || index >= length) {
        std::cerr << "Ошибка: индекс вне границ!" << std::endl;
        static char dummy = '\0';
        return dummy;
    }
    return str[index];
}

// Константная версия []
const char& String::operator[](int index) const {
    if (index < 0 || index >= length) {
        std::cerr << "Ошибка: индекс вне границ!" << std::endl;
        static const char dummy = '\0';
        return dummy;
    }
    return str[index];
}

// Поиск символа ()
int String::operator()(char ch) const {
    for (int i = 0; i < length; ++i) {
        if (str[i] == ch)
            return i;
    }
    return -1;
}

// Преобразование к int (длина)
String::operator int() const {
    return length;
}