#include <iostream>

int main() {
    double x = 1.0;
    double result = (x*x + 2) / (x*x*x + 4);
    std::cout << "1) " << result << std::endl;
    return 0;
}