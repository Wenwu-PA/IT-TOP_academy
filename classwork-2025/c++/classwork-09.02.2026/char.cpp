#include <iostream>

struct tovar{
    char name[50];
    double num;
    char unit[10];
};

int main(){
    FILE* myfile;
    const int size{3};
    tovar tovars[size]{
        {"apple",100,"кг"},
        {"pc",100,"item"},
        {"tomate",100,"kg"}

    };
    myfile = fopen("products.txt","a");
    for(int i{};i<size;i++){
        fprintf(myfile,"%s ",tovars[i].name);
        fprintf(myfile,"%.3f", tovars[i].num);
        fprintf(myfile,"%s\n",tovars[i].unit);
    }

    return 0;
}
