#include "Reservoir.h"
#include <cstring>
#include <cmath>

const char* typeToString(ReservoirType type) {
    switch(type) {
        case SEA: return "Море";
        case LAKE: return "Озеро";
        case POND: return "Пруд";
        case POOL: return "Бассейн";
        case RIVER: return "Река";
        default: return "Неизвестно";
    }
}

int Reservoir::objectCount = 0;

Reservoir::Reservoir() : type(LAKE), width(0), length(0), maxDepth(0) {
    name = new char[1];
    name[0] = '\0';
    objectCount++;
}

Reservoir::Reservoir(const char* name) : type(LAKE), width(0), length(0), maxDepth(0) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    objectCount++;
}

Reservoir::Reservoir(const char* name, ReservoirType type, double width, double length, double maxDepth)
    : type(type), width(width), length(length), maxDepth(maxDepth) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    objectCount++;
}

Reservoir::Reservoir(const Reservoir& other)
    : type(other.type), width(other.width), length(other.length), maxDepth(other.maxDepth) {
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);
    objectCount++;
}

Reservoir::~Reservoir() {
    delete[] name;
    objectCount--;
}

Reservoir& Reservoir::operator=(const Reservoir& other) {
    if (this != &other) {
        delete[] name;
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        type = other.type;
        width = other.width;
        length = other.length;
        maxDepth = other.maxDepth;
    }
    return *this;
}

const char* Reservoir::getName() const { return name; }
ReservoirType Reservoir::getType() const { return type; }
double Reservoir::getWidth() const { return width; }
double Reservoir::getLength() const { return length; }
double Reservoir::getMaxDepth() const { return maxDepth; }

void Reservoir::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

void Reservoir::setType(ReservoirType type) { this->type = type; }
void Reservoir::setWidth(double width) { this->width = width; }
void Reservoir::setLength(double length) { this->length = length; }
void Reservoir::setMaxDepth(double maxDepth) { this->maxDepth = maxDepth; }

double Reservoir::calculateVolume() const {
    return width * length * maxDepth;
}

double Reservoir::calculateSurfaceArea() const {
    return width * length;
}

bool Reservoir::sameType(const Reservoir& other) const {
    return this->type == other.type;
}

bool Reservoir::compareSurfaceArea(const Reservoir& other) const {
    if (!sameType(other)) {
        std::cout << "Водоемы разных типов! Сравнение невозможно." << std::endl;
        return false;
    }
    return this->calculateSurfaceArea() > other.calculateSurfaceArea();
}

void Reservoir::copyFrom(const Reservoir& other) {
    *this = other;
}

void Reservoir::display() const {
    std::cout << "\n=== Водоем ===" << std::endl;
    std::cout << "Название: " << name << std::endl;
    std::cout << "Тип: " << typeToString(type) << std::endl;
    std::cout << "Ширина: " << width << " м" << std::endl;
    std::cout << "Длина: " << length << " м" << std::endl;
    std::cout << "Максимальная глубина: " << maxDepth << " м" << std::endl;
    std::cout << "Площадь поверхности: " << calculateSurfaceArea() << " кв.м" << std::endl;
    std::cout << "Приблизительный объем: " << calculateVolume() << " куб.м" << std::endl;
}

void Reservoir::input() {
    char buffer[200];
    int typeChoice;

    std::cout << "Введите название водоема: ";
    std::cin.getline(buffer, 200);
    setName(buffer);

    std::cout << "Выберите тип водоема:" << std::endl;
    std::cout << "0 - Море" << std::endl;
    std::cout << "1 - Озеро" << std::endl;
    std::cout << "2 - Пруд" << std::endl;
    std::cout << "3 - Бассейн" << std::endl;
    std::cout << "4 - Река" << std::endl;
    std::cout << "Ваш выбор: ";
    std::cin >> typeChoice;
    setType(static_cast<ReservoirType>(typeChoice));

    std::cout << "Введите ширину (м): ";
    std::cin >> width;
    std::cout << "Введите длину (м): ";
    std::cin >> length;
    std::cout << "Введите максимальную глубину (м): ";
    std::cin >> maxDepth;
    std::cin.ignore();
}

int Reservoir::getObjectCount() {
    return objectCount;
}