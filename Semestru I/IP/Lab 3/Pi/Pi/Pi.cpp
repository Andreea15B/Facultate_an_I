#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double pi[20][20];
	int i, j, x=3;
	pi[0][1] = 4;
	for (j = 2; j <= 11; j++) {
		if (j % 2 == 0) pi[0][j] = (double)(pi[0][j - 1] - (double)(4 / x));
		else pi[0][j] = (double)(pi[0][j - 1] + (double)(4 / x));
		x += 2;
		cout << fixed << setprecision(9) << pi[0][j] << '\n';
	}
    return 0;
}

