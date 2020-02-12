#include <iostream>
#include <fstream>
#define DMAX 100
using namespace std;
ifstream fin("matrice.in");
void transformMatrix(int mat[DMAX][DMAX],int n,int m);
int main()
{
    int n,m,mat[DMAX][DMAX],i,j;
    fin>>n>>m;
    for(i=0;i<n;i++) for(j=0;j<m;j++) fin>>mat[i][j];
    transformMatrix(mat,n,m);
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) cout<<mat[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
void transformMatrix(int mat[DMAX][DMAX],int n,int m) {
    int i,j,k,mat2[DMAX][DMAX];
    for(i=0;i<n;i++) for(j=0;j<m;j++) mat2[i][j]=mat[i][j];
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) {
            if(mat2[i][j]==0) {
                for(k=0;k<n;k++) mat[k][j]=0;
                for(k=0;k<m;k++) mat[i][k]=0;
            }
        }
    }
}
