// Lab1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>

int main()
{
	/*int s,n;
	scanf_s("%d",&n);
	_asm {
	mov eax,0
	mov ecx,0
	for1: cmp ecx,n
	jae endfor
	add eax, ecx
	inc ecx
	jmp for1
	endfor: mov s, eax
	}
	printf("s=%d", s);*/
	/*char c[]="Ana are";
	int i;
	_asm {
		lea eax,c
		mov ecx,0
		nop
	len: mov bh, [eax+ecx]
		 cmp bh, '\0'
		 je stopwhile
		 inc ecx
		 jmp len
	stopwhile: mov i,ecx
	}
	printf("nr=%d\n", i);*/
	int s, v[] = { 1,2,3,4 };
	_asm {
		mov eax,0 //s=0
		mov ecx,0 //i=0
		lea ebx,v //&v
	for1: cmp ecx,4
		  jae endfor
		  mov edx,[ebx+4*ecx]
		  add eax,edx
		  inc ecx
		  jmp  for1
	endfor: mov s,eax
	}
	printf("s=%d\n", s);
    return 0;
}

