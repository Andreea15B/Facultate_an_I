#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("list.in");
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
void elimina_primul() { //șterge primul element al unei liste simplu înlănțuită
    nod *q=new nod;
    q=prim;
    prim=prim->urm;
    delete q;
}
int prime_intre_ele(int a, int b) {
    //cmmdc=1
    int r;
    while(b!=0) {
        r=a%b;
        a=b;
        b=r;
    }
    if(a==1) return 1;
    return 0;
}
int nr_perechi_prime() { //determină câte perechi de elemente prime între ele sunt memorate într-o listă simplu înlănțuită
    int nr=0;
    nod *p=new nod;
    p=prim;
    while(p->urm!=NULL) {
        if(prime_intre_ele(p->info,p->urm->info)) nr++;
        p=p->urm;
    }
    return nr;
}
int main()
{
    int n,i,x;
    fin>>n;
    for(i=0;i<n;i++) {
        fin>>x;
        adauga(x);
    }
    elimina_primul();
    afiseaza();
    prime_intre_ele(1,2);
    cout<<nr_perechi_prime();
    return 0;
}
