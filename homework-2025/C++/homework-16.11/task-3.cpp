#include <iostream>

bool is_perfect(int number);
void find_perfect(int a, int b);

int main()
{
    int a{};
    int b{};

    std::cout << "Введите диапазон (a b): ";
    std::cin >> a >> b;
    
    find_perfect(a, b);
 
    return 0;
}

void find_perfect(int a, int b)
{
    int flag{};
    if(a < b)
    {
        for(int i{a + 1}; i < b; i++)
            if(is_perfect(i))
            {
                std::cout << "Найдено совершенное число: " << i << "\n";
                flag = 1;
            }
    }
    else
    {
        for(int i{b + 1}; i < a; i++)
            if(is_perfect(i))
            {
                std::cout << "Найдено совершенное число: " << i << "\n";
                flag = 1;
            }
    }
    
    if(!flag)
        std::cout << "Совершенные числа не найдены...\n";
    else
        std::cout << "Больше совершенных чисел не найдено.\n";
}

bool is_perfect(int number)
{
    int sum{};
    
    for(int i{1}; i < number; i++)
        if(number % i == 0)
            sum += i;
    
    return sum == number;
}