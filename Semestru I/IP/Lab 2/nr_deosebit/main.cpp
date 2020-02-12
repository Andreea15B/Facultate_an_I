/* Sã se verifice dacã un numãr p dat este „deosebit” sau nu. Spunem cã p este „deosebit” dacã existã q astfel încât
p=q+s(q), în care s(q) este suma cifrelor lui q. */
#include <iostream>

using namespace std;
int suma_cif(int n);
int main()
{
    int p,deosebit=0,i;
    cin>>p;
    for(i=0;i<p;i++) {
        if(i+suma_cif(i)==p) {deosebit=1; break;}
    }
    if(deosebit) cout<<"Este deosebit: "<<i<<" + "<<suma_cif(i)<<'\n';
    else cout<<"Nu este deosebit.";
    return 0;
}
int suma_cif(int n) {
    int s=0;
    while(n>0) {
        s+=n%10;
        n/=10;
    }
    return s;
}
