#include <stdlib.h>
#include "stdafx.h"


int main()
{
	char c[] = "Ana are";
	int i = 0;
	while (c[i] != '\0') i++;
	printf("i=%d\n", i);
	_asm {
		lea eax, c; //&c //Daca aveam char *c="Ana are", aici scriam mov eax,c;
		mov ecx, 0; //i
	len: mov bh, [eax + ecx]; //c[i]
		cmp bh, '\0';
		je stopwhile;
		inc ecx;
		jmp len;
	stopwhile: mov i, ecx;
	}
	printf("i=%d\n", i);
	return 0;
}

