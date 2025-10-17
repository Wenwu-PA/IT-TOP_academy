#include <iostream>

int main()
{
    int sum1{};
    int sum2{};
    int num{};

    std::cout << "Введите шестизначное число: ";
    std::cin >> num;

    if((num / 100000 < 1) | (num / 100000 > 9))
    {
        std::cout << "Неправильный номер!\n";
        return 1;
    }

    for(int i = 0; i < 6; i++)
    {
        if(i >= 3)
        {
            sum2 += num % 10;
            num /= 10;
        }
        else
        {
            sum1 += num % 10;
            num /= 10;
        }
    }

    if(sum1 == sum2)
    {
        std::cout << "Это счастливая цифра!\n" << sum1;
    }
    else
    {
        std::cout << "Это обычный номер...\n" << sum2;
    }

    return 0;
}