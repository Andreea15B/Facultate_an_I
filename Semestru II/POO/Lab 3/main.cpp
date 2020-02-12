#include <iostream>
#include <stdio.h>
#include "BigNumber.h"
using namespace std;

int main()
{
    BigNumber a,c(131),d;
    BigNumber b(c);
    b.PrintNumber();
    b.Set("12");
    b.PrintNumber();

    return 0;
}
