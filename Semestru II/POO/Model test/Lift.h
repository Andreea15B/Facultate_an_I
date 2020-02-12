#include "Materie.h"

class Lift : public Materie {
public:
    Lift(string name, string tip) : Materie(nume, tip){}
    virtual void Build() {
        cout<<"LIFT:"<<name<<":"<<tip<<endl;
        for(auto it : *this) it->Build();
    }
};
