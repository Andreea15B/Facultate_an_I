
#include "stdafx.h"
#include <stdio.h>
#include "math.h"

struct triunghi {
	unsigned int a;
	unsigned int b;
	unsigned int c;
};

unsigned int radical(unsigned int x) {
	return (unsigned int)(sqrt(x));
}

unsigned int aria(triunghi *) {
	_asm {
		mov ebx, [ebp + 8]; //struct
		mov eax, 0; //p
		add eax, dword ptr[ebx]; //s->a
		add eax, dword ptr[ebx + 4]; //s->b
		add eax, dword ptr[ebx + 8]; //s->c
		//eax = (s->a + s->b + s->c)

		mov edx, 0;
		push ebx;
		mov ebx, 2;
		div ebx; //p = eax = (s->a + s->b + s->c)/2
		pop ebx;

		mov ecx, eax; //p
		sub ecx, dword ptr[ebx]; //ecx = (p - s->a)
		mul ecx; //eax = eax*ecx = p*(p - s->a)

		add ecx, dword ptr[ebx]; //ecx = p+(p - s->a) = p
		sub ecx, dword ptr[ebx + 4]; //ecx = (p - s->b)
		mul ecx; //eax = eax*ecx = p*(p - s->a)*(p - s->b)

		add ecx, dword ptr[ebx+4]; //ecx = p+(p - s->b) = p
		sub ecx, dword ptr[ebx + 8]; //ecx = (p - s->c)
		mul ecx; //eax = eax*ecx = p*(p - s->a)*(p - s->b)*(p - s->c)

		push eax;
		call radical;
		add esp, 4;
	}
}

/*unsigned int aria(triunghi *s) {
	int p,A;
	p = (s->a + s->b + s->c) / 2;
	A = p*(p - s->a)*(p - s->b)*(p - s->c);
	A = radical(A);
	return A;
}*/

int main()
{
	triunghi s;
	s.a = 4;
	s.b = 5;
	s.c = 6;
	unsigned int A = aria(&s);
	printf("%d\n", A);
    return 0;
}