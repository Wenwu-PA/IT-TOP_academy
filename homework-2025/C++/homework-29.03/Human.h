#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <cstring>

class Human {
private:
    char* fullName;
    int age;

public:
    Human() : fullName(nullptr), age(0) {
        fullName = new char[1];
        fullName[0] = '\0';
    }

    Human(const char* name, int a) : age(a) {
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
    }

    Human(const Human& other) : age(other.age) {
        fullName = new char[strlen(other.fullName) + 1];
        strcpy(fullName, other.fullName);
    }

    ~Human() {
        delete[] fullName;
    }

    void setFullName(const char* name) {
        delete[] fullName;
        fullName = new char[strlen(name) + 1];
        strcpy(fullName, name);
    }

    void setAge(int a) { age = a; }

    const char* getFullName() const { return fullName; }
    int getAge() const { return age; }

    void display() const {
        std::cout << "ФИО: " << fullName << ", Возраст: " << age << std::endl;
    }

    void input() {
        char buffer[200];
        std::cout << "Введите ФИО: ";
        std::cin.getline(buffer, 200);
        setFullName(buffer);
        std::cout << "Введите возраст: ";
        std::cin >> age;
        std::cin.ignore();
    }
};

#endif // HUMAN_H