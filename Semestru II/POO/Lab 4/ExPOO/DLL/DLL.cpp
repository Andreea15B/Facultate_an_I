// DLL.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "DLL.h"

const char* GetName() {
	return "Adunare";
}

int Compute(int a, int b) {
	return a + b;
}


