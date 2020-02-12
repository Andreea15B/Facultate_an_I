/* matrice cu m linii și n coloane. Determină dacă există un "punct șa". Dacă da, să se afișeze coordonatele sale și valoarea.
Este "punct șa" dacă este elementul minim de pe linia i și elementul maxim de pe coloana j. */
#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("pct.in");
int main()
{
    int i,j,maxim,minim,i_max,i_min,j_max,j_min,n,m,v[10][10];
    fin>>m>>n;
    for(i=0;i<m;i++) for(j=0;j<n;j++) fin>>v[i][j];
    for(i=0;i<m;i++) {
        minim=v[i][0]; j_min=0; i_min=0;
        for(j=1;j<n;j++) if(v[i][j]<minim) {
            minim=v[i][j]; i_min=i; j_min=j;
        }
        maxim=v[0][j_min]; j_max=j_min; i_max=0;
        for(j=1;j<m;j++) {
            if(v[j][j_min]>maxim) {
                maxim=v[j][j_min];
                i_max=j;
            }
        }
        if(i_min==i_max) cout<<i_min<<" "<<j_min<<" "<<v[i_min][i_max]<<endl;
    }
    return 0;
}
