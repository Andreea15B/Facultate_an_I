#include <iostream>
#include <cmath>
using namespace std;
int prim(int a);
int oglindit(int a);
int main()
{
    int i;
    for(i=1000;i<10000;i++) {
        if(prim(i) && prim(oglindit(i))) cout<<i<<" ";
    }
    return 0;
}
int prim(int a) {
    int d;
    for(d=2;d<sqrt(a);d++) if(a%d==0) return 0;
    return 1;
}
int oglindit(int a) {
    int x=0;
    while(a>0) {
        x=x*10+a%10;
        a/=10;
    }
    return x;
}
