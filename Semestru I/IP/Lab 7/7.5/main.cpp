#include <iostream>
#include <fstream>
#define DMAX 20
using namespace std;
ifstream fin("list.in");
struct nod {
    int info;
    nod *urm;
};

nod *liste[DMAX][2]; //DMAX este nr listei

void adauga(int x, nod *&prim, nod *&ultim) {
    nod *q;
    q=new nod;
    q->info=x;
    q->urm=NULL;
    if(prim==NULL) {
        prim=q;
        ultim=q;
    }
    else {
        ultim->urm=q;
        ultim=q;
    }
}
void afiseaza(nod *&prim){
    nod *p;
    p=prim;
    while(p!=NULL) {
        cout<<p->info<<" ";
        p=p->urm;
    }
    cout<<'\n';
}
void elimina_primul(nod *&prim) { //șterge primul element al unei liste simplu înlănțuită
    nod *q=new nod;
    q=prim;
    prim=prim->urm;
    delete q;
}
void interclasare(nod *&primL1, nod *&primL2) { // interclasează două liste simplu înlănțuite care sunt ordonate crescător
    nod *p1, *p2;
    p1=primL1; p2=primL2;
    if(primL1==NULL) while(p2!=NULL) {
        adauga(p2->info,liste[3][0],liste[3][1]);
        p2 = p2->urm;
    }
    else if(primL2==NULL) while(p1!=NULL) {
        adauga(p1->info,liste[3][0],liste[3][1]);
        p1 = p1->urm;
    }
    else {
        while(p1!=NULL && p2!=NULL) {
            if(p1->info > p2->info) {
                adauga(p2->info,liste[3][0],liste[3][1]);
                p2 = p2->urm;
            }
            else {
                adauga(p1->info,liste[3][0],liste[3][1]);
                p1 = p1->urm;
            }
        }
        while(p1!=NULL) {
            adauga(p1->info,liste[3][0],liste[3][1]);
            p1 = p1->urm;
        }
        while(p2!=NULL) {
            adauga(p2->info,liste[3][0],liste[3][1]);
            p2 = p2->urm;
        }
    }
}
int main()
{
    int n,x,i,m;
    nod *L1, *L2;
    fin>>n;
    for(i=0;i<n;i++) {
        fin>>x;
        adauga(x,liste[1][0],liste[1][1]);
    }
    fin>>m;
    for(i=0;i<m;i++) {
        fin>>x;
        adauga(x,liste[2][0],liste[2][1]);
    }
    interclasare(liste[1][0],liste[2][0]);
    afiseaza(liste[3][0]);
    return 0;
}
