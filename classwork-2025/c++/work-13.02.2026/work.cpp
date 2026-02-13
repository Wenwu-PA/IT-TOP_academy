#include <iostream>

struct tovar{
    char name[50];
    double num;
    char unit[10];
};

int main(){
    FILE* myfile;
    const int size{3};
    tovar tovars[size]{};
    myfile = fopen("tovars.txt","r");
    for(int i{};i<size;i++){
        fscanf(myfile,"%s %lf %s\n",tovars[i].name, &(tovars[i].num), tovars[i].unit); 
        std::cout << tovars[i].name << " " << tovars[i].num << " " << tovars[i].unit << "\n";
    }

    return 0;
}