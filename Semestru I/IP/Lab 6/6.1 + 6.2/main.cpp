#include <iostream>
#define DMAX 100
using namespace std;
struct nod {
    int info;
    nod *urm;
};

nod *liste[DMAX][2];

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
int main()
{
    int n,i,x;
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>x;
        adaug(x, liste[1][0], liste[1][1]);
        adaug(-x, liste[2][0], liste[2][1]);
    }
    afisare(liste[2][0]);
    return 0;
}
