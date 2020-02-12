#include <iostream>

using namespace std;

int main()
{
    int n,copie,nr=0;
    cin>>n;
    copie=n;
    while(copie>0) {
        nr=nr*10+copie%10;
        copie/=10;
    }
    if(nr!=n) cout<<"Nu e palindrom";
    else cout<<"Este palindrom";
    return 0;
}
