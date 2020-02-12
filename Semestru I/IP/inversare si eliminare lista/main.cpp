#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("lista.in");
struct nod {
    int info;
    nod *urm;
    nod *prec;
};
struct listaDubla {
    nod *prim, *ultim;
    unsigned int lungime;
};
void afisare(listaDubla a) {
    nod *p=new nod;
    p=a.prim;
    while(p!=NULL) {
        cout<<p->info<<" ";
        p = p->urm;
    }
    cout<<endl;
}
void adaug(listaDubla &a, int x) {
    nod *p=new nod;
    p->info=x;
    p->urm=NULL;
    if(a.prim==NULL) {
        p->prec=NULL;
        a.prim=p;
        a.ultim=p;
    }
    else {
        a.ultim->urm=p;
        p->prec=a.ultim;
        a.ultim=p;
    }
}
void elimin(listaDubla &a, int x) {
    nod *p=new nod;
    if(a.prim->info==x) {
        p=a.prim;
        a.prim->prec=NULL;
        a.prim=a.prim->urm;
        delete p;
    }
    else {
        if(a.ultim->info==x) {
            p=a.ultim;
            a.ultim=a.ultim->prec;
            a.ultim->urm=NULL;
            delete p;
        }
        else {
            p=a.prim;
            while(p!=NULL && p->info!=x) p=p->urm;
            p->urm->prec=p->prec;
            p->prec->urm=p->urm;
            delete p;
        }
    }
}
void inversare(listaDubla &a) {
    nod *p=new nod,*t=NULL;
    p=a.prim;
    while(p!=NULL) {
        t=p->prec;
        p->prec=p->urm;
        p->urm=t;
        p=p->prec;
    }
    if(t!=NULL) {
        a.prim=t->prec;
    }
}
void eliminareInversare(listaDubla &a) {
    nod *p=new nod;
    int x;
    p=a.prim;
    while(p!=NULL) {
        if(p->info<0) {
            x=p->info;
            p=p->urm;
            elimin(a,x);
        }
        else p=p->urm;
    }
    inversare(a);
}
int main()
{
    listaDubla a;
    int i,x;
    fin>>a.lungime;
    a.prim=a.ultim=NULL;
    for(i=0;i<a.lungime;i++) {
        fin>>x;
        adaug(a,x);
    }
    afisare(a);
    //elimin(a,5);
    //afisare(a);
    //inversare(a);
    eliminareInversare(a);
    afisare(a);
    return 0;
}
