#include <stdlib.h>
#include "stdafx.h"


int main()
{
	int s = 0, i, v[] = { 1,2,3,4 };
	for (i = 0; i < 4; i++) s += v[i];
	printf("int = %d bytes \n",sizeof(int));
	printf("char = %d bytes \n", sizeof(char));
	printf("s=%d\n", s);
	_asm {
		mov eax, 0; //s
		mov ebx, 0; //i
		lea ecx, v; //&v
	startFor: cmp ebx, 4;
		jae stopFor;
		mov edx, [ecx + 4*ebx]; //v[i]
		add eax, edx; //s += v[i];
		inc ebx;
		jmp startFor;
	stopFor: mov s, eax;
	}
	printf("s=%d\n", s);
    return 0;
}

