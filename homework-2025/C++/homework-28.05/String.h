#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
protected:
    char* data;          // указатель на C-строку
    size_t length;       // длина строки

public:
    // 1) конструктор без параметров
    String();

    // 2) конструктор из C-строки
    String(const char* str);

    // 3) конструктор копирования
    String(const String& other);

    // 4) оператор присваивания
    String& operator=(const String& other);

    // 5) получение длины
    size_t size() const;

    // 6) очистка строки
    void clear();

    // 7) деструктор
    ~String();

    // 8) конкатенация
    String operator+(const String& other) const;
    String& operator+=(const String& other);

    // 9) сравнение
    bool operator==(const String& other) const;
    bool operator!=(const String& other) const;

    // Дополнительно: доступ к C-строке (для производных)
    const char* c_str() const;
};

#endif