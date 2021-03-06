#include <stdio.h>
#include "stdafx.h"

struct MyStruct {
	int x;
	int z;
	char y;
	short t;
};

/*void fill(MyStruct *s) {
	s->x = 10;
	s->y = 11;
	s->z = 12;
	s->t = 13;
}*/

void fill(MyStruct*) {
	_asm {
		mov ebx, [ebp + 8]; //ebx contine acum inceputul structurii
		mov dword ptr[ebx], 10; //s->x = 10 DWORD este pentru int = 32 biti
		mov byte ptr[ebx + 8], 11; //s->y = 11 BYTE este pentru char = 8 biti
		mov dword ptr[ebx + 4], 12; //s->z = 12
		mov word ptr[ebx + 10], 13; //s->t = 13 WORD este pentru short = 16 biti
	}
}

int main()
{
	MyStruct *s;
	s = new MyStruct;
	//fill(s);
	_asm {
		push s;
		call fill;
		add esp, 4;
	}
	printf("x=%d\ny=%d\nz=%d\nt=%d\n", s->x, s->y, s->z, s->t);
    return 0;
}

