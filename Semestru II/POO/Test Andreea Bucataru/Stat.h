#pragma once
#include "Teritoriu.h"
#include "Munti.h"
#include <vector>
using namespace std;

class Stat : public Munti {
private:
    vector<Munti> munti;
public:
    Stat(string nume, int suprafata) : Munti(nume, suprafata, altitudine){
        this->nume = nume;
        this->suprafata = suprafata;
    }
    int CalculeazSuprafata() {
        return suprafata;
    }
    void Add(Munti munte) {
        munti.push_back(munte);
    }
};
