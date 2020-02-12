/* succesorul unui element din submulțimea numerelor din 10 cifre distincte
- găsesc primul a[i] < a[i+1] (în exemplu 3)
- caut în șirul din dreapta prima valoare mai mare ca a[i] și le interschimb (4 8 5 3 2)
- inversez șirul din dreapta (9 1 6 7 0 4 2 3 5 8)*/
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("succesor.in");
int main()
{
    int n,a[100],i,ind,val,m_ind;
    fin>>n;
    for(i=0;i<n;i++) fin>>a[i];
    for(i=n-2;i>=0;i--) if(a[i]<a[i+1]) {ind=i; break;}
    for(i=ind+1;i<n;i++) if(a[i]>a[ind]) m_ind=i;
    swap(a[ind],a[m_ind]);
    int start=ind+1,stop=n-1;
    for(i=0;i<=(stop-start)/2;i++) swap(a[start+i],a[stop-i]);
    for(i=0;i<n;i++) cout<<a[i];
    return 0;
}
