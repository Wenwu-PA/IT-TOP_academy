#include <iostream>

int main()
{
    int TSeconds{};
    int hours{};

    std::cout << "Enter time in seconds: ";
    std::cin >> TSeconds;
    
    hours = (28800 - TSeconds) / 3600;

    std::cout << "Hours untill the end of working day: " << hours << "\n";

    return 0;
}