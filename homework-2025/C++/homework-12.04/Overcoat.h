#ifndef OVERCOAT_H
#define OVERCOAT_H

#include <iostream>
#include <cstring>

class Overcoat {
private:
    char* type;
    double price;
    static int objectCount;

public:
    Overcoat();
    Overcoat(const char* t, double p);
    Overcoat(const Overcoat& other);
    ~Overcoat();

    Overcoat& operator=(const Overcoat& other);
    bool operator==(const Overcoat& other) const;
    bool operator>(const Overcoat& other) const;

    void display() const;
    void input();

    const char* getType() const;
    double getPrice() const;
    void setType(const char* t);
    void setPrice(double p);

    static int getObjectCount();
};

#endif