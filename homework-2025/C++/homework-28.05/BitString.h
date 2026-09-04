#ifndef BITSTRING_H
#define BITSTRING_H

#include "String.h"

class BitString : public String {
public:
    // 1) конструктор без параметров
    BitString();

    // 2) конструктор из C-строки (проверяет символы)
    BitString(const char* str);

    // 3) конструктор копирования
    BitString(const BitString& other);

    // 4) оператор присваивания
    BitString& operator=(const BitString& other);

    // 5) деструктор (не нужен, автоматический вызов базового)

    // 6) изменение знака (перевод в дополнительный код)
    void changeSign();

    // 7) сложение битовых строк
    BitString operator+(const BitString& other) const;

    // Преобразование в целое число
    long long toInt() const;

private:
    static BitString fromInt(long long value);
    static bool isValidBinary(const char* str);
};

#endif