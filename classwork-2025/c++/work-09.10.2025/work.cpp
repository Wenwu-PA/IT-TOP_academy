#include <iostream>

// int main()
// {
//     int a{},b{};
//     std::cout << "input a, b = ";
//     std::cin >> a >> b;

//     bool ab{ a < b };

//     bool or{ (a < 10) && (a > 1)};

//     std::cout << "a < b = " << ab << "\n\n" << "(a < 10) && (a > 1) = " << or;
//     std::cout << !true << "\n";

//     return 0;
// }

int main()
{
    int a{},b{},x{0};
    std::cout << "input a, b = ";
    std::cin >> a >> b;
    if (a == b)
    {
        std::cout << "True \n";
    }
    else
    {
        std::cout << "False :( \n";
    }

    // if (x++)
    // {
    //     std::cout << "True \n";
    // }
    // else
    // {
    //     std::cout << "False :(";
    // }

    if (a = b)
    {
        std::cout << "True \n";
    }
    else
    {
        std::cout << "False :(\n";
    }
}