#include <iostream>

int main()
{
    int UsOp;
    int CompOp;
    int CMin;

    float minOutKS; 
    float minOutV;
    float minOutLC;

    minOutKS = 2;
    minOutV = 3;
    minOutLC=2.5;
    std::cout << "с какого оператора вы звоните?\n";
    std::cout << "1- Севофония\n";
    std::cout << "2- кристолайн\n";
    std::cout << "3- трифоник\n\n";
    std::cin >> UsOp;
    std::cout << "а какой оператор у твоего аппонента?\n";
    std::cout << "1- Севофония\n";
    std::cout << "2- кристолайн\n";
    std::cout << "3- трифоник\n\n";
    std::cin >> CompOp;;
    std::cout << "сколько вы общались со своим братишкой?:\n";
    std::cin >> CMin;
    if (UsOp == CMin)
    {
        std::cout << "денег брать не за что";
    }
    else
    { switch(CMin){
        case 1:
            std::cout << "Стоимость звонка - " << CMin* minOutKS;
            break;
        case 2:
            std::cout << "Стоимость звонка  - " << CMin * minOutV;
            break;
        case 3:
            std::cout << "Стоимость звонка  - " << CMin * minOutLC;
            break;
        default:
            std::cout << "ошибочка(!";
            break;
    }
    return 0;
    }
}