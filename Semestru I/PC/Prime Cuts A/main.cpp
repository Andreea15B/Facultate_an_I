// https://vjudge.net/problem/UVA-406
#include <fstream>
#include <iostream>

using namespace std;
ifstream fin("prime.in");
int p[1001]; //p[i]=0 daca i este prim
void ciur(int N);
int main()
{
    int N,C,prime[1001],i,lg=0,j;
    ciur(1001);
    while(cin>>N>>C) {
        cout<<N<<" "<<C<<":";
        j=0;
        for(i=1;i<=N;i++) if(p[i]==0) prime[j++]=i;
        lg=j;
        if(lg/2-C<0) for(i=0;i<lg;i++) cout<<" "<<prime[i];
        else {
            if(lg%2==0) for(i=lg/2-C;i<lg/2+C;i++) cout<<" "<<prime[i];
            else for(i=lg/2-C+1;i<lg/2+C;i++) cout<<" "<<prime[i];
        }
        cout<<endl<<endl;
    }
    return 0;
}
void ciur(int N) {
    int i,j;
    for(i=2;i<=N;i++) {
        if(p[i]==0) {
            for(j=i+i;j<=N;j=j+i) p[j]=1;
        }
    }
}
