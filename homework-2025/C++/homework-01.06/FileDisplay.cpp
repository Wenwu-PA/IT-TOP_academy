#include "FileDisplay.h"
#include <fstream>
#include <iostream>

void FileDisplay::Display(const char* path) {
    std::ifstream file(path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл: " << path << std::endl;
        return;
    }
    char ch;
    while (file.get(ch)) {
        std::cout << ch;
    }
    std::cout << std::endl;
}