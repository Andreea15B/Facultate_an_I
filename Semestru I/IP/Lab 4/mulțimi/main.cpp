#include <iostream>
#define MAX_ELEM 50
using namespace std;
struct vector {
    unsigned int nrElemente;
    int elem[MAX_ELEM];
};
void citeste(vector &v, char nume);
void afisare(vector v, char nume);
vector reuniune(vector a, vector b, vector &c);
vector intersectie(vector a, vector b, vector &c);
bool apartine(int e, vector M);
int main()
{
    vector a,b,c;
    int nr;

    //apartinere:
    /*citeste(a,'a');
    cout<<"Numarul este: ";
    cin>>nr;
    if(apartine(nr,a)) cout<<"Apartine"<<endl;
    else cout<<"Nu apartine"<<endl;*/

    //reuniune:
    citeste(a,'a');
    citeste(b,'b');
    reuniune(a,b,c);
    afisare(c,'c');

    //intersectie:
    citeste(a,'a');
    citeste(b,'b');
    intersectie(a,b,c);
    afisare(c,'c');
    return 0;
}
vector intersectie(vector a, vector b, vector &c) {
    unsigned int i;
    c.nrElemente=0;
    for(i=0;i<a.nrElemente;i++) {
        if(apartine(a.elem[i],b)) c.elem[c.nrElemente++]=a.elem[i];
    }
    return c;
}
vector reuniune(vector a, vector b, vector &c) {
    unsigned int i;
    for(i=0;i<a.nrElemente;i++) c.elem[i]=a.elem[i];
    c.nrElemente=a.nrElemente;
    for(i=0;i<b.nrElemente;i++) {
        if(!apartine(b.elem[i],c)) {
            c.elem[c.nrElemente++]=b.elem[i];
        }
    }
    return c;
}
bool apartine(int e, vector M) {
    unsigned int i;
    for(i=0;i<M.nrElemente;i++) {
        if(e==M.elem[i]) return 1;
    }
    return 0;
}
void afisare(vector v, char nume) {
    unsigned int i;
    cout<<"Vectorul "<<nume<<" este: \n";
    for(i=0;i<v.nrElemente;i++) cout<<v.elem[i]<<",";
    cout<<endl;
}
void citeste(vector &v, char nume) {
    unsigned int i;
    cout<<"Dati nr de elemente ale lui "<<nume<<":";
    cin>>v.nrElemente;
    for(i=0;i<v.nrElemente;i++) {
        cout<<"Dati elementul nr "<<i<<" din "<<nume<<":";
        cin>>v.elem[i];
    }
}
