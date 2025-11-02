#include <iostream>
#include <cmath>

int main() {
    double x;
    std::cout << "Enter x: ";
    std::cin >> x;
    
    double numerator = x*x - sqrt(x);
    double denominator = sqrt(x) - 1;
    std::cout << "4) " << numerator / denominator << std::endl;
    return 0;
}