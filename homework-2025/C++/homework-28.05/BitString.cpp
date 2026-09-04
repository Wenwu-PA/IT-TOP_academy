#include "BitString.h"
#include <cstring>
#include <algorithm>

bool BitString::isValidBinary(const char* str) {
    if (!str) return false;
    while (*str) {
        if (*str != '0' && *str != '1') return false;
        ++str;
    }
    return true;
}

BitString::BitString() : String() {}

BitString::BitString(const char* str) : String("") {
    if (isValidBinary(str)) {
        String tmp(str);
        // Копируем данные из временной строки
        delete[] data;
        length = tmp.size();
        data = new char[length + 1];
        std::strcpy(data, tmp.c_str());
    }
}

BitString::BitString(const BitString& other) : String(other) {}

BitString& BitString::operator=(const BitString& other) {
    if (this == &other) return *this;
    String::operator=(other);
    return *this;
}

void BitString::changeSign() {
    if (length == 0) return;
    
    // Инвертируем все биты
    for (size_t i = 0; i < length; ++i) {
        data[i] = (data[i] == '0') ? '1' : '0';
    }
    
    // Прибавляем 1 в двоичной системе
    int carry = 1;
    for (int i = (int)length - 1; i >= 0 && carry; --i) {
        if (data[i] == '0') {
            data[i] = '1';
            carry = 0;
        } else {
            data[i] = '0';
            carry = 1;
        }
    }
    
    if (carry) {
        // Переполнение: добавляем ещё один бит '1' в начало
        char* newData = new char[length + 2];
        newData[0] = '1';
        std::strcpy(newData + 1, data);
        delete[] data;
        data = newData;
        length++;
    }
}

long long BitString::toInt() const {
    if (length == 0) return 0;
    
    bool negative = (data[0] == '1');
    unsigned long long value = 0;
    
    for (size_t i = 0; i < length; ++i) {
        value = (value << 1) | (data[i] - '0');
    }
    
    if (negative && length <= 63) {
        value = value - (1ULL << length);
        return (long long)value;
    }
    
    return (long long)value;
}

BitString BitString::fromInt(long long value) {
    if (value == 0) return BitString("0");
    
    bool negative = (value < 0);
    unsigned long long absVal = negative ? -value : value;
    
    char buffer[65];
    int pos = 0;
    while (absVal > 0) {
        buffer[pos++] = (absVal & 1) ? '1' : '0';
        absVal >>= 1;
    }
    std::reverse(buffer, buffer + pos);
    std::string str(buffer, pos);
    
    if (negative) {
        // Инвертируем
        for (char& c : str) c = (c == '0') ? '1' : '0';
        // Прибавляем 1
        int carry = 1;
        for (int i = (int)str.size() - 1; i >= 0 && carry; --i) {
            if (str[i] == '0') { str[i] = '1'; carry = 0; }
            else { str[i] = '0'; carry = 1; }
        }
        if (carry) str = "1" + str;
        if (str.front() == '0') str = "1" + str;
    }
    
    return BitString(str.c_str());
}

BitString BitString::operator+(const BitString& other) const {
    long long a = this->toInt();
    long long b = other.toInt();
    long long sum = a + b;
    return BitString::fromInt(sum);
}