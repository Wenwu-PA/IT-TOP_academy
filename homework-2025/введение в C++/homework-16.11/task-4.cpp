#include <iostream>

void print_card(int value, int suit);

int main() {
    std::cout << "ЗНАЧЕНИЯ\n"
              << "2-10 - цифры\n"
              << "11 - Валет\n"
              << "12 - Дама\n"
              << "13 - Король\n"
              << "14 - Туз\n"
              << "МАСТИ\n"
              << "0 - Пики\n"
              << "1 - Червы\n"
              << "2 - Бубны\n"
              << "3 - Трефы\n"
              << "Введите значение и масть карты: ";

    int suit{};
    int value{};

    std::cin >> value >> suit;

    print_card(value, suit);

    return 0;
}

void print_card(int value, int suit) {
    
    char suits[] = {'S', 'H', 'D', 'C'}; 
    char values[] = {' ',' ', '2','3','4','5','6','7','8','9',' ','J','Q','K','A'};
    
    char card_suit = suits[suit];
    
    if(value != 10)
    {
        char card_value = values[value];

        std::cout << "┌─────────┐\n"
                  << "│ " << card_value << card_suit << "      │\n"
                  << "│         │\n"
                  << "│    " << card_suit << "    │\n"
                  << "│         │\n"
                  << "│      " << card_value << card_suit << " │\n"
                  << "└─────────┘\n";
    }
    else
    {
        std::cout << "┌─────────┐\n"
                  << "│ " << 10 << card_suit << "     │\n"
                  << "│         │\n"
                  << "│    " << card_suit << "    │\n"
                  << "│         │\n"
                  << "│     " << 10 << card_suit << " │\n"
                  << "└─────────┘\n";    
    }
}