#include <iostream>
#include <cmath>

int main() {
    double x;
    std::cout << "Enter x: ";
    std::cin >> x;
    
    double result = sqrt(x + sqrt(x)) - sqrt(x);
    std::cout << "6) " << result << std::endl;
    return 0;
}