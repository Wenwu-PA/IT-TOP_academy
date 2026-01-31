#include <iostream>
struct date {
    int day;
    int month;
    int year;

};
int main(){
    date day{10,12,2025};
    date* pd{&day};
    std::cout << pd -> day << "." << pd -> month << "." << pd -> year << '\n';

}

date create_date(int day, int month, int year){
    return {day,month,year};
}