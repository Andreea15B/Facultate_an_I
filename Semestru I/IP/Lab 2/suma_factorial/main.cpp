// Se da n natural nenul. Sa se calculeze S=1!+2!+3!+…+n! folosind un singur „for”.
#include <iostream>

using namespace std;

int main()
{
    long long n,i,suma=1,x=1;
    cin>>n;
    for(i=2;i<=n;i++) {
        x*=i;
        suma+=x;
    }
    cout<<suma;
    return 0;
}
