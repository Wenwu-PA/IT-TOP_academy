#include <iostream>

int main()
{
    double percent{}, 
    double monthPercent{}, 
    double monthSum{}, 
    double sum{};

    std::cout << "Enter deposit amount: ";
    std::cin >> sum;
    std::cout << "Enter percent: ";
    std::cin >> percent;

    monthPercent = percent / 12;
    std::cout << "Monthly percanet: " << monthPercent << "\n";

    std::cout << "Monthly profit: ";
    std::cout << "Deposit status: \n";
    for(int i = 0; i < 12; i++)
        {
            monthSum = sum / 100 * monthPercent;
            std::cout << monthSum << "\t\t";
            sum += monthSum;
            std::cout << sum << "\n";
        }

    return 0;
}