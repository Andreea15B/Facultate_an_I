#include "Materie.h"

class Om : public Materie {
public:
    Om(string name, string tip) : Materie(nume, tip){}
    virtual void Build() {
        cout<<"OM:"<<name<<":"<<tip<<endl;
        for(auto it : *this) it->Build();
    }
};
