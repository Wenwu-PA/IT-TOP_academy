#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
    int day;
    int month;
    int year;

    bool isLeapYear() const;
    int daysInMonth() const;
    bool isValid() const;

public:
    Date(int d = 1, int m = 1, int y = 1970);
    Date(const Date& other);

    void incrementDay();
    void decrementDay();

    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);
    bool operator==(const Date& other) const;
    bool operator!=(const Date& other) const;
    bool operator<(const Date& other) const;
    bool operator>(const Date& other) const;
    Date& operator=(const Date& other);
    Date& operator+=(int days);
    Date& operator-=(int days);
    int operator()() const;

    friend std::ostream& operator<<(std::ostream& os, const Date& d);
    friend std::istream& operator>>(std::istream& is, Date& d);
};

#endif