#include <iostream>

using namespace std;

int main()
{
    int n,produs=1,i;
    float fractii=0,suma=1;
    cin>>n;
    for(i=1;i<=n/2;i++)
        fractii+=(float)1/(2*i);
    suma+=fractii;
    for(i=3;i<n+(n%2);i+=2) {
        produs*=i;
        suma+=produs;
    }
    cout<<fractii+produs;
    return 0;
}
