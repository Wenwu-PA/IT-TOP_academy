#include <iostream>
#include <cstdio>

int main(){
    FILE*myfile;
    myfile = fopen("./data.txt","w");
    if (!myfile){
        std::cout << "output";
        return 1;

    }

    std::cout << "close file eccept\n";
    // while (true){
    //     int num{ fprintf(myfile,"Artemii Артемий")};
        
    // }
    int num{ fprintf(myfile,"Artemii Артемий")};
    if(num < 0){
        std::cout << "warning!";
        return 1;
    }
    std::cout << "byte " << num << '\n';

    int success(fclose(myfile));
    if(success != 0){
        std::cout << "!warning\n";
        return 1;
    }
    std::cout << "success\n";

    return 0;
}