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
    myfile = fopen("products.dat","rb");
    for(int i{};i<size;i++){
        fread(tovars[i].name,50,1,myfile);
        fread(&(tovars[i].num),sizeof(double),1,myfile);
        fread(tovars[i].unit,10,1,myfile);
        std::cout << tovars[i].name << " " << tovars[i].num << " " << tovars[i].unit << "\n";
    }

    return 0;
}