#include <iostream>
#include "person.h"

int main(){
    Person pers{"Volodya",17,1};
    Person pers_default;
    pers.print();
    pers_default.print();
}