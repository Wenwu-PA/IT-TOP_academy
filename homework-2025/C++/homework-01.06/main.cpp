#include <iostream>
#include "FileDisplay.h"
#include "AsciiFileDisplay.h"
#include "BinaryFileDisplay.h"
#include "HexFileDisplay.h"

int main() {
    const char* filename = "test.txt"; // создайте тестовый файл

    FileDisplay* views[] = {
        new FileDisplay(),
        new AsciiFileDisplay(),
        new BinaryFileDisplay(),
        new HexFileDisplay()
    };

    for (auto view : views) {
        std::cout << "\n--- " << typeid(*view).name() << " ---\n";
        view->Display(filename);
        delete view;
    }

    return 0;
}