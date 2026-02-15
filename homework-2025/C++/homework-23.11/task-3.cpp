#include <iostream>
#include <string>

int main() {
    double expenses[7];
    std::string days[7] = {"понедельник", "вторник", "среда", "четверг", "пятница", "суббота", "воскресенье"};
    
    std::cout << "Введите расходы за неделю (в долларах):" << std::endl;
    for (int i = 0; i < 7; i++) {
        std::cout << days[i] << ": ";
        std::cin >> expenses[i];
    }
    
    double total = 0;
    for (int i = 0; i < 7; i++) {
        total += expenses[i];
    }
    
    double average = total / 7;
    
    std::cout << "Общая сумма за неделю: " << total << " долларов" << std::endl;
    std::cout << "Средняя сумма в день: " << average << " долларов" << std::endl;
    
    std::cout << "Дни с расходом более 100 долларов: ";
    int count = 0;
    for (int i = 0; i < 7; i++) {
        if (expenses[i] > 100) {
            count++;
            std::cout << days[i] << " ";
        }
    }
    std::cout << std::endl;
    std::cout << "Количество дней с расходом более 100 долларов: " << count << std::endl;
    
    return 0;
}