#include <iostream>

int compare(int x, int y)
{
    if (x > y)
        return 1;
    //std::cout << x << " is greater than " << y << '\n'; // case 1
    else if (x < y)
        ///std::cout << x << " is less than " << y << '\n'; // case 2
        return -1;
    else
        //std::cout << x << " is equal to " << y << '\n'; // case 3
        return 0;

}

int main()
{
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter another number: ";
    int y{};
    std::cin >> y;

    if (compare(x, y) > 0){
        std::cout << x << " is greater than " << y << '\n'; // case 1
    }
    else if (compare(x, y) < 0){
        std::cout << x << " is less than " << y << '\n'; // case 2
    }
    else 
        std::cout << x << " is equal to " << y << '\n'; // case 3


    return 0;
}