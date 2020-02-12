#include "Materie.h"

class Pamant : public Materie {
public:
    Pamant(string name, string tip) : Materie(nume, tip){}
    virtual void Build() {
        cout<<"PAMANT:"<<name<<":"<<tip<<endl;
        for(auto it : *this) it->Build();
    }
};
