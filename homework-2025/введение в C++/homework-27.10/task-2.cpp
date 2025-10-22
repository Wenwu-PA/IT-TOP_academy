#include <iostream>

int main()
{
    int x{};
    int y{};

    std::cout << "Input x and y: ";
    std::cin >> x >> y;
    
    int res{x};

    for(int i{1}; i < y; i++)
    {
        res *= x;
    }

    std::cout << "Output: " << res << "\n";

    return 0;
}