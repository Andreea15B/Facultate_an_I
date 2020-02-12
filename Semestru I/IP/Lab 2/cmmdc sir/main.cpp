#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmmdc.in");
int cmmdc(int a,int b);
int main()
{
    int n,a,b,c,x,i;
    fin>>n>>a>>b;
    c=cmmdc(a,b);
    for(i=1;i<=n;++i) {
        fin>>a;
        x=cmmdc(c,a);
        if(x==1) break; //nr prime intre ele
    }
    cout<<x;
    return 0;
}
int cmmdc(int a,int b) {
    int r;
    while(b>0) {
        r=a%b;
        a=b; b=r;
    }
    return a;
}
