/* S� se verifice dac� un num�r p dat este �deosebit� sau nu. Spunem c� p este �deosebit� dac� exist� q astfel �nc�t
p=q+s(q), �n care s(q) este suma cifrelor lui q. */
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
