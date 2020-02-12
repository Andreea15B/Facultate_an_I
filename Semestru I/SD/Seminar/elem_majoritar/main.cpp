#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("elem.in");
int main()
{
    int a[100],n,i,nr=0,k=0,elem=-1;
    fin>>n;
    for(i=0;i<n;i++) fin>>a[i];
    for(i=0;i<n;i++) {
        if(k==0) {elem=a[i]; k=1;}
        else if(a[i]==elem) k++;
             else k--;
    }
    if(elem==-1) cout<<"Nu exista element majoritar";
    else {
        for(i=0;i<n;i++) if(a[i]==elem) nr++;
        if(nr>n/2) cout<<"Elementul majoritar este: "<<elem<<'\n';
    }
    return 0;
}
