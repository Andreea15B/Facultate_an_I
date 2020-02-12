#include "Building.h"

class Casa : public Building {
public:
    Casa(string nume, string tip, int etaje) : Building(nume, tip, etaje) {}
    virtual void Build() {
        cout<<"CASA:"<<name<<" : "<<tip<<" : "<<etaje<<endl;
        vis->visit(this);
        for(auto it : *this) it->Build();
    }
};

