#include <stdio.h>
#include "stdafx.h"

int lungime(const char*) {
	_asm {
		mov eax, [ebp + 8];//&c Folosim mov, nu lea, pentru ca e deja pointer (c este alocat dinamic, nu static).
		mov ecx, 0; //i
	start: mov bh, [eax + ecx] //c[i]
			cmp bh, '\0'
			je stop
			inc ecx
			jmp start
	stop: mov eax, ecx;
	}
}

int main()
{
	char c[] = "Ana are";
	int i;
	_asm {
		lea eax, c;
		push eax;
		call lungime;
		add esp, 4;
		mov i, eax;
	}
	printf("i=%d\n", i);
    return 0;
}

