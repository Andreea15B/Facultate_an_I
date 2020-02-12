#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("list.in");
struct nod
{
    int info;
    nod *urm;
};
void adaug(int x, nod *&prim,nod *&ultim)
{
    if(prim==NULL)
    {
        prim=new nod;
        prim->info=x;
        prim->urm=NULL;
        ultim=prim;
    }
    else
    {
        nod* q;
        q=new nod;
        q->info=x;
        ultim->urm=q;
        q->urm=NULL;
        ultim=q;
    }
}
void afisare(nod *prim)
{   nod *p=prim;
    while(p!=NULL)
    {
        cout<<p->info<<" ";
        p=p->urm;
    }
    cout<<endl;
}

int perechi(nod *prim)
{   int nr=0;

    while(prim->urm!=NULL) {
        if(prim->info==prim->urm->info) nr++;
        prim=prim->urm;
    }
    return nr;
}

int main()
{
    nod *prim=NULL,*ultim=NULL;
    int x,n;
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>x;
        adaug(x,prim,ultim);
    }
    cout<<perechi(prim)<<endl;
    return 0;
}
