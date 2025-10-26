#include <iostream>

int main()
{
    long long int res{1};
    int number{};

    std::cout << "input a number: ";
    std::cin >> number;

    for(int i{number}; i <= 20; i++)
    {
        res *= i;
    }

    std::cout << "Output: " << res << "\n";

    return 0;
}