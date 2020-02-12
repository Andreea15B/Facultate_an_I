#include <iostream>

using namespace std;

int main()
{
    int n,i,j;
    cin>>n;
    for(i=1;i<=n;i++) {
        for(j=i;j<=n;j++) cout<<'_';
        for(j=i;j>=1;j--) cout<<j<<" ";
        cout<<endl;
    }
    for(i=n-1;i>=1;i--) {
        for(j=i;j<=n;j++) cout<<'_';
        for(j=i;j>=1;j--) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
