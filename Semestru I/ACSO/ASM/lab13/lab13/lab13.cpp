#include <stdio.h>
#include "stdafx.h"

struct MyStruct{
	char nrL;
	char nrC;
};

struct MyS {
	int x;
	char y;
	int z;
};

/*int Numara(int *m, MyS *s, int n) {
	int i, j;
	s->x = 0; s->z = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (m[i][j] == 0) {
				++s->x;
				continue;
			}
			if (m[i][j] == 7) {
				++s->z;
				continue;
			}
			m[i][j] = s->y;
		}
	}
	return 1;
}*/

/* int Numara(int*, MyS*, int) { neterminat
	_asm {
		mov ebx, [ebp + 8]; //matricea
		mov ecx, [ebp + 12]; //struct-ul
		mov esi, 0; //i
	startForI: cmp esi, [ebp + 16]; //if(i<n)
		jae stopForI;
		mov edi, 0; //j
	startForJ: cmp edi, [ebp + 16]; //if(j<n)
		jae stopForJ;
		mov eax, [epb + 16]; //n
		mul esi; //eax = eax*esi = n*i
		add eax, edi; //n*i+j
		cmp[ebx + eax * 4], 0; //if (matr[i][j] == 0)
		je incX;
		cmp[ebx + eax * 4], 7; //if (matr[i][j] == 7)
		je incZ;
		mov[ebx + eax * 4], byte ptr[ecx + 4]; //matr[i][j] == s->y
	incX: inc dword ptr[ecx];
		jmp startForJ;
	incZ: inc dword ptr[ecx + 8];
		jmp startForJ;
	stopForJ: inc esi;
		jmp startForI;
	stopForI:
	}
} */

int Numara2(int*, MyS*, int) {
	_asm {
		mov ebx, [ebp + 8];
		mov ecx, [ebp + 12];
		mov dword ptr[ecx], 0;
		mov dword ptr[ecx + 8], 0;
		mov esi, 0;
	forI: cmp esi, [ebp + 16];
		jae stopForI;
		mov edi, 0;
	forJ: cmp edi, [ebp + 16];
		jae stopForJ;
		mov eax, [ebp + 16];
		mul esi;
		add eax, edi;
		cmp dword ptr[ebx + 4 * eax],0;
		je cond0;
		cmp dword ptr[ebx + 4 * eax], 7;
		je cond7;
		mov edx, 0;
		mov dl, [ecx + 4]; //s.y
		mov[ebx + 4 * eax], edx; //nu putem scrie mov [],[]
	incJ: inc edi;
		jmp forJ;
	cond0: inc dword ptr[ecx];
		jmp incJ;
	cond7: inc dword ptr[ecx + 8];
		jmp incJ;
	stopForJ: inc esi;
		jmp forI;
	stopForI: mov eax, 1;
	}
}

int Numar(const char*, MyStruct*) {
	_asm {
		mov eax, 0; //i
		mov ebx, [ebp + 8]; //textul
		mov ecx, [ebp + 12]; //struct-ul
		mov byte ptr[ecx], 0; //s->nrL = 0
		mov byte ptr[ecx + 1], 0; //s->nrC = 0
	startWhile: mov bh, [ebx + eax]; //bh = x = text[i]
		cmp bh, '\0'; //if(x!=0)
		je stopWhile;
		cmp bh, '0'; //if(text[i]<0)
		jl verifLitera;
		cmp bh, '9'; //if(text[i]>9)
		jg verifLitera;
		inc byte ptr[ecx + 1]; //s->nrC++
	verifLitera: cmp bh, 'a';
		jl verifLiteraM;
		cmp bh, 'z';
		jg incEax; //i++
		inc byte ptr[ecx]; //s->nrL++
	verifLiteraM: cmp bh, 'A';
		jl incEax;
		cmp bh, 'Z';
		jg incEax;
		inc byte ptr[ecx]; //s->nrL++
	incEax: inc eax;
		jmp startWhile;
	stopWhile: 
	}
}

/*int Numar(const char* text, MyStruct* s) {
	int i;
	char x;
	i = 0;
	x = text[i];
	while(x != 0) {
		if (('a' <= text[i] && text[i] <= 'z') || ('A'<=text[i] && text[i]<='Z')) s->nrL++;
		else if ('0' <= text[i] && text[i] <= '9') s->nrC++;
		++i;
		x = text[i];
	}
	return i;
}*/

int main()
{
	MyS s;
	int i, j;
	s.y = 10;
	int matr[3][3] = { 0,0,7,7,1,0,1,1,1 };
	Numara2((int *)matr, &s, 3);
	printf("%d\n", s.x);
	printf("%d\n", s.z);
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) printf("%d ", matr[i][j]);
		printf("\n");
	}
    return 0;
}

