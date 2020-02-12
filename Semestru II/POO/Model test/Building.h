#include "Materie.h"

class Building : public Materie {
public:
    Building(string nume, string tip, int et) : Materie(nume, tip), etaje(et) {}
    void accept(BuildingVisitor *vis) {
        this->vis = vis;
    }
protected:
    int etaje;
    BuildingVisitor *vis;
};
