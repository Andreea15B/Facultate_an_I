#include "Building.h"

class Bloc : public Building {
public:
    Bloc(string nume, string tip, int etaje) : Building(nume, tip, etaje) {}
    virtual void Build() {
        cout<<"BLOC:"<<name<<" : "<<tip<<" : "<<etaje<<endl;
        vis->visit(this);
        for(auto it : *this) it->Build();
    }
};
