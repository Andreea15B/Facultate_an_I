#include <iostream>

using namespace std;

struct nod {
    int info;
    nod *urm;
}*L,*P;
int n;
void creare() {
    L=NULL;
    for(int i=1;i<=n;i++) {
        P=new nod;
        P->info=i;
        P->urm=L;
        L=P;
    }
}
void afisare() {
    P=L;
    while(P!=NULL) {
        cout<<P->info<<" ";
        P=P->urm;
    }
}
int main()
{
    int i,x;
    cin>>n;
    creare();
    afisare();
    return 0;
}
