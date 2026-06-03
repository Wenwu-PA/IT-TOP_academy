#include <cstring>


class Animal{

protected:
    char title[20];
public:
    Animal(char *t)
    {
        std::strcpy(title,t);
    };
    virtual void speak() = 0; // нет реализации (только виртуал)

};