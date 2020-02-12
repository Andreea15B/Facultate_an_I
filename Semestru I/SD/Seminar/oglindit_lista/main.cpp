// lista conține bucle?
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("list.in");
struct nod {
    int info;
    nod *urm;
};
void adaug(int x, nod *&prim, nod *&ultim) {
    if(prim==NULL) {
        prim=new nod;
        prim->info=x;
        prim->urm=NULL;
        ultim=prim;
    }
    else {
        nod *c;
        c=new nod;
        ultim->urm=c;
        c->info=x;
        c->urm=NULL;
        ultim=c;
    }
}
void afisare(nod *prim) {
    nod *c;
    c=prim;
    while (c!=NULL) {
        cout<<c->info<<" ";
        c=c->urm;
    }
    cout<<'\n';
}
nod *oglindit(nod *&prim1) {
    nod *p,*q,*t;
    p=prim1; q=NULL; t=p->urm;
    while(t->urm!=NULL) {
        p->urm=q;
        q=p;
        p=t;
        t=t->urm;
    }
    p->urm=q;
    q=p;
    p=t;
    p->urm=q;
    return p;
}
int main()
{
    int n,x,i;
    nod *prim1,*ultim1,*prim2,*ultim2;
    prim1=prim2=ultim1=ultim2=NULL;
    fin>>n;
    for(i=0;i<n;i++) {
        fin>>x;
        adaug(x,prim1,ultim1);
    }
    prim2=oglindit(prim1);
    afisare(prim2);
    return 0;
}
