#include "Flat.h"

int Flat::objectCount = 0;

Flat::Flat() : area(0.0), price(0.0) {
    objectCount++;
}

Flat::Flat(double a, double p) : area(a), price(p) {
    objectCount++;
}

Flat::Flat(const Flat& other) : area(other.area), price(other.price) {
    objectCount++;
}

Flat::~Flat() {
    objectCount--;
}

Flat& Flat::operator=(const Flat& other) {
    if (this != &other) {
        area = other.area;
        price = other.price;
    }
    return *this;
}

bool Flat::operator==(const Flat& other) const {
    return this->area == other.area;
}

bool Flat::operator>(const Flat& other) const {
    return this->price > other.price;
}

void Flat::display() const {
    std::cout << "Площадь: " << area << " кв.м, Цена: " << price << " руб.\n";
}

void Flat::input() {
    std::cout << "Введите площадь квартиры: ";
    std::cin >> area;
    std::cout << "Введите цену квартиры: ";
    std::cin >> price;
    std::cin.ignore();
}

double Flat::getArea() const { return area; }
double Flat::getPrice() const { return price; }
void Flat::setArea(double a) { area = a; }
void Flat::setPrice(double p) { price = p; }
int Flat::getObjectCount() { return objectCount; }