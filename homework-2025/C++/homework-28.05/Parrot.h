#ifndef PARROT_H
#define PARROT_H

#include "Animal.h"

class Parrot : public Animal {
public:
    Parrot(const std::string& name);
};

#endif