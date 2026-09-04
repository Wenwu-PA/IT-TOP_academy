#include "Animal.h"
#include <iostream>

Animal::Animal(const std::string& n, const std::string& t, const std::string& s)
    : name(n), type(t), sound(s) {}

Animal::~Animal() {}

void Animal::display() const {
    std::cout << "Тип: " << type << ", Имя: " << name 
              << ", Голос: " << sound << std::endl;
}