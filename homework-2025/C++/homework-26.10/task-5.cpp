#include <iostream>

int main()
{
    int ml1 = 0;
    int ml2 = 0;
    int ml3 = 0;
    int bestM = 0;
    int temp = 0;
    float salary1 = 0.0f;
    float salary2 = 0.0f;
    float salary3 = 0.0f;
    
    std::cout << "Введите уровень продаж 1 менеджера:\n";
    std::cin >> ml1;
    std::cout << "Введите уровень продаж 2 менеджера:\n";
    std::cin >> ml2;
    std::cout << "Введите уровень продаж 3 менеджера:\n";
    std::cin >> ml3;
    
    if (ml1 < 500)
    {
        salary1 = 200 + ml1 * 0.003f;
    }
    else if ((ml1 >= 500) && (ml1 < 1000))
    {
        salary1 = 200 + ml1 * 0.005f;
    }
    else
    {
        salary1 = 200 + ml1 * 0.008f;
    }
    
    if (ml2 < 500)
    {
        salary2 = 200 + ml2 * 0.003f;
    }
    else if ((ml2 >= 500) && (ml2 < 1000))
    {
        salary2 = 200 + ml2 * 0.005f;
    }
    else
    {
        salary2 = 200 + ml2 * 0.008f;
    }
    
    if (ml3 < 500)
    {
        salary3 = 200 + ml3 * 0.003f;
    }
    else if ((ml3 >= 500) && (ml3 < 1000))
    {
        salary3 = 200 + ml3 * 0.005f;
    }
    else
    {
        salary3 = 200 + ml3 * 0.008f;
    }
    
    if (ml1 > ml2)
    {
        bestM = 1;
        temp = ml1;
    }
    else
    {
        bestM = 2;
        temp = ml2;
    }
    
    if (ml3 > temp)
    {
        bestM = 3;
    }
    
    switch (bestM)
    {
    case 1:
        salary1 = salary1 + 200;
        break;
    case 2:
        salary2 = salary2 + 200;
        break;
    case 3:
        salary3 = salary3 + 200;
        break;
    }
    
    std::cout << "Лучший - " << bestM;
    std::cout << " менеджер. Премия начислена\n";
    std::cout << "Зарплата 1 менеджера: " << salary1;
    std::cout << "\n";
    std::cout << "Зарплата 2 менеджера: " << salary2;
    std::cout << "\n";
    std::cout << "Зарплата 3 менеджера: " << salary3;
    std::cout << "\n";
    
    return 0;
}