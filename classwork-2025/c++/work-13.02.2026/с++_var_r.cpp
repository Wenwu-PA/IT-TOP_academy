#include <iostream>
#include <fstream>

struct tovar{
    char name[50];
    double amount;
    char unit[10];
};

int main(){
    std::fstream fout("products.txt");
    const int size{3};
    tovar products[size]{};
    for (int i{};i < size;i++){
        fout >> products[i].name >> products[i].amount >> products[i].unit;
        std::cout << products[i].name << " " << products[i].amount << " " << products[i].unit << "\n";
    }
    fout.close();

    return 0;
}