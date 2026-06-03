#include "animal.h"

class Cat: public Animal{

public:
    Cat(char* t): Animal {t}
    virtual void speak(int when){
        std::cout << title << " say " << "mau-mau\n";
    };
};