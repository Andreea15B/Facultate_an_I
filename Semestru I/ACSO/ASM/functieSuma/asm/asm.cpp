#include <stdio.h>
#include "stdafx.h"

//int suma(int a, int b) { return a + b; }
int suma(int, int) {
	_asm {
		mov eax, [ebp + 8];
		add eax, [ebp + 12];
	}
}
int main()
{
	int a = 2, b = 3,s;
	/*int s = suma(a, b);
	printf("s=%d\n", s);*/
	_asm {
		push b;
		push a;
		call suma;
		add esp, 8;
		mov s, eax;
	}
	printf("s=%d\n", s);
    return 0;
}

