#include "drob.h"
#include <iostream>

Fraction::Fraction() {
    numerator = 0;
    denominator = 1;
}

Fraction::Fraction(int num, int den) {
    if (den == 0) {
        std::cout << "Denominator cannot be zero. Set to 1.\n";
        denominator = 1;
    } else {
        denominator = den;
    }
    numerator = num;
    reduce();
}

void Fraction::setValue(int num, int den) {
    if (den == 0) {
        std::cout << "Denominator cannot be zero.\n";
        return;
    }
    numerator = num;
    denominator = den;
    reduce();
}

void Fraction::display() {
    std::cout << numerator << "/" << denominator;
}

int Fraction::getNumerator() {
    return numerator;
}

int Fraction::getDenominator() {
    return denominator;
}

int findGCD(int a, int b) {
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduce() {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    
    int gcd = findGCD(numerator, denominator);
    
    if (gcd > 1) {
        numerator = numerator / gcd;
        denominator = denominator / gcd;
    }
}

Fraction Fraction::add(Fraction f) {
    Fraction result;
    result.numerator = numerator * f.denominator + f.numerator * denominator;
    result.denominator = denominator * f.denominator;
    result.reduce();
    return result;
}

Fraction Fraction::subtract(Fraction f) {
    Fraction result;
    result.numerator = numerator * f.denominator - f.numerator * denominator;
    result.denominator = denominator * f.denominator;
    result.reduce();
    return result;
}

Fraction Fraction::multiply(Fraction f) {
    Fraction result;
    result.numerator = numerator * f.numerator;
    result.denominator = denominator * f.denominator;
    result.reduce();
    return result;
}

Fraction Fraction::divide(Fraction f) {
    Fraction result;
    
    if (f.numerator == 0) {
        std::cout << "Cannot divide by zero. Returning 0/1.\n";
        result.numerator = 0;
        result.denominator = 1;
        return result;
    }
    
    result.numerator = numerator * f.denominator;
    result.denominator = denominator * f.numerator;
    result.reduce();
    return result;
}