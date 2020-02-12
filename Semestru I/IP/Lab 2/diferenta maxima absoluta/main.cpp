/* Se citesc n numere reale. Să se afle diferența maximă absolută între oricare 2 numere.
Soluție: diferența absolută dintre minim și maxim */
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n,minim,maxim,i,a;
    cin>>n>>a;
    minim=maxim=a;
    for(i=1;i<n;i++) {
        cin>>a;
        if(a>maxim) maxim=a;
        if(a<minim) minim=a;
    }
    cout<<abs(maxim-minim);
    return 0;
}
