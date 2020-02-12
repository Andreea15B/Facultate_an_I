#include "Propozitie.h"
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

Propozitie::Propozitie() {
    txt = nullptr;
}

Propozitie::Propozitie(const char* text) {
    Create(text);
}
Propozitie::~Propozitie() {
    erase(cuv);
}
char* operator[](int pos) {
    return cuv[pos];
}
bool Propozitie::Contains(const char* word, bool ignoreCase) {
    int i;
    if(ignoreCase == true) {
        for(i=0; i<strlen(word); i++) word[i] = word[i] - '0';
        for(auto it=cuv.begin(); i != cuv.end(); i++) {
            if(strcmp(*it, word)) return true;
        }
    }
    else {
        for(auto it=cuv.begin(); i != cuv.end(); i++) {
            if(strcmp(*it, word)) return true;
        }
    }
    return false;
}
void Propozitie::Create(const char* text) {
    int j=0, k=0;
    for(int i=0; i<strlen(text); i++) {
        if(text[i]!=' ') {
            cuv[j][k++] = text[i];
        }
        else j++;
    }
}
int Propozitie::GetNumberOfWords() {
    return cuv.size();
}
