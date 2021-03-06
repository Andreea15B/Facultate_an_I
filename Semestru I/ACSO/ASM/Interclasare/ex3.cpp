/*Tablourile src1 si src2 sunt ordonate crescător. Functia depune în tabloul dst elementele din tablourile
src1 si src2, astfel încât în final tabloul dst să fie ordonat crescător, si returnează numărul de elemente din
tabloul dst.*/
#include <stdio.h>
#include "stdafx.h"

/*int ic(int *src1, int n1, int *src2, int n2, int *dst) {
	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2) {
		if (src1[i] < src2[j]) dst[k] = src1[i++];
		else dst[k] = src2[j++];
		k++;
	}
	while (i < n1) dst[k++] = src1[i++];
	while (j < n2) dst[k++] = src2[j++];
	return k;
}*/

int ic(int *src1, int n1, int *src2, int n2, int *dst) {
	_asm {
		mov ebx, [ebp + 8]; //src1
		mov ecx, [ebp + 16]; //src2
		mov edx, [ebp + 24]; //dst
		mov esi, 0; //i
		mov edi, 0; //j
		mov eax, 0; //k
	while1: cmp esi, [ebp + 12]; //if(i<n1)
		jae stopWhile1;
		cmp edi, [ebp + 20]; //if(j<n2)
		jae stopWhile1;
		push eax;
		mov eax, [ecx + 4 * edi]; //src2[j]
		cmp [ebx + 4 * esi], eax; //if(src1[i] < src2[j])
		pop eax;
		jl put1;
		jmp put2; //else
	put1: push ecx;
		mov ecx, [ebx + 4 * esi]; //src1[i]
		mov[edx + 4 * eax], ecx; //dest[k] = src1[i]
		pop ecx;
		inc eax;
		inc esi;
		jmp while1;
	put2: push ebx;
		mov ebx, [ecx + 4 * edi]; //src2[j]
		mov[edx + 4 * eax], ebx; //dest[k] = src2[j]
		pop ebx;
		inc eax;
		inc edi;
		jmp while1;
	stopWhile1:
	}
}

int main()
{
	int src1[] = { 1,5,8,10 };
	int src2[] = { 0,2,4,8,12 };
	int dst[10], lungime;
	lungime = ic((int*)src1, 4, (int *)src2, 5, (int *)dst);
	printf("Lungime dst: %d\n", lungime);
	for (int i = 0; i < lungime; i++) printf("%d ", dst[i]);
    return 0;
}

