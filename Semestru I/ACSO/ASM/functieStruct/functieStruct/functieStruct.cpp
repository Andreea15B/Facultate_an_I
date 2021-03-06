#include <stdio.h>
#include "stdafx.h"

struct MyStruct {
	int x;
	int z;
	char y;
	short t;

	MyStruct() { //constructor
		x = y = z = t = 0;
	}
};

/*int fill(MyStruct *ms, const char *text) {
	int  rez = 0;
	ms->x = 0; ms->y = 0; ms->z = 0; ms->t = 0;
	for (int i = 0; text[i] != '\0'; ++i) {
		if (text[i] == 'x') ms->x++;
		else if (text[i] == 'y') ms->y++;
		else if (text[i] == 'z') ms->z++;
		else if (text[i] == 't') ms->t++;
		else if (text[i] >= '0' && text[i] <= '9') rez++;
	}
	return rez;
}*/

int fill(MyStruct*, char*) {
	_asm {
		mov ebx, [ebp + 8]; //inceputul lui ms
		mov edx, [ebp + 12]; //inceputul lui text
		mov eax, 0; //rez=0
		mov esi, 0; //i=0
	startWhile: mov cl, [edx + esi];
		cmp cl, '\0';
		je stopWhile;
		cmp cl, 'x';
		je amGasitX;
		cmp cl, 'y';
		je amGasitY;
		cmp cl, 'z';
		je amGasitZ;
		cmp cl, 't';
		je amGasitT;
		cmp cl, '0'; //daca text[i] nu este cifra
		jl nexti; //jump lower
		cmp cl, '9'; //daca text[i] nu este cifra
		jg nexti; //jump greater
		inc eax; //rez++ daca text[i] este cifra
	nexti: inc esi; //i++
		jmp startWhile;
	amGasitX: inc dword ptr[ebx];
		jmp nexti;
	amGasitY: inc byte ptr[ebx + 8];
		jmp nexti;
	amGasitZ: inc dword ptr[ebx + 4];
		jmp nexti;
	amGasitT: inc word ptr[ebx + 10];
		jmp nexti;
	stopWhile:
	}
}

int main()
{
	MyStruct *ms;
	ms = new MyStruct;
	char text[] = "xxxxyyt123";
	int rez;
	//rez=fill(ms, text);
	_asm {
		lea ebx, text;
		push ebx;
		push ms;
		call fill;
		add esp, 8;
		mov rez, eax;
	}
	printf("x=%d\ny=%d\nz=%d\nt=%d\nrez=%d\n", ms->x, ms->y, ms->z, ms->t, rez);
    return 0;
}