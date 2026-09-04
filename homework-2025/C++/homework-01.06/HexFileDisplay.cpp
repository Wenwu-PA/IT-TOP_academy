#include "HexFileDisplay.h"
#include <fstream>
#include <iostream>
#include <iomanip>

void HexFileDisplay::Display(const char* path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << path << std::endl;
        return;
    }
    unsigned char ch;
    int count = 0;
    while (file.read(reinterpret_cast<char*>(&ch), 1)) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') 
                  << static_cast<int>(ch) << " ";
        if (++count % 16 == 0) std::cout << std::endl;
    }
    std::cout << std::dec << std::endl;
}