// Să se descompună n ca sumă de termeni distincți ai șirului Fibonacci.
#include <iostream>

using namespace std;
int v[100];
int fib(int n);
int main()
{
    int n,i,lung,suma[100],j=0;
    cin>>n;
    lung=fib(n);
    for(i=lung;i>=1 && n>0;--i) {
        if(v[i]<=n) {
            suma[j++]=v[i];
            n-=v[i];
        }
    }
    for(i=0;i<j-1;i++) cout<<suma[i]<<"+";
    cout<<suma[j-1];
    return 0;
}
int fib(int n) {
    int a=1,b=1,c=0,i=3;
    v[1]=v[2]=1;
    while(c<=n) {
        c=a+b;
        v[i++]=c;
        a=b; b=c;
    }
    return i-2;
}
