#include "String.h"
#include <cstring>
#include <cstdlib>

int String::objectCount = 0;

String::String() : String(80) {}

String::String(int size) : length(size) {
    str = new char[length + 1];
    str[0] = '\0';
    objectCount++;
}

String::String(const char* input) : length(strlen(input)) {
    str = new char[length + 1];
    strcpy(str, input);
    objectCount++;
}

String::String(const String& other) : length(other.length) {
    str = new char[length + 1];
    strcpy(str, other.str);
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
    length = strlen(buffer);
    str = new char[length + 1];
    strcpy(str, buffer);
}

void String::output() const {
    std::cout << "Строка: " << str << std::endl;
    std::cout << "Длина: " << length << std::endl;
}

int String::getObjectCount() {
    return objectCount;
}

