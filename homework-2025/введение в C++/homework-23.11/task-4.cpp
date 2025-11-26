#include <iostream>
#include <string>

int main() {
    double exchange_rate[12];
    double interest[12];
    double deposit;
    
    std::cout << "Введите сумму депозита в евро: ";
    std::cin >> deposit;
    
    std::string months[12] = {"январь", "февраль", "март", "апрель", "май", "июнь",
                             "июль", "август", "сентябрь", "октябрь", "ноябрь", "декабрь"};
    
    std::cout << "Введите курс доллара к евро за каждый месяц:" << std::endl;
    for (int i = 0; i < 12; i++) {
        std::cout << months[i] << ": ";
        std::cin >> exchange_rate[i];
    }
    
    std::cout << "Введите начисленные проценты за каждый месяц (в евро):" << std::endl;
    for (int i = 0; i < 12; i++) {
        std::cout << months[i] << ": ";
        std::cin >> interest[i];
    }
    
    int month;
    std::cout << "Введите номер месяца (1-12): ";
    std::cin >> month;
    
    if (month < 1 || month > 12) {
        std::cout << "Неверный номер месяца" << std::endl;
        return 1;
    }
    
    int index = month - 1;
    double interest_usd = interest[index] * exchange_rate[index];
    
    if (interest_usd >= 500) {
        double available = interest[index] * 0.5;
        double available_usd = available * exchange_rate[index];
        std::cout << "Доступная сумма для снятия: " << available_usd << " долларов" << std::endl;
    } else {
        std::cout << "Начисленная сумма менее 500$, снятие невозможно" << std::endl;
    }
    
    return 0;
}