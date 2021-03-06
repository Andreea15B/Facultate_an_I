// EXE.cpp : Defines the entry point for the console application.
//

#include <Windows.h>
#include <iostream>

using namespace std;

typedef const char* (*Func_GetName)();
typedef int(*Func_Compute)(int a, int b);

int main()
{
	Func_GetName GetName;
	Func_Compute Compute;

	char numeDLL[100];

	cout << "Dati numele DLL: ";
	cin >> numeDLL;

	HMODULE handleDLL = NULL;
	handleDLL = LoadLibraryA(numeDLL);

	if (handleDLL == NULL) {
		cout << "Incarcare esuata a librariei.\n";
		return 0;
	}

	GetName = (Func_GetName)GetProcAddress(handleDLL, "GetName");

	if (GetName == NULL) {
		cout << "Eroare la aflare adresa GetName.\n";
		return 0;
	}

	Compute = (Func_Compute)GetProcAddress(handleDLL, "Compute");

	if (Compute == NULL) {
		cout << "Eroare la aflare adresa Compute.\n";
		return 0;
	}

	cout << GetName() << endl;
	cout << Compute(8, 13) << endl;

    return 0;
}

