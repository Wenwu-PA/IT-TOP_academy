#include "BinaryFileDisplay.h"
#include <fstream>
#include <iostream>
#include <bitset>

void BinaryFileDisplay::Display(const char* path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << path << std::endl;
        return;
    }
    unsigned char ch;
    while (file.read(reinterpret_cast<char*>(&ch), 1)) {
        std::cout << std::bitset<8>(ch) << " ";
    }
    std::cout << std::endl;
}