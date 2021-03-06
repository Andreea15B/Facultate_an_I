#include <stdio.h>
#include "stdafx.h"

/*int produs(int *v) {
int i = 0, suma=0, medie, produs=1, j;
while (v[i] != 0) {
suma += v[i];
++i;
}
medie = suma / i;
for (j = 0; j < i; j++) {
if(v[j]<medie) produs *= v[j];
}
return produs;
}*/

int produs(int *) {
	_asm {
		mov ebx, [ebp + 8]; //v
		mov esi, 0; //i
		mov eax, 0; //suma
	while1: mov ecx, [ebx + 4 * esi]; //v[i]
		cmp ecx, 0; //if(v[i]==0)
		je stopWhile;
		add eax, ecx; //suma += v[i];
		inc esi; //++i
		jmp while1;
	stopWhile:
		mov edx, 0;
		div esi; //eax = eax/esi = suma/i in eax
		mov edi, 0; //j
		mov edx, eax; //media
		mov eax, 1; //produs
	for1: cmp edi, esi; //if(j>=i)
		jae stopFor;
		mov ecx, [ebx + 4 * edi]; //v[j]
		cmp ecx, edx; //if(v[j]>=medie)
		jae incremEdi;
		push edx;
		mul ecx; //eax = eax*ecx = produs*v[j]
		pop edx;
		jmp incremEdi;
	incremEdi: inc edi; //++j
		jmp for1;
	stopFor:
	}
}

int main()
{
	int v[6] = { 1,3,5,7,8,0 };
	int pr = produs((int *)v);
	printf("%d\n", pr);
	return 0;
}