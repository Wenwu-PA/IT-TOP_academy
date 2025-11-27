#include <iostream>

double pow(int a, int b);

int main()
{
    int a{};
    int b{};

    std::cout << "Введите число и степень (a b): ";
    std::cin >> a >> b;

    std::cout << "Результат: " << pow(a, b) << "\n";

    return 0;
}

double pow(int a, int b)
{
    double res{1};

    if(b > 0)
    {    
        for(int i{1}; i <= b; i++)
            res *= a;
    }
    else if ((b < 0) && (a == 0))
    {
        std::cout << "Нельзя возводить ноль в отрицательную степень! ";
        return 0;
    }
    else if((b < 0) && (a > 0))
    {    
        for(int i{1}; i <= -b; i++)
            res *= 1.0 / a;
    }
    else if ((a < 0) && (b < 0))
    {
        for(int i{1}; i <= -b; i++)
            res *= 1.0 / -a;
        res = -res;
    }

    return res;
}