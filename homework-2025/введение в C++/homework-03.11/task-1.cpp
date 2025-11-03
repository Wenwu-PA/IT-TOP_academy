#include <iostream>
#include <string>

int printA() {
    std::cout << "Фигура a:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}

int printNotA() {
    std::cout << "Фигура ¬a:\n";
    for (int i = 5; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}

int printNotB() {
    std::cout << "Фигура ¬b:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j < 4 - i) std::cout << " ";
            else std::cout << "*";
        }
        std::cout << "\n";
    }
    return 0;
}

int printNotC() {
    std::cout << "Фигура ¬c:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= i) std::cout << "*";
            else std::cout << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

int printNotD() {
    std::cout << "Фигура ¬d:\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (j >= i && j <= 4 - i) std::cout << "*";
            else if (j < i) std::cout << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

int printE() {
    std::cout << "Фигура e:\n";
    int size = 5;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == 0 || i == size - 1 || j == 0 || j == size - 1) 
                std::cout << "*";
            else 
                std::cout << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

int printX() {
    std::cout << "Фигура x:\n";
    int size = 5;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j || i + j == size - 1) 
                std::cout << "*";
            else 
                std::cout << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

int print3() {
    std::cout << "Фигура 3:\n";
    int size = 5;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == size / 2 || j == size - 1) 
                std::cout << "*";
            else if (j == 0 && i < size / 2) 
                std::cout << "*";
            else 
                std::cout << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

int printU() {
    std::cout << "Фигура u:\n";
    int size = 5;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j == 0 || j == size - 1 || i == size - 1) 
                std::cout << "*";
            else 
                std::cout << " ";
        }
        std::cout << "\n";
    }
    return 0;
}

int printK() {
    std::cout << "Фигура k:\n";
    int size = 5;
    for (int i = 0; i < size; i++) {
        std::cout << "*";
        for (int j = 0; j < 3; j++) {
            if ((i == 0 || i == size - 1) && j < 2) 
                std::cout << "*";
            else if (i == size / 2 && j == 0) 
                std::cout << "*";
            else 
                std::cout << " ";
        }
        if (i != 0 && i != size - 1 && i != size / 2) 
            std::cout << "*";
        std::cout << "\n";
    }
    return 0;
}

int showMenu() {
    std::cout << "\n=== МЕНЮ ВЫБОРА ФИГУР ===\n";
    std::cout << "1 - Фигура a\n";
    std::cout << "2 - Фигура ¬a\n";
    std::cout << "3 - Фигура ¬b\n";
    std::cout << "4 - Фигура ¬c\n";
    std::cout << "5 - Фигура ¬d\n";
    std::cout << "6 - Фигура e\n";
    std::cout << "7 - Фигура x\n";
    std::cout << "8 - Фигура 3\n";
    std::cout << "9 - Фигура u\n";
    std::cout << "10 - Фигура k\n";
    std::cout << "0 - Выход\n";
    std::cout << "Выберите фигуру: ";
    return 0;
}

int main() {
    int choice;
    
    do {
        showMenu();
        std::cin >> choice;
        
        switch (choice) {
            case 1: printA(); break;
            case 2: printNotA(); break;
            case 3: printNotB(); break;
            case 4: printNotC(); break;
            case 5: printNotD(); break;
            case 6: printE(); break;
            case 7: printX(); break;
            case 8: print3(); break;
            case 9: printU(); break;
            case 10: printK(); break;
            case 0: std::cout << "Выход из программы.\n"; break;
            default: std::cout << "Неверный выбор!\n"; break;
        }
        
    } while (choice != 0);
    
    return 0;
}
