// https://vjudge.net/contest/194760#problem/B
#include <iostream>
#include <cmath>
#include <iomanip>
#include <fstream>
using namespace std;
ifstream fin("pi.in");
int cmmdc(int x,int y);
int main()
{
    int N,perechi_prime,perechi,nr[60],i,j;
    long double pi;
    cin>>N;
    while(N!=0) {
        perechi_prime=0; perechi=0;
        for(i=0;i<N;i++) cin>>nr[i];
        perechi = N*(N-1)/2;
        for(i=0;i<N-1;i++) {
            for(j=i+1;j<N;j++) if(cmmdc(nr[i],nr[j])==1) perechi_prime++;
        }
        if(perechi_prime==0) cout<<"No estimate for this data set.\n";
        else {
            pi=sqrt(6*(double)perechi/1.0/perechi_prime);
            cout<<fixed<<setprecision(6)<<pi<<endl;
        }
        cin>>N;
    }
    return 0;
}
int cmmdc(int x,int y) {
    int r;
    while(y!=0) {
        r=x%y;
        x=y;
        y=r;
    }
    return x;
}
