#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("inversa.in");
int calcul_det(int **matr,int n);
int **calcul_minor(int **matr,int lin,int col,int n);
int **calcul_inversa(int **matr,int n);
int main()
{
    int i,j,det,n;
    fin>>n;
    int **matr=new int*[n];
    for(i=0;i<n;i++) matr[i]=new int[n];
    for(i=0;i<n;i++) for(j=0;j<n;j++) fin>>matr[i][j];
    det=calcul_det(matr,n);
    cout<<det<<endl;
    if(det==0) cout<<"Nu e inversabila.";
    else {
        int **inversa=calcul_inversa(matr,n);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++) {
                if(inversa[i][j]%det==0) cout<<inversa[i][j]/det<<" ";
                else if(inversa[i][j]<0 && det<0) cout<<-inversa[i][j]<<"/"<<-det<<" ";
                else cout<<inversa[i][j]<<"/"<<det<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
int **calcul_inversa(int **matr,int n) {
    int **rez=new int *[n],i,j,**minor,k,p;
    for(i=0;i<n;i++) rez[i]=new int[n];
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            minor=calcul_minor(matr,j,i,n);
            rez[i][j]=((i+j)%2?1:-1)*calcul_det(minor,n-1);
        }
    }
    return rez;
}
int calcul_det(int **matr,int n) { //recursiv
    if(n==1) return matr[0][0];
    int i,s=0;
    for(i=0;i<n;i++) s+=matr[0][i]*(i%2?1:-1)*calcul_det(calcul_minor(matr,0,i,n),n-1);
    return s;
}
int **calcul_minor(int **matr,int lin,int col,int n) {
    int i,j,**a=new int*[n-1];
    for(i=0;i<n-1;i++) a[i]=new int[n-1];
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-1;j++) {
            if(i<lin) {
                if(j<col) a[i][j]=matr[i][j];
                else a[i][j]=matr[i][j+1];
            }
            else if(j<col) a[i][j]=matr[i+1][j];
            else a[i][j]=matr[i+1][j+1];
        }
    }
    return a;
}
