// nr de înmulțiri cu 2 a lui b este log2(a)
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a,b,suma=0,a1,b1;
    cin>>a>>b;
    a1=a; b1=b;
    while(a>0) {
        if(a%2==1) suma+=b;
        a/=2;
        b*=2;
    }
    cout<<suma<<" ";
    return 0;
}
