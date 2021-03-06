#include <stdio.h>
#include "stdafx.h"

void compute(int *, int) {
	_asm {
		mov ebx, [ebp + 8]; //initializare matrice
		mov esi, 0; //i
	fori: cmp esi, [ebp + 12]; //if(i<n)
		jae stopFori;
		mov edi, 0; //j
	forj: cmp edi, [ebp + 12]; //if(j<n)
		jae stopForj;
		mov eax, [ebp + 12]; //n
		mul esi; //eax = eax*esi = i*n
		add eax, edi; //i*n+j
		mov ecx, esi; //i
		add ecx, edi; //i+j
		mov [ebx + 4 * eax], ecx; //m[i][j]=m[i*n+j]=i+j
		inc edi; //j++
		jmp forj;
	stopForj: inc esi; //i++
		jmp fori;
	stopFori:
	}
}

int main()
{
	int x[3][3];
	compute((int*)x, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) printf("%d ", x[i][j]);
		printf("\n");
	}
    return 0;
}