#include <iostream>

int main() {
    int A;
    std::cout << "Введите число A: ";
    std::cin >> A;
    
    std::cout << "Числа B: ";
    for (int B = 1; B <= A; B++) {
        if (A % (B * B) == 0 && A % (B * B * B) != 0) {
            std::cout << B << " ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}