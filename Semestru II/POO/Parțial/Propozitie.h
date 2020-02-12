#include <vector>
#include <iostream>
using namespace std;
class Propozitie
{
	char* txt;
	vector<char*> cuv;
public:
	Propozitie();
	~Propozitie();
	Propozitie(const char* text);
	void Create(const char* text);

	int GetNumberOfWords();
	bool Contains(const char* word, bool ignoreCase);

	friend char operator[](int pos); //operator de indexare
	friend operator<char*>(); //cast la string
};

