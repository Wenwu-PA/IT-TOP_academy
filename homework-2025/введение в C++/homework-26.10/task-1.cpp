#include <iostream>

int main(){
    int ch_code;
    char ch;
    std::cout << "Введите символ: \n";
    std::cin >> ch;
    ch_code = (int)ch;
    if (((ch_code >= 65)&&(ch_code <= 90)) || ((ch_code >= 97) && (ch_code <= 122)))
    {
        std::cout << "Ого, это буква!";
    }
    else if ((ch_code >= 48) && (ch_code <= 57))
    {
        std::cout << "Ого, это цифра!";
    }
    else if ((ch_code == 33) || ((ch_code >= 44) && (ch_code<=46)) || (ch_code == 58) || (ch_code == 59) || (ch_code == 63))
    {
        std::cout << "Почему знак препинания...?";
    }
    else
    {
        std::cout << "что?";
    }
 return 0;

}