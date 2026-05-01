#ifndef BUILDING_H
#define BUILDING_H
#include "Apartment.h"

class Building {
private:
    Apartment* apartments;
    int floorCount;
    int apartmentsPerFloor;
    int totalApartments;

public:
    Building(int floors, int aptsPerFloor) : floorCount(floors), apartmentsPerFloor(aptsPerFloor) {
        totalApartments = floors * aptsPerFloor;
        apartments = new Apartment[totalApartments];
    }

    Building(const Building& other) : floorCount(other.floorCount), apartmentsPerFloor(other.apartmentsPerFloor), totalApartments(other.totalApartments) {
        apartments = new Apartment[totalApartments];
        for (int i = 0; i < totalApartments; i++) {
            apartments[i] = other.apartments[i];
        }
    }

    ~Building() {
        delete[] apartments;
    }

    Apartment* getApartment(int floor, int aptNumber) {
        int index = (floor - 1) * apartmentsPerFloor + (aptNumber - 1);
        if (index < 0 || index >= totalApartments) return nullptr;
        return &apartments[index];
    }

    void addResidentToApartment(int floor, int aptNumber, const Human& h) {
        Apartment* apt = getApartment(floor, aptNumber);
        if (apt) {
            apt->addResident(h);
        } else {
            std::cout << "Неверный номер квартиры!" << std::endl;
        }
    }

    void display() const {
        std::cout << "\n=== Дом: " << floorCount << " этажей, " << apartmentsPerFloor << " квартир на этаже ===" << std::endl;
        for (int i = 0; i < totalApartments; i++) {
            int floor = i / apartmentsPerFloor + 1;
            int aptNum = i % apartmentsPerFloor + 1;
            std::cout << "\n--- Квартира " << floor << "-" << aptNum << " ---" << std::endl;
            apartments[i].display();
        }
    }
};
#endif // BUILDING_H