#include <stdio.h>
#include "stdafx.h"


int main()
{
	int m[10][10],n=3,i=2,j=1;
	_asm {
		lea edi, m; //&m
		mov eax, n;
		mov ebx, i;
		mov ecx, j;
		mul ebx; //eax = eax*ebx = n*i
		add eax, ecx; //n*i+j
		//add edi, eax; //&m+n*i+j
		mov dword ptr[edi]+4*eax,5; //m[i][j]=&m+n*i+j = 5
	}
	printf("%d\n", m[i][j]);
    return 0;
}

