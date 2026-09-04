#include "AsciiFileDisplay.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void AsciiFileDisplay::Display(const char* path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << path << std::endl;
        return;
    }
    unsigned char ch;
    while (file.read(reinterpret_cast<char*>(&ch), 1)) {
        std::cout << std::setw(3) << static_cast<int>(ch) << " ";
    }
    std::cout << std::endl;
}