/*O insectă poate urca 1 sau 2 trepte dintr-o scară cu n trepte. Să se afle nr de variante în care poate urca scara.
n=1: 1 mod
n=2: (1+1),(2) 2 moduri
n=3: (1+1+1),(1+2),(2+1) 3 moduri
n=4: (1+1+1+1),(1+1+2),(1+2+1),(2+1+1),(2+2) 5 moduri
n=5: (1+1+1+1+1),(1+1+1+2),(1+1+2+1),(1+2+1+1),(2+1+1+1),(2+2+1),(1+2+2),(2+1+2) 8 moduri
Fibonacci */
#include <iostream>

using namespace std;

int main()
{
    int n,a=1,b=1,c;
    cin>>n;
    for(int i=2;i<=n;i++) {
        c=a+b;
        a=b; b=c;
    }
    cout<<c<<'\n';
    return 0;
}
