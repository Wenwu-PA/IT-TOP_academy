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