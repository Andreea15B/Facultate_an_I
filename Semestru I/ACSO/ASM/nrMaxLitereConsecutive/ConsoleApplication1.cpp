#include <stdio.h>
#include "stdafx.h"

/*char GetMaxConsecutiveCharacter(char *s) {
	int i = 1, nr_max = 1, nr = 1;
	char lit;
	while (s[i] != '\0') {
		if (s[i] == s[i - 1]) nr++;
		if (s[i] != s[i - 1]) {
			if (nr > nr_max) {
				lit = s[i-1];
				nr_max = nr;
			}
			nr = 1;
		}
		++i;
	}
	return lit;
}*/

char GetMaxConsecutiveCharacter(char *s) {
	_asm {
		mov esi, 1; //i
		mov ebx, [ebp + 8]; //s
		mov ecx, 1; //nr_max
		mov edi, 1; //nr
	startWhile: mov dh, [ebx + esi]; //s[i]
		cmp dh, '\0'; //if(s[i]=='\0')
		je stopWhile;
		cmp dh, [ebx + esi - 1]; //if (s[i] != s[i - 1])
		jne notEqual;
		inc edi;
		inc esi;
		jmp startWhile;
	notEqual: cmp edi, ecx; //if (nr <= nr_max)
		jbe incEsiNr;
		mov al, [ebx + esi - 1]; //lit = s[i-1]
		mov ecx, edi; //nr_max = nr
		jmp incEsiNr;
	incEsiNr: inc esi;
		mov edi, 1; //nr = 1
		jmp startWhile;
	stopWhile:
	}
}

int main()
{
	char lit = GetMaxConsecutiveCharacter("a22aahhkkkkxxxwwii9");
	printf("%c\n", lit);
    return 0;
}

