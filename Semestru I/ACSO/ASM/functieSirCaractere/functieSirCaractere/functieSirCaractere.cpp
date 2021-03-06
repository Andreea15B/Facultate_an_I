// returneaza lungimea primului cuvant din const char* si il pune in char*
#include <stdio.h>
#include "stdafx.h"

int copy(const char*, char*) {
	_asm {
		mov eax, 0; //i
		mov ecx, [ebp + 8];
		mov edx, [ebp + 12];
	startFor: mov bh, [ecx + eax]; //s[i]
		cmp bh, '\0';
		je stopFor;
		cmp bh, ' ';
		je stopFor;
		mov [edx + eax], bh; //o[i]=s[i]
		inc eax; //i++
		jmp startFor;
	stopFor: mov[edx + eax], '\0';
	}
}

int main()
{
	char s[] = "Ana are mere", o[10];
	int i;
	_asm {
		lea eax, s;
		lea ebx, o;
		push ebx;
		push eax;
		call copy;
		add esp, 8;
		mov i, eax;
	}
	printf("i=%d\n", i);
	printf("o=%s\n", o);
    return 0;
}