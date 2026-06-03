#include "../Test.h"

TEST("Test will pass without any confirms")
{
    
}

TEST("Test passing grades")
{
    bool result = isPassingGrade(0);
    if (result)
    {
        throw 1;
    }
        result = isPassingGrade(100);
    if (not result)
        {
            throw 1;
    }
}