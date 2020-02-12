#include <iostream>
#include "Probl.h"
#include <algorithm> 

using namespace std;

int main() {
	try {
		int test = 20, test1 = 30, test2 = 10;
		Array<int> a(1);
		Array<int> b(10);
		a += test; a += test1;
		a.Insert(2, test2);
		b += 90; b += 100; b += 88;
		a.Insert(2, b);
		a.Sort();
		for(int i = 0; i < a.GetSize(); i++) cout <<i<<": "<<a[i] << endl;
	}
	catch (char const* msg) {
		cout << msg << endl;
	}
	// a = 20 30 10
	// b = 90 100 88
	// a = 20 30 90 100 88 10
	return 0;
}