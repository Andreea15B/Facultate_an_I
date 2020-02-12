#include <iostream>

using namespace std;
int p[20]; //p[i]==0 daca i este prim
int main()
{
    int i,j,n,nr=1; //nr = cate nr prime sunt pana la n
    cin>>n;
    for(i=2;i*i<=n;i++) {
        if(p[i]==0) {
            nr++;
            for(j=2*i;j<=n;j+=i) p[j]=1;
        }
    }
    cout<<nr;
    return 0;
}
