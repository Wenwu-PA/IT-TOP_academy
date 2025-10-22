#include <iostream>

int main()
{
    int res{};
    int num{};

    std::cout << "input number: ";
    std::cin >> num;

    for(int i{num}; i < 500; i++)
    {
        res += i;
    }

    std::cout << "Output: "<< res << "\n";

    return 0;
}