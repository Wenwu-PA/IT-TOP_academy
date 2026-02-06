#include <iostream>

struct statusField{
    unsigned int JS;
    unsigned int PHP;
    unsigned int Python;
};

struct fieldbite{
    unsigned short field1: 2;
    unsigned short field2: 2;
    unsigned short field3: 4;
};

struct Date{
    unsigned short weekDay: 3;
    unsigned short monthDay: 3;
    unsigned short month: 3;
    unsigned short year: 3;
};

int main(){

    statusField Fi{};
    std::cout << sizeof(Fi) << '\n';

    fieldbite FB;
    std::cout << sizeof(FB) << '\n';

    Date newDate{};
    std::cout << sizeof(newDate) << '\n';

    return 0;
}