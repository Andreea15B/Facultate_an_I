#include <iostream>
#include <stdio.h>
#include "Forma.h"
#include "Dreptunghi.h"
#include "Cerc.h"
#include "Triunghi.h"

using namespace std;

int main()
{
    Forma* v[10];

    v[0] = new Dreptunghi(2, 3);
    printf("%s %.1f\n", v[0]->GetName(), v[0]->ComputeArea());

    v[1] = new Cerc(5);
    printf("%s %.2f\n", v[1]->GetName(), v[1]->ComputeArea());

    v[2] = new Triunghi(20, 5, 7, 10, 20, 21);
    printf("%s %.3f\n", v[2]->GetName(), v[2]->ComputeArea());
    return 0;
}
