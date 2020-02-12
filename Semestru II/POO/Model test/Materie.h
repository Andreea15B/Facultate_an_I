#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Materie {
public:
    virtual void Build()=0;
    Materie(string name, string tip) {
        this->name = name;
        this->tip = tip;
    }
    void Add(Materie *mat) {
        childs.push_back(mat);
    }
    vector<Materie*>::iterator begin() {return childs.begin();}
    vector<Materie*>::iterator end() {return childs.end();}

protected:
    vector<Materie*> child;
    string name;
    string tip;
};
