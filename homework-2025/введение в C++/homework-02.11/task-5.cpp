#include <iostream>
#include <cmath>

int main() {
    double x;
    std::cout << "Enter x: ";
    std::cin >> x;
    
    double numerator = 3*x*x + sqrt(4*x);
    double denominator = x * (sqrt(2 + 4*x*x) + 2);
    std::cout << "5) " << numerator / denominator << std::endl;
    return 0;
}