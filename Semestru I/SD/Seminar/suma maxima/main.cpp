// subsecvența cu suma maximă
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("sir.in");
int main()
{
    int n,a[100],i,poz=1,neg=1,maxim=-99999;
    fin>>n;
    for(i=0;i<n;i++) {
        fin>>a[i];
        if(a[i]<0) poz=0;
        else neg=0;
        if(a[i]>maxim) maxim=a[i];
    }
    if(poz==1) for(i=0;i<n;i++) cout<<a[i]<<" ";
    else {
        if(neg==1) cout<<maxim;
        else {
            int s1=0,s2=0,p1=0,p2=0,max1=0,max2=0;
            max1=a[0]; max2=a[n-1];
            for(i=0;i<n;i++) {
                s1+=a[i]; s2+=a[n-i-1];
                if(s1>max1) {max1=s1; p1=i;}
                if(s2>max2) {max2=s2; p2=n-i-1;}
            }
            for(i=p2;i<=p1;i++) cout<<a[i]<<" ";
        }
    }
    return 0;
}
