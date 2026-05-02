#include "Date.h"
#include <iostream>
#include <ctime>

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    if (!isValid()) {
        std::cerr << "Некорректная дата! Установлена 01.01.1970\n";
        day = 1; month = 1; year = 1970;
    }
}

Date::Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}
bool Date::isLeapYear() const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int Date::daysInMonth() const {
    static const int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && isLeapYear())
        return 29;
    return days[month - 1];
}
bool Date::isValid() const {
    if (year < 1 || month < 1 || month > 12) return false;
    if (day < 1 || day > daysInMonth()) return false;
    return true;
}
void Date::incrementDay() {
    ++day;
    if (day > daysInMonth()) {
        day = 1;
        ++month;
        if (month > 12) {
            month = 1;
            ++year;
        }
    }
}

void Date::decrementDay() {
    --day;
    if (day < 1) {
        --month;
        if (month < 1) {
            month = 12;
            --year;
        }
        day = daysInMonth();
    }
}


Date& Date::operator++() {
    incrementDay();
    return *this;
}
Date Date::operator++(int) {
    Date temp = *this;
    incrementDay();
    return temp;
}
Date& Date::operator--() {
    decrementDay();
    return *this;
}

Date Date::operator--(int) {
    Date temp = *this;
    decrementDay();
    return temp;
}


bool Date::operator==(const Date& other) const {
    return day == other.day && month == other.month && year == other.year;
}

bool Date::operator!=(const Date& other) const {
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    if (year != other.year) return year < other.year;
    if (month != other.month) return month < other.month;
    return day < other.day;
}

bool Date::operator>(const Date& other) const {
    return other < *this;
}


Date& Date::operator=(const Date& other) {
    if (this != &other) {
        day = other.day;
        month = other.month;
        year = other.year;
    }
    return *this;
}

Date& Date::operator+=(int days) {
    if (days < 0) return *this -= (-days);
    for (int i = 0; i < days; ++i)
        incrementDay();
    return *this;
}

Date& Date::operator-=(int days) {
    if (days < 0) return *this += (-days);
    for (int i = 0; i < days; ++i)
        decrementDay();
    return *this;
}

int Date::operator()() const {
    int days = 0;
    for (int m = 1; m < month; ++m) {
        Date dummy(1, m, year);
        days += dummy.daysInMonth();
    }
    days += day;
    return days;
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << (d.day < 10 ? "0" : "") << d.day << "."
       << (d.month < 10 ? "0" : "") << d.month << "."
       << d.year;
    return os;
}

std::istream& operator>>(std::istream& is, Date& d) {
    char dot1, dot2;
    int dd, mm, yy;
    is >> dd >> dot1 >> mm >> dot2 >> yy;
    if (dot1 == '.' && dot2 == '.' && is) {
        Date temp(dd, mm, yy);
        if (temp.isValid()) {
            d = temp;
        } else {
            std::cerr << "Ошибка: неверная дата. Оставлена прежняя.\n";
        }
    } else {
        std::cerr << "Ошибка формата. Используйте ДД.ММ.ГГГГ\n";
        is.clear();
    }
    return is;
}