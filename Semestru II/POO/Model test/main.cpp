#include <iostream>
#include "Materie.h"
#include "Building.h"
#include "Casa.h"
#include "Bloc.h"
#include "Lift.h"
#include "Om.h"
#include "Pamant.h"
#include "BuildingVisitor.h"
#include <time.h>

using namespace std;

int main()
{
    Materie *teritoriu = new Pamant("Romania", "tara");
    Building *bloc = new Bloc("Nr. 41, L5", "Ciment", 10);
    Building *casa = new Casa("Nr. 4", "Chirpici", 1);
    bloc->Add(new Lift("Lift", "metal"));
    teritoriu->Add(bloc);
    teritoriu->Add(casa);
    srand(time(NULL));
    [casa]() mutable {
        for (auto i : { '1','2','3','4' })
            casa->Add(new Om(string("Persoana") + i, []() -> string {
                const char *items[3] = { "Femeie", "Barbat" };
                return items[rand() % 2];
            }()));
    }();
    bloc->accept(new BlocVisitor);
    casa->accept(new CasaVisitor);
    teritoriu->Build(0);
    return 0;
}
