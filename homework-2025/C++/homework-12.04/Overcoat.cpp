#include "Overcoat.h"
#include <cstring>

int Overcoat::objectCount = 0;

Overcoat::Overcoat() : price(0.0) {
    type = new char[1];
    type[0] = '\0';
    objectCount++;
}

Overcoat::Overcoat(const char* t, double p) : price(p) {
    type = new char[strlen(t) + 1];
    strcpy(type, t);
    objectCount++;
}

Overcoat::Overcoat(const Overcoat& other) : price(other.price) {
    type = new char[strlen(other.type) + 1];
    strcpy(type, other.type);
    objectCount++;
}

Overcoat::~Overcoat() {
    delete[] type;
    objectCount--;
}

Overcoat& Overcoat::operator=(const Overcoat& other) {
    if (this != &other) {
        delete[] type;
        type = new char[strlen(other.type) + 1];
        strcpy(type, other.type);
        price = other.price;
    }
    return *this;
}

bool Overcoat::operator==(const Overcoat& other) const {
    return strcmp(this->type, other.type) == 0;
}

bool Overcoat::operator>(const Overcoat& other) const {
    if (!(*this == other)) {
        std::cout << "Ошибка: сравнение разных типов одежды!\n";
        return false;
    }
    return this->price > other.price;
}

void Overcoat::display() const {
    std::cout << "Тип одежды: " << type << ", Цена: " << price << " руб.\n";
}

void Overcoat::input() {
    char buffer[100];
    std::cout << "Введите тип одежды: ";
    std::cin.getline(buffer, 100);
    setType(buffer);
    std::cout << "Введите цену: ";
    std::cin >> price;
    std::cin.ignore();
}

const char* Overcoat::getType() const { return type; }
double Overcoat::getPrice() const { return price; }

void Overcoat::setType(const char* t) {
    delete[] type;
    type = new char[strlen(t) + 1];
    strcpy(type, t);
}

void Overcoat::setPrice(double p) { price = p; }

int Overcoat::getObjectCount() { return objectCount; }