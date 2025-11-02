#include <iostream>

int main() {
    double x = 2.0;
    double numerator = x*x + 4;
    double denominator = x*x - 4;
    std::cout << "2) " << numerator / denominator << std::endl;
    return 0;
}