#include <iostream>
// Что за безумие творится в решение этой задачи котрое прикреплено к дз? От такого ужаса надо избавляться

int main()
{
    
    int numbers [7] {};
    int max{};

     for(int i = 0; i < 7; i++)
    {
        std::cout << "Введите число: " << i+1 << ": ";
        std::cin >> numbers[i];
    }
    
    for(int i = 0; i < 7; i++)
    {
        if(numbers[i] > max)
        {
            max = numbers[i];
        }
    }

    std::cout << "Максимальное количество: " << max << "\n";

    return 0;
}