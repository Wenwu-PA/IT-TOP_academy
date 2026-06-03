#include <iostream>
#include <cstring>

int main(){
    char* str{"Артемий"};
    for (int i{}; i < strlen(str); i++){
        std::cout << (int)str[i] << " ";
    }
}