#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

// Базовый класс Домашнее животное
class Animal {
protected:
    std::string name;       // имя
    std::string type;       // вид
    std::string sound;      // звук
public:
    // Конструктор с именем и характеристиками
    Animal(const std::string& n, const std::string& t, const std::string& s);
    virtual ~Animal();

    // Отображение информации
    void display() const;
};

#endif