#include <stdio.h>
#include "stdafx.h"

void swap(int *, int *) {
	_asm {
		mov esi, [ebp + 8]; //&a
		mov eax, [esi]; // eax = *esi = *a
		mov edi, [ebp + 12]; //b
		mov ebx, [edi]; // ebx = *edi = *b
		mov [esi], ebx; // &a = b
		mov [edi], eax; // &b = a
	}
}

int main()
{
	int a = 2, b = 3;
	printf("%d %d\n", a, b);
	swap(&a, &b);
	printf("%d %d\n", a, b);
    return 0;
}

