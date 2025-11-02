#include <iostream>

int main() {
    double x;
    std::cout << "Enter x: ";
    std::cin >> x;
    
    double numerator = x*x - 4*x + 3;
    double denominator = x*x - x - 6;
    std::cout << "3) " << numerator / denominator << std::endl;
    return 0;
}