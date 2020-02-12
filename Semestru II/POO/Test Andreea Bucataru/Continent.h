#pragma once
#include "Teritoriu.h"
#include "Stat.h"
#include <vector>
using namespace std;

class Continent : public Stat {
private:
    vector<Stat> state;
public:
    Continent(string nume) : Stat(nume, suprafata){
        this->nume = nume;
    }
    void AfiseazaStateCuMunti();
    int CalculeazSuprafata() {}
    void Add(Stat st) {
        state.push_back(st);
    }
};
