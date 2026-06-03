#include <iostream>
#include "classes/animal.h"
#include "classes/cat.h"
#include "classes/dog.h"
#include "classes/lion.h"
#include "classes/frog.h"
int main(){
    const int numAnimals{4};
    Animal* animals[numAnimals]{
        new Frog{"Evgeny"},
        new Cat{"Gosha"},
    }
}