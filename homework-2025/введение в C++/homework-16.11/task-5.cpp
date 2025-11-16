#include <iostream>


bool is_happy(int number)
{
    int sum1{};
    int sum2{};


    for(int i{}; i < 6; i++)
    {

        if(i <= 2)
            sum1 += number % 10;
        else
            sum2 += number % 10;
        number /= 10; 
    }
        
    return sum1 == sum2;
}

int main()
{
    int num{};
    std::cout << "Введите 6-значное число: ";
    std::cin >> num;

    if(is_happy(num))
        std::cout << num << " - счастливое число!\n";
    else
        std::cout << num << " - не счастливое число...\n";

    return 0;
}