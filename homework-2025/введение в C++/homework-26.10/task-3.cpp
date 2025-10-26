#include <iostream>

int main()
{
    int desiredIncome = 0;
    int lateCount = 0;
    int codeLines = 0;
    int penaltyAmount = 0;
    int menuChoice = 0;
    float pricePerLine = 0.5f;
    float temporaryCalculation = 0.0f;
    
    std::cout << "Выберите пункт меню:\n";
    std::cout << "1 - доход и количество опозданий -> количество строк кода\n";
    std::cout << "2 - доход и количество строк кода -> количество опозданий\n";
    std::cout << "3 - количество опозданий и количество строк кода -> доход\n";
    std::cin >> menuChoice;
    
    switch (menuChoice)
    {
    case 1:
    {
        std::cout << "Введите желаемый доход: ";
        std::cin >> desiredIncome;
        std::cout << "Сколько раз пользователь опоздал? ";
        std::cin >> lateCount;
        
        codeLines = desiredIncome / pricePerLine;
        
        if (lateCount >= 3)
        {
            penaltyAmount = lateCount / 3 * 20;
            codeLines = codeLines + penaltyAmount / pricePerLine;
        }
        
        std::cout << "Количество строк кода: " << codeLines << std::endl;
        break;
    }
    case 2:
    {
        std::cout << "Введите желаемый доход: ";
        std::cin >> desiredIncome;
        std::cout << "Введите количество строк кода: ";
        std::cin >> codeLines;
        
        temporaryCalculation = codeLines * pricePerLine;
        
        if (desiredIncome >= temporaryCalculation)
        {
            std::cout << "Вам нельзя опаздывать!";
        }
        else
        {
            lateCount = (temporaryCalculation - desiredIncome) / 20 * 3;
            std::cout << "Вам разрешено опаздывать ";
            std::cout << lateCount << " или " << lateCount + 1;
            std::cout << " или " << lateCount + 2 << " раз(а)";
        }
        break;
    }
    case 3:
    {
        std::cout << "Введите количество строк кода: ";
        std::cin >> codeLines;
        std::cout << "Сколько раз пользователь опоздал? ";
        std::cin >> lateCount;
        
        temporaryCalculation = codeLines * pricePerLine;
        
        if (lateCount >= 3)
        {
            penaltyAmount = lateCount / 3 * 20;
            if (penaltyAmount >= temporaryCalculation)
            {
                std::cout << "Вы ничего не получите\n";
            }
            else
            {
                desiredIncome = temporaryCalculation - penaltyAmount;
                std::cout << "Вы получите " << desiredIncome << "$\n";
            }
        }
        else
        {
            desiredIncome = temporaryCalculation;
            std::cout << "Вы получите " << desiredIncome << "$\n";
        }
        break;
    }
    default:
        std::cout << "Неверный ввод!";
    }
    
    return 0;
}