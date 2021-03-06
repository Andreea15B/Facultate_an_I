#include <stdio.h>
#include "stdafx.h"

struct rect {
	int x, y; //colt stanga jos
	int width; //latimea
	int height; //inaltime
};

/*int intersectie(rect *r1, rect *r2) {
	if (r1->x < r2->x && r1->y < r2->y && r1->x - r1->width > r2->x - r2->width && r1->y - r1->height > r2->y - r2->height)
		return 2;
	else if (r2->x < r1->x && r2->y < r1->y && r2->x - r2->width > r1->x - r1->width && r2->y - r2->height > r1->y - r1->height)
		return 1;
	else return 0;
}*/

int intersectie(rect *r1, rect *r2) {
	_asm {
		mov ebx, [ebp + 8]; //rect1
		mov ecx, [ebp + 12]; //rect2
		mov eax, [ebx]; //r1->x
		cmp eax, [ecx]; //if (r1->x < r2->x)
		jl Caz1Cond2;
		cmp eax, [ecx]; //if (r1->x > r2->x)
		jg Caz2Cond2;
	Caz1Cond2: mov edx, [ebx + 4]; //r1->y
		cmp edx, [ecx + 4]; //if(r1->y < r2->y)
		jg nicioIntersectie;
		sub eax, [ebx + 8]; //eax = r1->x - r1->width
		mov edx, [ecx]; //r2->x
		sub edx, [ecx + 8]; //edx = r2->x - r2->width
		cmp eax, edx; //if(r1->x - r1->width > r2->x - r2->width)
		jl nicioIntersectie;
		mov edx, [ebx + 4]; //r1->y
		sub edx, [ebx + 12]; //edx = r1->y - r1->height
		mov eax, [ecx + 4]; //r2->y
		sub eax, [ecx + 12]; //eax = r2->y - r2.height 
		cmp edx, eax; //if(r1->y - r1->height > r2->y - r2->height)
		jl nicioIntersectie;
		mov eax, 2;
		jmp stop;
	Caz2Cond2: mov edx, [ecx + 4]; //r2->y
		cmp edx, [ebx + 4]; //if(r2->y < r2->y)
		jg nicioIntersectie;
		sub edx, [ecx + 12]; //edx = r2->y - r2->height
		mov eax, [ebx+4]; //r1->y
		sub eax, [ebx + 12]; //eax = r1->y - r1->height
		cmp edx, eax; //if(r2->y - r2->height > r1->y - r1->height)
		jl nicioIntersectie;
		mov edx, [ecx]; //r2->x
		sub edx, [ecx + 8]; //edx = r2->x - r2->width
		mov eax, [ebx]; //r1->x
		sub eax, [ebx + 8]; //eax = r1->x - r1->width
		cmp edx, eax; //if(r2->x - r2->width > r1->x - r1->width)
		jl nicioIntersectie;
		mov eax, 1;
		jmp stop;
	nicioIntersectie: mov eax, 0;
	stop:
	}
}

int main()
{
	rect r1, r2;
	r1.x = 200; r1.y = 200;
	r1.width = 200; r1.height = 200;
	r2.x = 100; r2.y = 100;
	r2.width = 10; r2.height = 10;
	int nr;
	nr = intersectie(&r1, &r2);
	printf("%d\n", nr);
    return 0;
}

