#include <iostream>

int main() {
    int A;
    std::cout << "Введите число A: ";
    std::cin >> A;
    
    int sum = 0;
    int temp = A;
    while (temp != 0) {
        sum += temp % 10;
        temp /= 10;
    }
    
    int cubeSum = sum * sum * sum;
    if (cubeSum == A * A) {
        std::cout << "5) Верно" << std::endl;
    } else {
        std::cout << "5) Неверно" << std::endl;
    }
    
    return 0;
}