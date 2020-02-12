#include <iostream>
#include "Propozitie.h"
using namespace std;

int main()
{
	Propozitie p("Ana are mere");
	cout << p[1] << endl; // va afisa "are"
	cout << std::boolalpha << p.Contains("MeRE",true) << endl; // fa afisa true
	cout << std::boolalpha << p.Contains("ere",false) << endl; // fa afisa false
	cout << (char*)p << endl; // va afisa "Ana are mere"
	for (auto w: p)
	{
		cout << w << endl; // afiseaza pe rand "ana", "are" si "mere"
	}
	cout << p.GetNumberOfWords() << endl; // afiseaza 3
	return 1;
}
