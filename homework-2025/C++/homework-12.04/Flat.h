#ifndef FLAT_H
#define FLAT_H

#include <iostream>

class Flat {
private:
    double area;
    double price;
    static int objectCount;

public:
    Flat();
    Flat(double a, double p);
    Flat(const Flat& other);
    ~Flat();

    Flat& operator=(const Flat& other);
    bool operator==(const Flat& other) const;
    bool operator>(const Flat& other) const;

    void display() const;
    void input();

    double getArea() const;
    double getPrice() const;
    void setArea(double a);
    void setPrice(double p);

    static int getObjectCount();
};

#endif