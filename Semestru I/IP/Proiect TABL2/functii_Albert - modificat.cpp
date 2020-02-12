#include <iostream>

using namespace std;

#define DMAX 100

struct vect {
    int lungime;
    int v[DMAX];
};

struct matrix {
    unsigned int linii,coloane;
    float m[DMAX][DMAX];
};

void citire_tastatura_matrice(matrix &x) {
    int i,j,n,m;
    //cout<<"Dati nr linii: ";
    cin>>n;
    cin>>m;
    x.linii = n;
    x.coloane = m;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
          cin>>x.m[i][j];
};

void citire_fisier();

void afisare_tastatura_matrice(matrix x) {
    int i,j;
    for(i=0;i<x.linii;i++) {
        for(j=0;j<x.coloane;j++)
            cout<<x.m[i][j]<<' ';
        cout<<endl;
        }
};

void afisare_fisier();

void adunare_vector(vect x, vect y); //Andreea

void adunare_matrice(matrix x, matrix y); //Andreea

void scadere_vector(vect x, vect y, vect &z) {

    int i;
    if (x.lungime != y.lungime) {
            cout<<"Vectorii trebuie sa aiba lungimi egale pentru operatia de scadere."<<endl;
        }
    else
        for(i=0;i<x.lungime;i++)
           z.v[i] = x.v[i] - y.v[i];

} //Albert

void scadere_matrice(matrix x, matrix y, matrix &z) {

    int i,j;
    if (x.linii != y.linii) {
            cout<<"Matricele trebuie sa aiba acelasi numar de linii pentru operatia de scadere."<<endl;
        }
    else
    if (x.coloane != y.coloane) {
            cout<<"Matricele trebuie sa aiba acelasi numar de coloane pentru operatia de scadere."<<endl;
        }
    else
    for(i=0;i<x.linii;i++)
        for(j=0;j<x.coloane;j++)
           z.m[i][j] = x.m[i][j] - y.m[i][j];

}; //Albert

void inmultire_vector(vect x,vect y); //Andreea

void inmultire_matrice(matrix x,matrix y,matrix &z){}; //Andreea

//void impartire_vector(vect x,vect y) {}; //Albert

void putere_vector(vect x, int putere); //Andreea

void transpusa_matrice(matrix x); //Andreea

void inverseaza_linii(matrix &x, unsigned int i, unsigned int j){
    int k;
    float aux;
    for(k=0;k<x.linii;k++) {
        aux=x.m[i][k];
        x.m[i][k]=x.m[j][k];
        x.m[j][k] = aux;
    }
};

void determinant_matrice(matrix x,float &determinant) {

    int i,j,k;
    float lambda;
    unsigned int nrInversari = 0;
    for(i=0;i<x.linii-1;i++){
        for(j=i;j<x.linii;j++)
            if(x.m[j][i]!=0){
                break;
                }

        if(j==x.linii) {
            determinant=0;
            break;
        }
        else {
            if(j!=i) {
                inverseaza_linii(x,i,j);
                nrInversari++;
                }
            for(j=i+1;j<x.linii;j++) {
                    lambda = x.m[j][i] / x.m[i][i];
                    for(k=0;k<x.coloane;k++)
                    x.m[j][k] = x.m[j][k] - lambda*x.m[i][k];
                  }
             determinant = nrInversari%2==0 ? 1 : -1;
             for(j=0;j<x.linii;j++)
                determinant*=x.m[j][j];
            }
       }
}; //Albert

void inmultire_scalar_matrice(matrix x, float scalar, matrix &y) {
    int i,j;
    for(i=0;i<x.linii;i++)
        for(j=0;j<x.coloane;j++)
            x.m[i][j]*=scalar;
};

/*void matrice_adjunta(matrix x, matrix &y) {

};

void inversare_matrice(matrix x, matrix &y) {

    float determinant;
    determinant_matrice(x,determinant);
    if(determinant!=0) {
        matrix adjuncta;
        matrice_adjunta(x,adjuncta);
        matrix y;
        inmultire_scalar_matrice(adjuncta,1/determinant,y);
    }
};*/

void matrice_identitate(matrix &x,bool esteVida) {
    unsigned int i;
    if(esteVida) {
        for(i=0;i<x.linii;i++)
            x.m[i][i]=1;
    }
};

void inversare_matrice(matrix x, matrix &y) {

    matrix inv;
    inv.linii = x.linii;
    inv.coloane = x.linii;

    bool vida = true;
    matrice_identitate(inv,vida);

    int i,j,k;
    float lambda = 0;
    bool numaiZerouri = false;
    bool inversabila = true;
    unsigned int nrInversari = 0;
    float elemNenul;

    for(i=0;i<x.coloane&&inversabila;i++){

        for(j=i;j<x.linii;j++)
            if(x.m[j][i]!=0){
                break;
                }

        if(j==x.linii) {
            cout<<"Matricea nu este inversabila";
            inversabila = false;
        }
        else {

            if(j!=i) {
                inverseaza_linii(x,i,j);
                inverseaza_linii(inv,i,j);
                nrInversari++;
                }
            elemNenul = x.m[i][i];

            for(j=0;j<x.coloane;j++) {
                x.m[i][j]/=elemNenul;
                inv.m[i][j]/=elemNenul;
                }
            for(j=i+1;j<x.linii&&inversabila;j++) {

                lambda = x.m[j][i] / x.m[i][i];

                numaiZerouri = true;

                for(k=0;k<x.coloane;k++) {
                    x.m[j][k] = x.m[j][k] - lambda*x.m[i][k];
                    inv.m[j][k] = inv.m[j][k] - lambda*inv.m[i][k];
                    if(x.m[j][k]!=0)
                        numaiZerouri = false;
                    }
                if(numaiZerouri){
                    cout<<"Matricea nu este inversabila";
                    inversabila=false;
                    }
                }
            }

        }
        if(inversabila){
            for(i=x.coloane-1;i>0;i--) {
                for(j=i-1;j>=0;j--){
                    lambda = x.m[j][i];
                    x.m[j][i]=0;
                    for(k=0;k<inv.coloane;k++) {
                            inv.m[j][k] = inv.m[j][k] - lambda*inv.m[i][k];
                        }
                }
            }
            y=inv;
       }

}

void impartire_matrice(matrix x,matrix y,matrix &rezultat) {
    matrix inversa;
    inversare_matrice(y,inversa);
    inmultire_matrice(x,inversa,rezultat);
}; //Albert

void putere_matrice(matrix &x,int putere) {

    unsigned int i;
    //if(putere==0)
    if(putere>0)
        for(i=2;i<=putere;i++)
            inmultire_matrice(x,x,x);
    if(putere<0) {
        putere=-putere;
        inversare_matrice(x,x);
        for(i=2;i<=putere;i++)
            inmultire_matrice(x,x,x);
    }
}; //Albert

void suma_elemente_vector(vect x); //Andreea

void produs_elemente_vector(vect x, int &produs) {
    int i;
    for(i=0;i<x.lungime;i++)
        produs *= x.v[i];
}; //Albert

void sortare_crescatoare_vector(vect x) {

}; //Albert

void sortare_descrescatoare_vector(vect x) {

}; //Albert

void shiftare_dreapta_vector(vect x); //Andreea

void shiftare_stanga_vector(vect x); //Andreea

void inmultire_vector_scalar(vect x); //Andreea

void suma_diag_principala(matrix x); //Andreea

void suma_sub_diag_principala(matrix x); //Andreea

void suma_diag_secundara(matrix x, int &suma) {
    int i;
    //MATRICE PATRATICA
    for(i=0;i<x.linii;i++)
        suma += x.m[i][x.linii-i];
}; //Albert

void suma_sub_diag_secundara(matrix x, int &suma){
    int i,j;
    //MATRICE PATRATICA
    for(i=1;i<x.linii;i++)
        for(j=x.coloane-i;j<x.coloane;j++)
            suma += x.m[i][j];
}; //Albert

int main()
{
    matrix x;

    citire_tastatura_matrice(x);
    cout<<"Matricea data este:"<<endl;
    afisare_tastatura_matrice(x);

    //int suma = 0;
    //suma_sub_diag_secundara(x,suma);
    //cout<<endl<<suma;

    float determinant=0;
    determinant_matrice(x,determinant);
    cout<<"determinantul matricei este: "<<determinant<<endl;

    cout<<"Matricea inversa este:"<<endl;

    matrix inversa;
    inversare_matrice(x,inversa);

    afisare_tastatura_matrice(inversa);
    return 0;
}
