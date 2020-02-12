#include <iostream>

using namespace std;

int main()
{
    int n,o=0;
    cin>>n;
    while(n>0) {
        o=o*10+n%10;
        n/=10;
    }
    cout<<o;
    return 0;
}
