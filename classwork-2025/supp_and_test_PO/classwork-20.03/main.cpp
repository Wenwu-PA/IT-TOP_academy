#include <iostream>
#include "soundex.h"

int main()
{
    Soundex sd;
    std::cout << sd.encode("son") << '\n';
    std::cout << sd.encode("sun") << '\n';
    std::cout << sd.encode("buba") << '\n';
    std::cout << sd.encode("biba") << '\n';
    std::cout << sd.encode("Artem") << '\n';
    std::cout << sd.encode("Artemii") << '\n';
    std::cout << sd.encode("htop") << '\n';
    std::cout << sd.encode("btop") << '\n';
    
    
    return 0;
}