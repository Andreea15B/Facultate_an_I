#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("secv.in");
int main()
{
    int n,i,a,x,lung=1,l_max=1,ind_max=0,nr;
    fin>>n>>a;
    for(i=2;i<=n;i++) {
        fin>>x;
        if(a==x) lung++;
        else {
            if(lung>l_max) {
                l_max=lung;
                ind_max=i-lung;
                nr=a;
            }

            lung=1;
        }
        a=x;
    }
    cout<<l_max<<" "<<ind_max<<" "<<nr;
    return 0;
}
