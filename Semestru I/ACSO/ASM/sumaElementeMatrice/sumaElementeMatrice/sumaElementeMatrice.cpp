#include <stdio.h>
#include "stdafx.h"

int suma(int *, int, int) {
	_asm {
		mov ecx, 0; //suma
		mov ebx, [ebp + 8]; //initializare matrice
		mov esi, 0; //i
	fori: cmp esi, [ebp + 12]; //if(i<n)
		jae stopFori;
		mov edi, 0; //j
	forj: cmp edi, [ebp+16]; //if(j<m)
		jae stopForj;
		mov eax, [ebp + 12]; //n
		mul esi; //eax=eax*esi=i*n
		add eax, edi; //i*n+j
		add ecx, [ebx + eax * 4]; //suma += m[i][j]
		inc edi; //j++
		jmp forj;
	stopForj: inc esi;
		jmp fori;
	stopFori: mov eax, ecx;
	}
}

int main()
{
	int m[3][3] = { 0,1,1,1,5,0,0,0,0 };
	int s = 0;
	s = suma((int*)m, 3, 3);
	printf("%d\n", s);
	return 0;
}