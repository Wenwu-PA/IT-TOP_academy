#include "String.h"
#include <cstring>

String::String() : data(nullptr), length(0) {
    data = new char[1];
    data[0] = '\0';
}

String::String(const char* str) {
    length = std::strlen(str);
    data = new char[length + 1];
    std::strcpy(data, str);
}

String::String(const String& other) {
    length = other.length;
    data = new char[length + 1];
    std::strcpy(data, other.data);
}

String& String::operator=(const String& other) {
    if (this == &other) return *this;
    delete[] data;
    length = other.length;
    data = new char[length + 1];
    std::strcpy(data, other.data);
    return *this;
}

size_t String::size() const {
    return length;
}

void String::clear() {
    delete[] data;
    length = 0;
    data = new char[1];
    data[0] = '\0';
}

String::~String() {
    delete[] data;
}

String String::operator+(const String& other) const {
    String result;
    delete[] result.data;
    result.length = length + other.length;
    result.data = new char[result.length + 1];
    std::strcpy(result.data, data);
    std::strcat(result.data, other.data);
    return result;
}

String& String::operator+=(const String& other) {
    *this = *this + other;
    return *this;
}

bool String::operator==(const String& other) const {
    return std::strcmp(data, other.data) == 0;
}

bool String::operator!=(const String& other) const {
    return !(*this == other);
}

const char* String::c_str() const {
    return data;
}