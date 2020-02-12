#include <iostream>
#include <fstream>
#define DMAX 100
using namespace std;
ifstream fin("lab.in");
struct maze {
    unsigned int lines,cols;
    int values[100][100];
};
struct poz{
    int lin,col;
}coada[DMAX],precedent,viitor;
unsigned int minRouteLength(maze magicMaze,poz plecare,poz iesire);
int main()
{
    int lungime,i,j;
    maze matrice;
    poz iesire,plecare;
    fin>>matrice.lines>>matrice.cols;
    for(i=0;i<matrice.lines;i++) for(j=0;j<matrice.cols;j++) fin>>matrice.values[i][j];
    fin>>plecare.lin>>plecare.col>>iesire.lin>>iesire.col;
    lungime=minRouteLength(matrice,plecare,iesire);
    cout<<lungime;
    return 0;
}
unsigned int minRouteLength(maze magicMaze,poz plecare,poz iesire) {
    if(magicMaze.values[plecare.lin][plecare.col]==1) return 0;
    int prim,ultim,k;
    int dl[]={-1,0,1,0},dc[]={0,1,0,-1};
    prim=ultim=0;
    coada[0]=plecare;
    magicMaze.values[plecare.lin][plecare.col]=1;
    while(prim<=ultim && magicMaze.values[iesire.lin][iesire.col]==0) {
        precedent=coada[prim++];
        for(k=0;k<4;k++) {
            viitor.lin=precedent.lin+dl[k];
            viitor.col=precedent.col+dc[k];
            if(viitor.lin>=0 && viitor.col>=0 && viitor.lin<magicMaze.lines && viitor.col<magicMaze.cols) {
                if(magicMaze.values[viitor.lin][viitor.col]==0) {
                    magicMaze.values[viitor.lin][viitor.col]=magicMaze.values[precedent.lin][precedent.col]+1;
                    ultim++;
                    coada[ultim]=viitor;
                }
            }
        }
    }
    /*for(int i=0;i<magicMaze.lines;i++) {
        for(int j=0;j<magicMaze.cols;j++) cout<<magicMaze.values[i][j]<<" ";
        cout<<endl;
    }*/
    if(magicMaze.values[iesire.lin][iesire.col]==0) return 0;
    return magicMaze.values[iesire.lin][iesire.col];
}
