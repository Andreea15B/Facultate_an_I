/* Se citesc n numere între 1 și n, distincte între ele, cu excepția unuia care apare de 2 ori și a unuia care lipsește.
a - dublura și b - nr lipsă
a^2 - b^2 = (a-b)(a+b)
T - suma celor n numere
T2 - suma pătratelor celor n numere
S - cât ar trebui să fie suma de fapt
S2 - cât ar trebui să fie suma pătratelor */
#include <iostream>
#include <fstream>
ifstream fin("nr.in");
ofstream fout("nr.out");
using namespace std;

int main()
{
    int n,T=0,T2=0,S,S2,i,x,dif,dif2,suma,a,b;
    cin>>n;
    for(i=0;i<=n;i++) {
        cin>>x;
        T=T+x;
        T2=T2+x*x;
    }
    S=n*(n+1)/2; //T-a+b=S
    S2=n*(n+1)*(2*n+1)/6;
    dif=T-S; //a-b
    dif2=T2-S2; //a^2-b^2
    suma=dif2/dif; //(a^2-b^2)/(a-b), deci suma=a+b
    a=(suma+dif)/2; //(a+b+(a-b))/2
    b=suma-a;
    cout<<"Dublura: "<<a<<endl;
    cout<<"Lipseste: "<<b<<endl;
    return 0;
}
