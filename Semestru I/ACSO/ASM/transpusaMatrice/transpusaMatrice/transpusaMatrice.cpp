#include <stdio.h>
#include "stdafx.h"

/*void transpusa(int *m, int n) {
	int i, j;
	for (i = 0; i < n; ++i) {
		for (j = 0; j < i; ++j) {
			aux = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = aux;
		}
	}
}*/

void transpusaMatrice(int *, int) {
	_asm {
		mov ebx, [ebp + 8]; //initializare matrice
		mov esi, 0; //i
	fori: cmp esi, [ebp + 12]; //if(i<n)
		jae stopFori;
		mov edi, 0; //j
	forj: cmp edi, esi; //if(j<i)
		jae stopForj;
		mov eax, [ebp + 12]; //n
		mul esi; //eax=eax*esi=i*n
		add eax, edi; //i*n+j
		mov ecx, [ebx + eax * 4]; //m[i][j]
		push eax;
		mov eax, [ebp + 12]; //n
		mul edi; //eax = eax*edi = n*j
		add eax, esi; //n*j+i
		mov edx, [ebx + eax * 4]; //m[j][i]
		mov [ebx + eax * 4], ecx; //m[j][i] = m[i][j]
		pop eax; //ramane in eax m[i][j]
		mov [ebx + eax * 4], edx; //m[i][j] = m[j][i]
		inc edi; //j++
		jmp forj;
	stopForj: inc esi; //i++
		jmp fori;
	stopFori: 
	}
}

int main()
{
	int m[3][3] = { 0,1,2,3,4,5,6,7,8 };
	transpusaMatrice((int*)m, 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) printf("%d ", m[i][j]);
		printf("\n");
	}
    return 0;
}

