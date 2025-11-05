#include <iostream>

int main() {
    int count = 0;
    for (int i = 100; i <= 999; i++) {
        int digit1 = i / 100;
        int digit2 = (i / 10) % 10;
        int digit3 = i % 10;
        if (digit1 == digit2 || digit1 == digit3 || digit2 == digit3) {
            count++;
        }
    }
    std::cout << "1) " << count << std::endl;
    return 0;
}