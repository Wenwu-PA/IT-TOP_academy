#ifndef DROB_H
#define DROB_H

class Fraction {
private:
    int numerator;
    int denominator;
    
public:
    Fraction();
    Fraction(int num, int den);
    
    void setValue(int num, int den);
    void display();
    
    Fraction add(Fraction f);
    Fraction subtract(Fraction f);
    Fraction multiply(Fraction f);
    Fraction divide(Fraction f);
    
    void reduce();
    int getNumerator();
    int getDenominator();
};

#endif