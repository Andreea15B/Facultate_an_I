// Să se scrie descompunerea în factori primi (ridicați la puterile corespunzătoare) a unui număr natural n.
#include <iostream>

using namespace std;
int p[200];
void ciur(int n);
int main()
{
    int n,i,j,putere=0;
    cin>>n;
    ciur(n);
    for(i=2;i<=n && n>1;i++) {
        if(p[i]==0) {
            while(n%i==0) {
                putere++;
                n/=i;
            }
            if(putere>0) cout<<"("<<i<<"^"<<putere<<")";
        }
        putere=0;
    }
    return 0;
}
void ciur(int n) {
    int i,j; // p[i]==0 daca i este prim
    for(i=2;i<=n;i++) {
        if(p[i]==0) for(j=2*i;j<=n;j+=i) p[j]=1;
    }
}
