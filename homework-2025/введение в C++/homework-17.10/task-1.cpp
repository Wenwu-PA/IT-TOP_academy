#include <iostream>

int main()
{
    int TSec{};
    int hours{};
    int h_mid{};
    int min{};
    int min_mid{};
    int sec{};
    int sec_mid{};
    int temp{};

    std::cout << "Enter current time in seconds: ";
    std::cin >> TSec;

    hours = TSec / 3600;
    temp = TSec % 3600;
    min = temp / 60;
    sec = temp % 60;
    temp = 86400 - TSec;
    h_mid = temp / 3600;
    temp = temp % 3600;
    min_mid = temp / 60;
    sec_mid = temp % 60;

    std::cout << "Current time: " << hours<< ":" << min << ":" << sec << "\n";
    std::cout << "Time midnight left: " << h_mid << ":" << min_mid << ":" << sec_mid << "\n";

    return 0;
}