#include <iostream>

int main()
{
    int days{}, 
    int weeks{};

    std::cout << "Enter number of days: ";
    std::cin >> days;

    weeks = days / 7;
    days %= 7;

    std::cout << "Weeks " << weeks << " Days " << days << "\n";

    return 0;
}