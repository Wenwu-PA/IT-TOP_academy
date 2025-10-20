#include <iostream>

int main()
{
    int a{}; int b{};
    std::cout << "input a,  ";
    std::cin >> a >> b;
    double ab{ a < b };
    std::cout << "a < b = " << ab;

    return 0;
}