#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,i,prim=1;
    cin>>n;
    if(n%2==0) prim=0;
    else
        for(i=3;i<sqrt(n);i+=2) {
            if(n%i==0) {prim=0; break;}
        }
    if(prim) cout<<"Este prim";
    else cout<<"Nu e prim";
    return 0;
}
