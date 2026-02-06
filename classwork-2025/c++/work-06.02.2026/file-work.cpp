#include <iostream>
#include <cstdio>

int main(){
    FILE*myfile;
    myfile = fopen("data.txt","w");
    if (!myfile){
        std::cout << "output";
        return 1;

    }
    std::cout << "success\n";
    int success(fclose(myfile));
    if(success != 0){
        std::cout << "!warning\n";
        return 1;
    }

    std::cout << "close file eccept\n";

    return 0;
}