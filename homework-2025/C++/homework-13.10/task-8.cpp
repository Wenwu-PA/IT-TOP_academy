#include <iostream>

int main()
{
    double distance{}, 
    double consumption{}, 
    double price1{}, 
    double price2{}, 
    double price3{};

    std::cout << "Enter distnace (km): ";
    std::cin >> distance;

    std::cout << "Enter fuel consumption (l/100km): ";
    std::cin >> consumption;

    std::cout << "Enter price for 3 types of fuel (separating with space): ";
    std::cin >> price1 >> price2 >> price3;

    std::cout << "АИ-92\t" << "АИ-95\t" << "АИ-98" << "\n";
    std::cout << distance * price1 * consumption / 100 << "\t" << distance * price2 * consumption / 100 << "\t" << distance * price3 * consumption / 100 << "\n";

    return 0;
}