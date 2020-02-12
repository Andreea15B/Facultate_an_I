#pragma once
#include "Materie.h"

class BuildingVisitor {
public:
    virtual void visit(Materie *mat) = 0;
};

class BlocVisitor : public BuildingVisitor {
public:
    virtual void visit(Materie *mat) {
        cout<<"BLOC este o cladire"<<endl;
    }
};

class CasaVisitor : public BuildingVisitor {
public:
    virtual void visit(Materie *mat) {
        cout<<"CASA este o cladire"<<endl;
    }
};
