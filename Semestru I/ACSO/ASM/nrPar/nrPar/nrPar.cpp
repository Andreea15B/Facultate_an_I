#include <stdio.h>
#include "stdafx.h"

int sumaNrPare(int *, int, int) {
	_asm {
		mov ecx, 0; //suma
		mov ebx, [ebp + 8]; //initializare matrice
		mov esi, 0; //i
	fori: cmp esi, [ebp + 12]; //n
		jae stopFori;
		mov edi, 0; //j
	forj: cmp edi, [ebp + 16]; //m
		jae stopForj;
		mov eax, [ebp + 12]; //n
		mul esi; //eax=eax*esi=i*n
		add eax, edi; //i*n+j

		mov eax, [ebx + eax * 4]; //m[i][j]=m[i*n+j]
		mov edx, 0; //initializare pentru div
		push eax;
		push ecx;
		mov ecx, 2;
		div ecx; //in eax catul si in edx restul //m[i][j] % 2
		pop ecx;
		pop eax;
		cmp edx, 1; // if (m[i][j] % 2 != 1)
		je nextj; //jmp daca impar
		add ecx, eax;
	nextj: inc edi; //j++
		jmp forj;

		/* mov eax, [ebx + eax * 4]; //m[i][j]=m[i*n+j]
		test eax, 1; // & pe biti //un nr par o sa aiba intotdeauna pe ultimul bit (cel mai nesemnificativ) 0
		jnz nextj; //daca e impar
		add ecx, eax; //suma += m[i][j]
		jmp nextj; 
	nextj: inc edi; //j++
		jmp forj; */
	stopForj: inc esi; //i++
		jmp fori;
	stopFori: mov eax, ecx; //suma
	}
}

int main()
{
	int m[3][3] = { 8,5,2,2,4,0,2,6,0 };
	int s = 0;
	s = sumaNrPare((int *)m, 3, 3);
	printf("%d\n", s);
	return 0;
}