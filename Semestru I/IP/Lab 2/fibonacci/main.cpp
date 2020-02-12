#include <iostream>

using namespace std;

int main()
{
    int n,a=0,b=1,c=0;
    cin>>n;
    cout<<a<<" ";
    while(c<=n) {
        cout<<b<<" ";
        c=a+b;
        a=b;
        b=c;
    }
    return 0;
}
