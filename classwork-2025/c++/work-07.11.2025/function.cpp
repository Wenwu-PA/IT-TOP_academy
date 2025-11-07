#include <iostream>

void second(){
    std::cout << "функция second\n";
}

void third(){
    
}
void first(){
    std::cout << "начало функции first\n";
    second();
    std::cout << "конец функции first\n";
}


void main(){

    first();

}