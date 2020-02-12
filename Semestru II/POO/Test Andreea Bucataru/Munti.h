#pragma once
#include "Teritoriu.h"

class Munti : public Teritoriu {
protected:
    int altitudine;
public:
    Munti(string nume, int sup, int alt) {
        this->nume = nume;
        this->suprafata = sup;
        this->altitudine = alt;
    }
};
