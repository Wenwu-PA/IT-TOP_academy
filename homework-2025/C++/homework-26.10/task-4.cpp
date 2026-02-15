#include <iostream>

int main()
{
    int pizzaID = 0;
    int drinkID = 0;
    int pizzaAmount = 0;
    int drinkAmount = 0;
    int temp = 0;
    float pizzaPrice1 = 6.75f;
    float pizzaPrice2 = 8.95f;
    float pizzaPrice3 = 14.5f;
    float pizzaPrice4 = 10.25f;
    float drinkPrice1 = 1.79f;
    float drinkPrice2 = 2.5f;
    float drinkPrice3 = 3.09f;
    float selPizPrice = 0.0f;
    float selDrPrice = 0.0f;
    float sumOrder = 0.0f;
    
    std::cout << "Выберите пиццу:\n";
    std::cout << "1 — Сырная пицца $" << pizzaPrice1 << "\n";
    std::cout << "2 — Гавайская пицца $" << pizzaPrice2 << "\n";
    std::cout << "3 — Пицца с курицей BBQ $" << pizzaPrice3 << "\n";
    std::cout << "4 — Пицца с морепродуктами $" << pizzaPrice4 << "\n";
    std::cin >> pizzaID;
    
    std::cout << "Введите количество выбранной пиццы:\n";
    std::cin >> pizzaAmount;
    
    std::cout << "Выберите напиток:\n";
    std::cout << "1 — Пепси (Бутылка 20 унций) $" << drinkPrice1 << "\n";
    std::cout << "2 — Аквафина (Бутылка 20 унций) $" << drinkPrice2 << "\n";
    std::cout << "3 — Апельсиновый Краш (1 литр) $" << drinkPrice3 << "\n";
    std::cin >> drinkID;
    
    std::cout << "Введите количество выбранного напитка:\n";
    std::cin >> drinkAmount;
    
    switch (pizzaID)
    {
    case 1:
        selPizPrice = pizzaPrice1;
        break;
    case 2:
        selPizPrice = pizzaPrice2;
        break;
    case 3:
        selPizPrice = pizzaPrice3;
        break;
    case 4:
        selPizPrice = pizzaPrice4;
        break;
    default:
        std::cout << "Извините, такой пиццы нет в меню\n";
        selPizPrice = 0;
        break;
    }
    
    switch (drinkID)
    {
    case 1:
        selDrPrice = drinkPrice1;
        break;
    case 2:
        selDrPrice = drinkPrice2;
        break;
    case 3:
        selDrPrice = drinkPrice3;
        break;
    default:
        std::cout << "Извините, такого напитка нет в меню\n";
        selDrPrice = 0;
        break;
    }
    
    temp = pizzaAmount;
    
    if (pizzaAmount >= 5)
    {
        std::cout << "Супер скидка для вас — каждая 5-я пицца бесплатно!\n";
        pizzaAmount = pizzaAmount - pizzaAmount / 5;
    }
    
    sumOrder = sumOrder + pizzaAmount * selPizPrice;
    
    if ((drinkAmount >= 3) && (selDrPrice > 2))
    {
        std::cout << "У вас есть скидка (15%) на напитки!\n";
        sumOrder = sumOrder + drinkAmount * selDrPrice * (1 - 0.15f);
    }
    else
    {
        sumOrder = sumOrder + drinkAmount * selDrPrice;
    }
    
    if (sumOrder > 50)
    {
        std::cout << "У вас есть скидка (20%) на весь заказ!\n";
        sumOrder = sumOrder * (1 - 0.2f);
    }
    
    std::cout << "Ваш заказ:\n";
    std::cout << "Пицца " << pizzaID << " - " << temp << " - $" << selPizPrice << "\n";
    std::cout << "Напиток " << drinkID << " - " << drinkAmount << " - $" << selDrPrice << "\n";
    std::cout << "Сумма: $" << sumOrder << "\n";
    std::cout << "Приятного аппетита!";
    
    return 0;
}