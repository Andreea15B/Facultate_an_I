#include <iostream>

using namespace std;

int main()
{
    int n,x,suma=0,i,s;
    cin>>n;
    for(i=0;i<n-1;i++) {
        cin>>x;
        suma+=x;
    }
    s=n*(n+1)/2;
    cout<<s-suma;
    return 0;
}
