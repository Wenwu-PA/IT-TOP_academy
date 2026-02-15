#include <iostream>

int main() {
    float coffeePrice = 2.5f;
    float teaPrice = 1.8f;
    float juicePrice = 3.0f;
    float croissantPrice = 2.2f;
    float cakePrice = 4.5f;
    float cookiePrice = 1.5f;
    
    int peopleCount = 0;
    std::cout << "На сколько человек заказ? ";
    std::cin >> peopleCount;
    
    float totalSum = 0.0f;
    
    for (int person = 1; person <= peopleCount; person++) {
        std::cout << "\n--- Заказ для человека " << person << " ---\n";
        float personSum = 0.0f;
        int choice = 0;
        
        do {
            std::cout << "МЕНЮ:\n";
            std::cout << "1 - Кофе $" << coffeePrice << "\n";
            std::cout << "2 - Чай $" << teaPrice << "\n";
            std::cout << "3 - Сок $" << juicePrice << "\n";
            std::cout << "4 - Круассан $" << croissantPrice << "\n";
            std::cout << "5 - Торт $" << cakePrice << "\n";
            std::cout << "6 - Печенье $" << cookiePrice << "\n";
            std::cout << "0 - Закончить заказ этого человека\n";
            std::cout << "Выберите пункт: ";
            std::cin >> choice;
            
            switch (choice) {
                case 1:
                    personSum += coffeePrice;
                    break;
                case 2:
                    personSum += teaPrice;
                    break;
                case 3:
                    personSum += juicePrice;
                    break;
                case 4:
                    personSum += croissantPrice;
                    break;
                case 5:
                    personSum += cakePrice;
                    break;
                case 6:
                    personSum += cookiePrice;
                    break;
                case 0:
                    break;
                default:
                    std::cout << "Неверный выбор!\n";
            }
            
            if (choice != 0) {
                std::cout << "Текущая сумма: $" << personSum << "\n\n";
            }
            
        } while (choice != 0);
        
        totalSum += personSum;
        std::cout << "Итого для человека " << person << ": $" << personSum << "\n";
    }
    
    std::cout << "\n=== ОБЩИЙ ЗАКАЗ ===\n";
    std::cout << "Общая сумма: $" << totalSum << std::endl;
    
    return 0;
}