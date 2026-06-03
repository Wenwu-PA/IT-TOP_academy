#include <iostream>
#include <queue>
#include <string>
#include <ctime>
#include <limits>

struct PrintJob {
    std::string user;
    int priority;    // 1 - высокий, 2 - средний, 3 - низкий
    time_t timestamp;
    
    // Для priority_queue: чем меньше priority, тем выше приоритет
    bool operator<(const PrintJob& other) const {
        return priority > other.priority;
    }
};

// Очистка буфера ввода
void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Функция для ввода целого числа с проверкой
int getIntInput(int min, int max, const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        if (std::cin >> value) {
            if (value >= min && value <= max) {
                clearInput();
                return value;
            } else {
                std::cout << "Ошибка: введите число от " << min << " до " << max << "\n";
            }
        } else {
            std::cout << "Ошибка: введите корректное число\n";
            clearInput();
        }
    }
}

int main() {
    std::priority_queue<PrintJob> printQueue;
    std::queue<PrintJob> statistics;
    int choice;
    
    std::cout << "===== Имитация очереди печати =====\n";
    std::cout << "1. Добавить задание\n";
    std::cout << "2. Выполнить печать\n";
    std::cout << "3. Показать статистику\n";
    std::cout << "4. Выход\n";
    
    while (true) {
        std::cout << "\nВыберите действие (1-4): ";
        
        if (!(std::cin >> choice)) {
            clearInput();
            std::cout << "Ошибка: введите число от 1 до 4\n";
            continue;
        }
        
        if (choice == 4) {
            std::cout << "Программа завершена. До свидания!\n";
            break;
        }
        
        if (choice < 1 || choice > 4) {
            std::cout << "Ошибка: выберите пункт от 1 до 4\n";
            continue;
        }
        
        if (choice == 1) {
            PrintJob job;
            
            std::cout << "Имя пользователя: ";
            std::cin.ignore();
            std::getline(std::cin, job.user);
            
            job.priority = getIntInput(1, 3, "Приоритет (1-высокий, 2-средний, 3-низкий): ");
            job.timestamp = time(0);
            
            printQueue.push(job);
            std::cout << "Задание для пользователя \"" << job.user 
                      << "\" с приоритетом " << job.priority << " добавлено.\n";
        }
        else if (choice == 2) {
            if (printQueue.empty()) {
                std::cout << "Нет заданий в очереди.\n";
            } else {
                PrintJob job = printQueue.top();
                printQueue.pop();
                statistics.push(job);
                std::cout << "Печать задания: пользователь \"" << job.user 
                          << "\" (приоритет " << job.priority << ")\n";
            }
        }
        else if (choice == 3) {
            if (statistics.empty()) {
                std::cout << "Статистика пуста. Ещё не было выполнено ни одной печати.\n";
            } else {
                std::queue<PrintJob> temp = statistics;
                std::cout << "\n===== ИСТОРИЯ ПЕЧАТИ =====\n";
                int counter = 1;
                while (!temp.empty()) {
                    PrintJob j = temp.front();
                    temp.pop();
                    std::cout << counter++ << ". Пользователь: " << j.user 
                              << ", приоритет: " << j.priority;
                    
                    // Вывод времени в читаемом формате
                    char* timeStr = ctime(&j.timestamp);
                    // Удаляем символ перевода строки из ctime
                    std::string tStr(timeStr);
                    if (!tStr.empty() && tStr.back() == '\n') tStr.pop_back();
                    std::cout << ", время: " << tStr << "\n";
                }
                std::cout << "========================\n";
            }
        }
    }
    
    return 0;
}