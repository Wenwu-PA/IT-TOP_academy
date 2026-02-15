#include <iostream>

int main()
{
    int dist1{};
    int dist2{};
    int weight{};
    int FCap{300};
    int minF{};
    int FCons{};
    
    std::cout << "Введите расстояние между A и B (км): ";
    std::cin >> dist1;
    std::cout << "Введите расстояние между точками B и C (км): ";
    std::cin >> dist2;
    std::cout << "Введите вес (кг): ";
    std::cin >> weight;

    if(weight < 500)
    {
        FCons = 1;
        if(FCons * dist1 <= FCap && FCons * dist2 <= FCap)
        {
            if(FCap - FCons * dist1 <= FCons * dist2)
            {
                minF = (FCons * dist2) - (FCap - FCons * dist1);
            }
        }
        else
        {
            std::cout << "Недостаточно запаса топлива для такого расстояния!\n";
            return 0;
        }
    }
    else if(weight < 1000)
    {
        FCons = 4;
        if(FCons * dist1 <= FCap && FCons * dist2 <= FCap)
        {
            if(FCap - FCons * dist1 <= FCons * dist2)
            {
                minF = (FCons * dist2) - (FCap - FCons * dist1);
            }
        }
        else
        {
            std::cout << "Недостаточно запаса топлива для такого расстояния!\n";
            return 0;
        }
    }
    else if(weight < 1500)
    {
        FCons = 7;
        if(FCons * dist1 <= FCap && FCons * dist2 <= FCap)
        {
            if(FCap - FCons * dist1 <= FCons * dist2)
            {
                minF = (FCons * dist2) - (FCap - FCons * dist1);
            }
        }
        else
        {
            std::cout << "Недостаточно запаса топлива для такого расстояния!\n";
            return 0;
        }
    }
    else if(weight < 2000)
    {
        FCons = 9;
        if(FCons * dist1 <= FCap && FCons * dist2 <= FCap)
        {
            if(FCap - FCons * dist1 <= FCons * dist2)
            {
                minF = (FCons * dist2) - (FCap - FCons * dist1);
            }
        }
        else
        {
            std::cout << "Недостаточно запаса топлива для такого расстояния!\n";
            return 0;
        }
    }
    else
    {
        std::cout << "Слишком большой вес!\n";
        return 0;
    }

    std::cout << "Минимальное количество топлива для заправки составляет: " << minF << "\n";

    return 0;
}