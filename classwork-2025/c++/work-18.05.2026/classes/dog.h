#include "animal.h"

class Dog: public Animal{

public:
    Dog(char* t): Animal {t}
    virtual void speak(){
        std::cout << title << " say " << "gav-gav\n";
    };
};