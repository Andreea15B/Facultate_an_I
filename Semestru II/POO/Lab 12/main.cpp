#include <iostream>
#include "GWindow.h"
#include "Loh.h"
#include "vector"
#include "string"
using namespace std;

int main()
{
   /* GWindow *P1 = new Panel(0,0,100,100,"P1");
    P1->Add(new Panel(10,10,80,40,"P2"));
    GWindow *P3 = new Panel(10,60,80,40,"P3");
    P1->Add(P3);
    P3->Add(new Buton(20,65,50,10,"B1"));
    P3->Add(new Buton(20,75,50,10,"B2"));
    P1->Paint(); */

    Log* inst = Log::GetInstance();
    inst->changeFileName("log.txt");
    inst->DebugMsg("Start\n");

    PanelVisitor *pv = new PanelVisitor;
    ButonVisitor *bv = new ButonVisitor;
    return 0;
}
