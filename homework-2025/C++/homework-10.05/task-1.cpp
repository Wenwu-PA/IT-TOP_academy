#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string input;
    std::cout << "Введите строку (признак конца ';'): ";
    std::getline(std::cin, input, ';');

    std::stack<char> brackets;
    bool correct = true;
    size_t errorPos = 0;

    for (size_t i = 0; i < input.length(); ++i) {
        char c = input[i];

        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (brackets.empty()) {
                correct = false;
                errorPos = i;
                break;
            }

            char top = brackets.top();
            brackets.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                correct = false;
                errorPos = i;
                break;
            }
        }
    }

    if (correct && !brackets.empty()) {
        correct = false;
        errorPos = input.length() - 1;
    }

    if (correct) {
        std::cout << "Строка корректна! Все скобки расставлены правильно.\n";
    } else {
        std::cout << "Ошибка в позиции " << errorPos << "\n";
        std::cout << "Строка до места ошибки: " << input.substr(0, errorPos + 1) << "\n";
    }

    return 0;
}