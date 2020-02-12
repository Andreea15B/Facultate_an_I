#include <cstring>
#include <stdio.h>
#include <iostream>
#include "BigNumber.h"

using namespace std;

BigNumber::BigNumber() {
    cout << "Constructor 1\n";
    Number[0] = 0;
    CharactersCount = 1;
}

BigNumber::BigNumber(int value) {
    cout << "Constructor 2\n";
    CharactersCount = sprintf(Number, "%d", value);
}

BigNumber::BigNumber(const char * number) {
    cout<< "Constructor 3\n";
    strcpy(Number, number);
    CharactersCount = strlen(number)+1;
}

BigNumber::BigNumber(const BigNumber & number) {
    cout<< "Constructor 4\n";
    strcpy(Number, number.Number);
    CharactersCount = strlen(number.Number)+1;
}

void BigNumber::PrintNumber() {
    cout << Number <<endl;
}

bool BigNumber::Set(int value) {
    CharactersCount = sprintf(Number, "%d", value);
}

bool BigNumber::Set(const char * number) {
    strcpy(Number, number);
    CharactersCount = strlen(number)+1;
}

bool operator== (const BigNumber & n1, const BigNumber & n2) {
    if(n1.CharactersCount != n2.CharactersCount) return false;
    if(!strcmp(n1.Number, n2.Number)) return true;
    return false;
}

BigNumber operator+ (const BigNumber & number) {
    int i;
    if(number.CharactersCount > this->CharactersCount) {

    }
}
