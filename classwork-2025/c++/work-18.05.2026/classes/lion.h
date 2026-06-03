#include "animal.h"

class Lion: public Animal{

public:
    Lion(char* t): Animal {t}
    virtual void speak(){
        std::cout << title << " say " << "Leon\n";
    };
};