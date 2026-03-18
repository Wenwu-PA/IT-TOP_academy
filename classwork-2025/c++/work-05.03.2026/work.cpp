#include <iostream>
#include "Student.h"

int main(){

    
    //group students array
    const int NUM_STUD{3};
    Student group[NUM_STUD]{};

    for(int i{}; i < NUM_STUD; i++){
        group[i].input();
    }

    for(int i{}; i < NUM_STUD; i++){
        group[i].print();
        std::cout << '\n';
    }

    return 0;
}