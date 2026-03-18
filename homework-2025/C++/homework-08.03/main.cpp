#include <iostream>
#include "drob.h"

int main() {
    std::cout << "FRACTION CALCULATOR\n";
    std::cout << "===================\n\n";
    
    Fraction f1(1, 2);
    Fraction f2(2, 3);
    Fraction f3;
    
    std::cout << "f1 = ";
    f1.display();
    std::cout << "\n";
    
    std::cout << "f2 = ";
    f2.display();
    std::cout << "\n";
    
    std::cout << "f3 = ";
    f3.display();
    std::cout << "\n\n";
    
    f3.setValue(3, 4);
    std::cout << "f3 = ";
    f3.display();
    std::cout << "\n\n";
    
    std::cout << "Operations:\n";
    std::cout << "f1 + f2 = ";
    f1.add(f2).display();
    std::cout << "\n";
    
    std::cout << "f1 - f2 = ";
    f1.subtract(f2).display();
    std::cout << "\n";
    
    std::cout << "f1 * f2 = ";
    f1.multiply(f2).display();
    std::cout << "\n";
    
    std::cout << "f1 / f2 = ";
    f1.divide(f2).display();
    std::cout << "\n\n";
    
    Fraction f4(4, 8);
    std::cout << "f4 = ";
    f4.display();
    std::cout << " (reduced)\n";
    
    return 0;
}