#include <iostream>

int main() 
{
    double money{};
    int dollars{}, 
    int cents{};

    std::cout << "Enter money amount (dollars.cents): ";
    std::cin >> money;
    dollars = money;
    cents = (money - dollars) * 100;

    std::cout << dollars << " dollars " << cents << " cents" << "\n";

    return 0;
}