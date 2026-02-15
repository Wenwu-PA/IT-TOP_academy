#include <iostream>

int main()
{
    int seconds{}, 
    int minutes{}, 
    int hours{};
    
    std::cout << "Enter time in seconds: ";
    std::cin >> seconds;
    
    minutes = seconds / 60;
    seconds %= 60;
    hours = minutes / 60;
    minutes %= 60;
    

    std::cout << hours << ":" << minutes << ":" << seconds << "\n";

    return 0;
}