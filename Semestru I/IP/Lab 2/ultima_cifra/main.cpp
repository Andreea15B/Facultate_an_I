#include <iostream>

using namespace std;

int main()
{
    int a,b,uc[20][20],i,j; // uc[i][j] = uc a lui i^j
    cin>>a>>b;
    if(a%10==0 || a%10==1 || a%10==5 || a%10==6) cout<<a%10;
    else {
        uc[2][1]=2; uc[2][2]=4; uc[2][3]=8; uc[2][0]=6;
        uc[3][1]=3; uc[3][2]=9; uc[3][3]=7; uc[3][0]=1;
        uc[4][1]=4; uc[4][0]=6;
        uc[7][1]=7; uc[7][2]=9; uc[7][3]=3; uc[7][0]=1;
        uc[8][1]=8; uc[8][2]=4; uc[8][3]=2; uc[8][0]=6;
        uc[9][1]=9; uc[9][0]=1;
        if(a%10==2 || a%10==3 || a%10==7 || a%10==8) cout<<uc[a%10][b%4];
        if(a%10==4 || a%10==9) cout<<uc[a%10][b%2];
    }
    return 0;
}
