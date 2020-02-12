#include <iostream>

using namespace std;

struct nod {
    int info;
    nod *urm;
}*prim,*ultim;

void adaug(int x) {
    if(prim==NULL) {
        prim=new nod;
        prim->info=x;
        prim->urm=NULL;
        ultim=prim;
    }
    else {
        nod *c;
        c=new nod;
        c->info=x;
        c->urm=NULL;
        ultim->urm=c;
        ultim=c;
    }
}

void afisare() {
    nod *c;
    c=prim;
    while (c!=NULL) {
        cout<<c->info<<" ";
        c=c->urm;
    }
    cout<<'\n';
}
void adaug_inceput(int x){
    nod *c;
    c=new nod;
    c->info=x;
    c->urm=prim;
    prim=c;
}
void adaug_valoare(int x,int elem) {
    nod *q;
    q=prim;
    while(q!=NULL) {
        if(q->info==elem) {
            nod *r;
            r=new nod;
            r->info=x;
            r->urm=q->urm;
            q->urm=r;
        }
        q=q->urm;
    }
}
int main()
{
    int n,nr,i;
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>nr;
        adaug(nr);
    }
    adaug_inceput(4);
    afisare();
    adaug_valoare(5,6);
    afisare();
    return 0;
}
