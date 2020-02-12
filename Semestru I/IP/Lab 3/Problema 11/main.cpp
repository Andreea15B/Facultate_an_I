#include <iostream>

using namespace std;
int p[100]; //p[i]==0 daca i prim
void ciur(int n);
//int prim(int n);
int main()
{
    int n,m,i,j,matr[100][100],x=1,k,a=1;
    cin>>n>>m;
    ciur(200);
    for(i=0;i<=n/2;i++) {
        for(j=i;j<=n-i-1;j++) {
            for(k=x+1;k<=200;k++) {
                if(p[k]==0) {
                    matr[i][j]=k;
                    x=k;
                    break;
                }
            }
        }
        for(j=i+1;j<=n-i-1;j++) {
            for(k=x+1;k<=200;k++) {
                if(p[k]==0) {
                    matr[j][n-i-1]=k;
                    x=k;
                    break;
                }
            }
        }
        for(j=n-i-2;j>=i;j--) {
            for(k=x+1;k<=200;k++) {
                if(p[k]==0) {
                    matr[n-i-1][j]=k;
                    x=k;
                    break;
                }
            }
        }
        for(j=n-i-2;j>=i+1;j--) {
            for(k=x+1;k<=200;k++) {
                if(p[k]==0) {
                    matr[j][i]=k;
                    x=k;
                    break;
                }
            }
        }
    }
    for(i=0;i<n;i++) {
        for(j=0;j<m;j++) cout<<matr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
/*int prim(int n) {
    int i;
    for(i=2;i<=sqrt(n);i++) if(n%i==0) return 0;
    return 1;
}*/
void ciur(int n){
    int i,j;
    for(i=2;i<=n;i++) {
        if(p[i]==0) {
            for(j=2*i;j<=n;j+=i) p[j]=1;
        }
    }
}
