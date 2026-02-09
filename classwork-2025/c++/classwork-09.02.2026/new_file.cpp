#include <iostream>
#include <cstdio>

int main(){
    FILE*myfile;
    myfile = fopen("./data.txt","r");
    if (!myfile){
        std::cout << "warning";
        return 1;

    }
    const int size{256};
    char str[size];
    // int res{};
    // while (res  = fscanf(myfile,"%s",str)>0){
    //     std::cout << str << '\t';
    // }

    // while (fgets(str,size,myfile)!=nullptr){
    //     std::cout << "reading file..." << str;
    // }
    // std::cout << '\n';

    char sym{};
    while ((sym = fgetc(myfile))!=EOF){
        std::cout << sym;
    }
    std::cout << '\n';

    int success(fclose(myfile));
    if(success != 0){
        std::cout << "!warning\n";
        return 1;
    }
    std::cout << "success\n";

    return 0;
}