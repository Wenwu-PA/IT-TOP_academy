#include <iostream>

struct DateTime{
    unsigned short DayNum: 5;
    unsigned short MonthNum: 4;
    unsigned short YearNum: 7;
    unsigned short HourNum: 5;
    unsigned short MinuteNum: 6;
    unsigned short SecondNum: 6;
    
};

int main(){

    DateTime d{};
    int i{};
    std::cout << "input date and time: " << '\n';
    std::cin >> i;
    d.YearNum = i;
    std::cin >> i;
    d.MonthNum = i;
    std::cin >> i;
    d.DayNum = i;
    std::cin >> i;
    d.HourNum = i;
    std::cin >> i;
    d.MinuteNum = i;
    std::cin >> i;
    d.SecondNum = i;
    std::cout << "date: "<< d.YearNum << "." << d.MonthNum << "." << d.DayNum  << ":" << d.HourNum << "." << d.MinuteNum << "."<< d.SecondNum;


    return 0;
    
}