#include <iostream>
//структуры 


// создание свое структуры (бывают базовые структуры (типы) - int,bool, string и не базовые(свои созданные))
struct date {
    int day;
    int month;
    int year;

};

struct student{
    char name[10];
    char location[15];
    int age;
};
void menu_item(const int counts,char item){
    for (int i{0}; i < counts;i++){
        std::cout << item;
    }
    std::cout << '\n';
}

int main(){
    //объект структуры date
    date d; //без инициализации 
    date day{10,12,2025}; //с инициализацией
    menu_item(15,'-');
    student info{"Gosha","Vyborg", 17};
    std::cout << "|student:" << '\n';
    std::cout << "|" << "age:" << info.age << "\n" << "|" << "location:" << info.location << "\n" << "|" << "name:" <<  info.name << "\n";
    std::cout << "|" << "date:" << day.day << "." << day.month << "." << day.year << '\n';
    menu_item(15,'-');
    

    return 0;
}