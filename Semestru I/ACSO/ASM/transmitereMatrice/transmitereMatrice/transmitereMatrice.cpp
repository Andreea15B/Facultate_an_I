#include <stdio.h>
#include "stdafx.h"
#define L 10
#define C 20


int f(int m[][C]) {
	//returnarea lui m[0][0]
	_asm {
		mov eax, [ebp + 8]
		mov eax, [eax]
	}
}

int main()
{
	int m[L][C];
	m[0][0] = 1024000;
	int x = f(m);//vectorii si matricele se transmit prin referinta
	printf("%d\n", x); // se afiseaza 1024000
    return 0;
}

