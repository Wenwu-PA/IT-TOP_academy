#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

struct Event {
    double time;
    int type;     // 0 - пассажир, 1 - маршрутка
    int seats;    // свободные места в маршрутке
    bool operator<(const Event& other) const { return time > other.time; }
};

double expRandom(double mean) {
    double u = (double)rand() / RAND_MAX;
    return -mean * log(1.0 - u);
}

int main() {
    srand(time(0));
    
    double meanPassMorning, meanPassDay, meanPassEvening;
    double meanBusMorning, meanBusDay, meanBusEvening;
    int maxAllowed;
    double simHours = 8.0;
    
    std::cout << "Среднее время между появлениями пассажиров (минуты):\n";
    std::cout << "Утро (6-10): "; std::cin >> meanPassMorning;
    std::cout << "День (10-18): "; std::cin >> meanPassDay;
    std::cout << "Вечер (18-22): "; std::cin >> meanPassEvening;
    std::cout << "Среднее время между появлениями маршрутов (минуты):\n";
    std::cout << "Утро: "; std::cin >> meanBusMorning;
    std::cout << "День: "; std::cin >> meanBusDay;
    std::cout << "Вечер: "; std::cin >> meanBusEvening;
    std::cout << "Максимально допустимое число людей на остановке N: "; std::cin >> maxAllowed;
    
    // Поиск подходящего коэффициента
    double coef = 1.0;
    double bestCoef = 1.0;
    const double step = 0.05;
    
    for (int iter = 0; iter < 30; ++iter) {
        std::priority_queue<Event> events;
        double currentTime = 0.0;
        int queueSize = 0;
        int maxQueue = 0;
        
        // Начальные события
        events.push({expRandom(meanPassMorning * coef), 0, 0});
        events.push({expRandom(meanBusMorning), 1, rand() % 15 + 5});
        
        while (!events.empty() && currentTime < simHours * 60) {
            Event e = events.top();
            events.pop();
            currentTime = e.time;
            
            if (e.type == 0) { // пассажир
                queueSize++;
                if (queueSize > maxQueue) maxQueue = queueSize;
                // следующее появление пассажира
                double meanPass = (currentTime < 240) ? meanPassMorning : (currentTime < 600 ? meanPassDay : meanPassEvening);
                events.push({currentTime + expRandom(meanPass * coef), 0, 0});
            } else { // маршрутка
                if (queueSize > 0) {
                    int boarded = (e.seats < queueSize) ? e.seats : queueSize;
                    queueSize -= boarded;
                }
                double meanBus = (currentTime < 240) ? meanBusMorning : (currentTime < 600 ? meanBusDay : meanBusEvening);
                events.push({currentTime + expRandom(meanBus), 1, rand() % 15 + 5});
            }
        }
        
        if (maxQueue <= maxAllowed) {
            bestCoef = coef;
            coef -= step;
            if (coef < 0.1) break;
        } else {
            coef += step;
        }
    }
    
    std::cout << "Достаточный интервал между маршрутами: ~" << (meanBusMorning * bestCoef) << " минут\n";
    
    return 0;
}