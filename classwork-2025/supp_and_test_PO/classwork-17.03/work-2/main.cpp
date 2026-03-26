#include <iostream>
#include "modulse/soundex.h"
#include <cassert>

int main()
{
    Soundex sd;
    assert(sd.encode("A") == "A000");
    assert(sd.encode("I") == "I000");
    assert(sd.encode("Ab") == "A100");
    assert(sd.encode("Ac") == "A200");
    assert(sd.encode("Ad") == "A300");
    assert(sd.encode("Ax") == "A200");
    
    
    return 0;
}