#include "stdafx.h"
//#include "stdio.h"

int main()
{
	int x, y, z, t;
	scanf_s("%d", &x);
	scanf_s("%d", &y);
	scanf_s("%d", &z);
	scanf_s("%d", &t);
	int f = x*x + y + 10 * z + x / t;
	printf("f=%d\n", f);

	return 0;
}

