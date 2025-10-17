#include <iostream>

int main() 
{
    int seconds1{}, 
    int minutes1{}, 
    int hours1{};
    int seconds2{}, 
    int minutes2{}, 
    int hours2{};
    int time{}, 
    int time1{}, 
    int time2{};
    double cost{}, 
    double price{};

    std::cout << "Enter start time (hours minutes seconds): ";
    std::cin >> hours1 >> minutes1 >> seconds1;

    std::cout << "Enter end time (hours minutes seconds): ";
    std::cin >> hours2 >> minutes2 >> seconds2;

    std::cout << "Enter price (rub/min): ";
    std::cin >> price;
    
    time1 = hours1 * 60 + minutes1 + seconds1 / 60;
    time2 = hours2 * 60 + minutes2 + seconds2 / 60;
    time = time2 - time1;
    cost = time * price;
    
    std::cout << "Total cost: "<< cost << " rub" <<"\n";

    return 0;
}