#include "animal.h"

class Frog: public Animal{

public:
    Frog(char* t): Animal {t}
    virtual void speak(){
        std::cout << title << " say " << "kva-vka\n";
    };
};