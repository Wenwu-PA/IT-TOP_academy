#include <iostream>

int main()
{
    double distance{}, 
    double time{}, 
    double speed{};
    
    std::cout << "Enter distance (km): ";
    std::cin >> distance;

    std::cout << "Enter time (min): ";
    std::cin >> time;
    
    speed = distance / (time / 60);

    std::cout << "Speed: "<< speed << " km/h" << "\n";

    return 0;
}