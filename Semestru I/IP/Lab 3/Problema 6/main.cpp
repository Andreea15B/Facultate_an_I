#include <iostream>

using namespace std;
struct date{
    char nume[100],prenume[100];
    unsigned int ani,sex,punctaj; // sex 1 baiat si 0 fata
};
int main()
{
    int n,i,j=0,sortat=0,h;
    date concurent[200];
    int baieti[200];
    cin>>n;
    for(i=0;i<n;i++) {
        cin>>concurent[i].nume>>concurent[i].prenume>>concurent[i].ani>>concurent[i].sex>>concurent[i].punctaj;
        if(concurent[i].sex==1 && concurent[i].ani>=16 && concurent[i].ani<=20) baieti[j++]=i;
    }
    for(i=0;i<j;i++) {
        for(h=i+1;h<j-1;h++) {
            if(concurent[baieti[i]].punctaj < concurent[baieti[h]].punctaj) swap(baieti[i],baieti[h]);
        }
    }
    for(i=0;i<j;i++) {
        cout<<concurent[baieti[i]].nume<<" "<<concurent[baieti[i]].punctaj<<endl;
    }
    return 0;
}
