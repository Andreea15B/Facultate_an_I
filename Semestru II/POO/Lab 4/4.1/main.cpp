#include <iostream>
#include <stdio.h>
#include "Forma.h"
#include "Dreptunghi.h"
#include "Cerc.h"

using namespace std;

int main()
{
    Forma* v[10];

    v[0] = new Dreptunghi(2, 3);
    printf("%s %f\n", v[0]->GetName(), v[0]->ComputeArea());

    v[1] = new Cerc(5);
    printf("%s %f\n", v[1]->GetName(), v[1]->ComputeArea());
    return 0;
}
