// Calculate Pi Using an Infinite Series
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	float pi[21][21],x=3.0;
	int i,j;
	pi[0][1]=4;
	for (j=2;j<=20;j++) {
		if (j%2==0) pi[0][j]=pi[0][j-1]-4/x;
		else pi[0][j]=pi[0][j-1]+4/x;
		x += 2;
	}
	for(i=1;i<=20;i++) {
        for(j=1;j<=20-i;j++) {
            pi[i][j]=(0.5)*(pi[i-1][j]+pi[i-1][j+1]);
        }
	}
	cout<<fixed<<setprecision(9)<<pi[10][10]<<endl;
    return 0;
}
