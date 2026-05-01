#ifndef APARTMENT_H
#define APARTMENT_H

#include "Human.h"

class Apartment {
private:
    Human* residents;
    int count;
    int capacity;

    void resize() {
        capacity *= 2;
        Human* newResidents = new Human[capacity];
        for (int i = 0; i < count; i++) {
            newResidents[i] = residents[i];
        }
        delete[] residents;
        residents = newResidents;
    }

public:
    Apartment() : count(0), capacity(2) {
        residents = new Human[capacity];
    }

    Apartment(const Apartment& other) : count(other.count), capacity(other.capacity) {
        residents = new Human[capacity];
        for (int i = 0; i < count; i++) {
            residents[i] = other.residents[i];
        }
    }

    ~Apartment() {
        delete[] residents;
    }

    void addResident(const Human& h) {
        if (count >= capacity) {
            resize();
        }
        residents[count] = h;
        count++;
    }

    void addResidentInteractive() {
        Human h;
        h.input();
        addResident(h);
    }

    void display() const {
        std::cout << "Квартира. Количество жильцов: " << count << std::endl;
        for (int i = 0; i < count; i++) {
            std::cout << "  " << i + 1 << ". ";
            residents[i].display();
        }
    }

    int getCount() const { return count; }
    Human* getResidents() const { return residents; }
};

#endif // APARTMENT_H