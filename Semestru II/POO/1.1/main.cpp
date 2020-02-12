#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    FILE* f;
    char line[100];
    int n = 100;
    int v[1000];
    int i = 0;

    f = fopen("numbers.txt","r");
    if(f == NULL) {
        printf("Eroare la deschiderea fisierului\n");
        return 0;
    }
    while(1) {
        if(fgets(line, 100, f) == NULL) {
            printf("Eroare la citire\n");
            break;
        }
        v[i++] = atoi(line);
    }
    if (fclose(f) != 0) printf("Eroare la inchiderea fisierului\n");
    int ok;
    do {
        ok=0;
        for(int j=0; j<i; j++) {
            if(v[j]>v[j+1]) {
                swap(v[j],v[j+1]);
                ok=1;
            }
        }
    } while(ok);
    for(int j=0; j<i; j++) cout<<v[j]<<" ";
}
