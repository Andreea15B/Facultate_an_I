#include <iostream>

using namespace std;
struct nod {
    int info;
    nod *urm;
}*prim,*ultim;
void adauga(int x) {
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
void afiseaza(){
    nod *p;
    p=prim;
    while(p!=NULL) {
        cout<<p->info<<" ";
        p=p->urm;
    }
    cout<<'\n';
}
int sum_elem_impare() { //suma elementelor impare dintr-o lista simplu înlănțuită care sunt situate între două elemente pare
    int s=0;
    nod *curent,*precedent;
    precedent=prim;
    curent=precedent->urm;
    while(curent!=NULL) {
        if(precedent->info%2==0 && curent->info%2==1 && curent->urm->info%2==0) s+=curent->info;
        precedent=curent;
        curent=curent->urm;
    }
    return s;
}
void adauga_inceput(int x) { //adaugă o valoare la începutul unei liste simplu înlănțuită
    nod *p;
    p=new nod;
    p->info=x;
    p->urm=prim;
    prim=p;
}
int main()
{
    int n,x,i;
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>x;
        adauga(x);
    }
    afiseaza();
    cout<<sum_elem_impare()<<'\n';
    adauga_inceput(100);
    afiseaza();
    return 0;
}
