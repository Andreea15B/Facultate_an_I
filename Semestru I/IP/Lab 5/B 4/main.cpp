#include <iostream>
#include <fstream>
#define DMAX 100
using namespace std;
ifstream fin("labirint.in");
struct poz{
    int lin,col;
}plecare,iesire,coada[DMAX],viitor,precedent;
int drum_minim(int matrice[DMAX][DMAX],int n,int m,poz plecare,poz iesire);
int main()
{
    int lungime,n,m,i,j,matrice[DMAX][DMAX];
    fin>>n>>m;
    for(i=0;i<n;i++) for(j=0;j<m;j++) fin>>matrice[i][j];
    fin>>plecare.lin>>plecare.col>>iesire.lin>>iesire.col;
    lungime=drum_minim(matrice,n,m,plecare,iesire);
    cout<<lungime;
    return 0;
}
int drum_minim(int matrice[DMAX][DMAX],int n,int m,poz plecare,poz iesire) {
    if(matrice[plecare.lin][plecare.col]==1) return 0;
    int prim,ultim,k;
    int dl[5]={1,0,-1,0},dc[5]={0,1,0,-1};
    prim=ultim=0;
    coada[0]=plecare;
    matrice[plecare.lin][plecare.col]=1;
    while(prim<=ultim && matrice[iesire.lin][iesire.col]==0) {
        precedent=coada[prim++];
        for(k=0;k<4;k++) {
            viitor.lin=precedent.lin+dl[k];
            viitor.col=precedent.col+dc[k];
            if(viitor.lin>=0 && viitor.lin<=n && viitor.col>=0 && viitor.col<=m) {
                if(matrice[viitor.lin][viitor.col]==0) {
                    matrice[viitor.lin][viitor.col]=matrice[precedent.lin][precedent.col]+1;
                    ultim++;
                    coada[ultim]=viitor;
                }
            }
        }
    }
    if(matrice[iesire.lin][iesire.col]==0) return 0;
    return matrice[iesire.lin][iesire.col];
}
