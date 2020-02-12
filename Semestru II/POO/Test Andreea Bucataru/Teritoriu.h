#pragma once
#include <string.h>
#include <stdlib.h>
using namespace std;

class Teritoriu {
protected:
    string nume;
    int suprafata;
public:
    void Afiseaza();
    virtual int CalculeazSuprafata() {}
};
