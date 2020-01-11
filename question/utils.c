#include <math.h>
#include "utils.h"
#include "draw.h"

unsigned long f0(unsigned long i)
{
    return pow(i, 1);
}

unsigned long f1(unsigned long i)
{
    return pow(i, 2) + 2;
}

unsigned long f2(unsigned long i)
{
    return pow(i, 3) + 4;
}

unsigned long f3(unsigned long i)
{
    return pow(i, 4) + 8;
}

unsigned long f4(unsigned long i)
{
    return pow(i, 5) + 16;
}

unsigned long apply_function(unsigned long i, int column)
{
    int func;
    func = column % 5;

    switch (func)
    {
    case 0:
        return f0(i);
    case 1:
        return f1(i);
    case 2:
        return f2(i);
    case 3:
        return f3(i);
    case 4:
        return f4(i);
    default:
        return i;
    }
}
