#include <iostream>
#include <cmath>

int main()
{
    int number{};
    int NNumber{};

    std::cout << "Введите четырехзначное число: ";
    std::cin >> number;

    if((number / 1000 < 1) | (number / 1000 > 9))
    {
        std::cout << "Неверный номер!\n";
        return 0;
    }
// по сути такой способ должен быть быстрее, чем решение прикрипленное в дз
    for(int i = 1; i < 5; i++)
    {
        if(i % 2 == 0)
        {
            NNumber += number % 10 * pow(10, i-1); // pow - возведение в степень
            number /= 10;
        }
        else
        {
            NNumber += number % 10 * pow(10, i+1);
            number /= 10;
        }
    }
    NNumber /= 10; 

    std::cout << "Новый номер: " << NNumber << "\n";

    return 0;
}