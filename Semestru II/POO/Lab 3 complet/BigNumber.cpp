#include "BigNumber.h"
#include <iostream>
#include <cstring>
using namespace std;

BigNumber::BigNumber() {
    Number[0] = '0';
    Number[1] = 0;
    CharactersCount = 1;
}

BigNumber::BigNumber (int value) {
    if(value==0) {
        BigNumber();
        return;
    }
    CharactersCount = 0;
    while(value) {
        Number[CharactersCount++] = value%10+'0';
        value /= 10;
    }
    Number[CharactersCount] = 0;
}

BigNumber::BigNumber (const char * number) {
    int len = strlen(number);
    CharactersCount = 0;
    for(int i=len-1; i>=0; i--) Number[CharactersCount++] = number[i];
    Number[CharactersCount] = 0;
}

BigNumber::BigNumber (const BigNumber & number) {
    CharactersCount = number.CharactersCount;
    strcpy(Number,number.Number);
}

void BigNumber::Print() {
    for(int i=CharactersCount-1; i>=0; i--) cout<<Number[i];
    cout<<endl;
}

bool BigNumber::Set(int value) {
    if(value==0) {
        BigNumber();
        return true;
    }
    CharactersCount = 0;
    while(value) {
        Number[CharactersCount++] = value%10+'0';
        value /= 10;
    }
    Number[CharactersCount] = 0;
    return true;
}

bool BigNumber::Set(const char * number) {
    int len = strlen(number);
    if(len >= DMAX) return false;
    CharactersCount = 0;
    for(int i=len-1; i>=0; i--) Number[CharactersCount++] = number[i];
    Number[CharactersCount] = 0;
    return true;
}

BigNumber BigNumber::operator+ (const BigNumber & number) {
    int i = 0, t = 0, aux;
    char rezAdunare[DMAX+1];
    while(i<CharactersCount && i<number.CharactersCount) {
        aux = Number[i] - '0' + number.Number[i] - '0' + t;
        rezAdunare[i] = aux % 10 + '0';
        t = aux/10;
        i++;
    }
    while(i<CharactersCount) {
        aux = Number[i] - '0' + t;
        rezAdunare[i] = aux%10 + '0';
        t = aux/10;
        i++;
    }
    while(i<number.CharactersCount) {
        aux = number.Number[i] - '0' + t;
        rezAdunare[i] = aux%10 + '0';
        t = aux/10;
        i++;
    }
    if(t == 1) rezAdunare[i++] = '1';

    rezAdunare[i] = 0;

    for (int st = 0, dr = i - 1; st <= dr; st++, dr--) swap (rezAdunare[st], rezAdunare[dr]);

    if (strlen(rezAdunare) >= DMAX){
        cout << "Numbers too big.\n";
        exit(0);
    }

    BigNumber rez(rezAdunare);
    return rez;
}

BigNumber BigNumber::operator- (const BigNumber & number) {
    int i = 0, t = 0, aux;
    char rezAdunare[DMAX+1];
    while(i<CharactersCount && i<number.CharactersCount) {
        aux = Number[i] - '0' - (number.Number[i] - '0') + t;
        if(aux >= 0) {
            rezAdunare[i] = aux + '0';
            t = 0;
        }
        else {
            rezAdunare[i] = aux + 10 + '0';
            t = -1;
        }
        i++;
    }
    while(i<CharactersCount) {
        aux = Number[i] - '0' + t;
        if(aux >= 0) {
            rezAdunare[i] = aux + '0';
            t = 0;
        }
        else {
            rezAdunare[i] = aux + 10 + '0';
            t = -1;
        }
        i++;
    }
    rezAdunare[i] = 0;
    while(i>0 && rezAdunare[i-1] == '0') rezAdunare[--i] = 0;
    for (int st = 0, dr = i - 1; st <= dr; st++, dr--) swap (rezAdunare[st], rezAdunare[dr]);
    BigNumber rez(rezAdunare);
    return rez;
}

bool operator == (const BigNumber & n1, const BigNumber & n2) {
    if(n1.CharactersCount != n2.CharactersCount) return false;
    return (strcmp(n1.Number, n2.Number) == 0);
}

bool operator != (const BigNumber & n1, const BigNumber & n2) {
    return (strcmp(n1.Number, n2.Number) != 0);
}

bool operator < (const BigNumber & n1, const BigNumber & n2) {
    if(n1.CharactersCount < n2.CharactersCount) return true;
    if(n1.CharactersCount > n2.CharactersCount) return false;
    for(int i=n1.CharactersCount-1; i>=0; i--) {
        if(n1.Number[i] < n2.Number[i]) return true;
    }
    return false;
}

bool operator > (const BigNumber & n1, const BigNumber & n2){
    if(n1.CharactersCount > n2.CharactersCount) return true;
    if(n1.CharactersCount < n2.CharactersCount) return false;
    for(int i=n1.CharactersCount-1; i>=0; i--) {
        if(n1.Number[i] > n2.Number[i]) return true;
    }
    return false;
}

bool operator >= (const BigNumber & n1, const BigNumber & n2) {
    if(n1.CharactersCount > n2.CharactersCount) return true;
    if(n1.CharactersCount < n2.CharactersCount) return false;
    if(strcmp(n1.Number, n2.Number) == 0) return true;
    for(int i=n1.CharactersCount-1; i>=0; i--) {
        if(n1.Number[i] > n2.Number[i]) return true;
    }
    return false;
}

bool operator <= (const BigNumber & n1, const BigNumber & n2) {
    if(n1.CharactersCount < n2.CharactersCount) return true;
    if(n1.CharactersCount > n2.CharactersCount) return false;
    if(strcmp(n1.Number, n2.Number) == 0) return true;
    for(int i=n1.CharactersCount-1; i>=0; i--) {
        if(n1.Number[i] < n2.Number[i]) return true;
    }
    return false;
}

BigNumber::operator int() {
    int nr = 0, p = 1;
    for(int i=0; i<CharactersCount; i++) {
        nr += p*(Number[i] - '0');
        p *= 10;
    }
    return nr;
}

char BigNumber::operator[] (int index) {
    if(index<0 || index>=CharactersCount) return 0;
    return Number[CharactersCount-index-1];
}

BigNumber BigNumber::operator() (int start, int ending) {
    int i, nr = 0;
    if(start<0 || start>=CharactersCount || ending<0 || ending >=CharactersCount) return 0;
    if(start>ending) {
        for(i=start; i>=ending; i--) {
            nr = nr*10 + Number[CharactersCount - i - 1] - '0';
        }
    }
    else {
        for(i=start; i<=ending; i++) {
            nr = nr*10 + Number[CharactersCount - i - 1] - '0';
        }
    }
    BigNumber numar(nr);
    return numar;
}
