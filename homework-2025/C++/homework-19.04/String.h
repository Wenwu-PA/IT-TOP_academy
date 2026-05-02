#ifndef STRING_H
#define STRING_H

#include <iostream>

class String {
private:
    char* str;
    int length;
    static int objectCount;

public:
    // Старые конструкторы
    String();
    String(int size);
    String(const char* input);
    String(const String& other);
    ~String();

    // Конструктор переноса (задание 8)
    String(String&& other) noexcept;

    // Оператор присваивания с переносом
    String& operator=(String&& other) noexcept;

    // Перегрузки (задание 9)
    char& operator[](int index);
    const char& operator[](int index) const;
    int operator()(char ch) const;
    operator int() const;

    // Остальные методы
    void input();
    void output() const;
    static int getObjectCount();
    const char* c_str() const;   // удобно для вывода
};

#endif