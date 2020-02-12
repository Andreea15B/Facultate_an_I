#include <iostream>
#include <fstream>
#include <graphics.h>
#define DMAX 100
using namespace std;
ifstream fin("tabl.in");
ofstream fout("tabl.out");
struct vect {
    int lungime;
    int elem[DMAX];
    int x,y;
    bool afisatOrizontal = false;
};
struct matrix {
    int linii,coloane;
    float elem[DMAX][DMAX];
    int x,y;
};

void citire_tastatura_vect(vect &x);
void citire_tastatura_matr(matrix &x);
void citire_fisier_vect(vect &x);
void citire_fisier_matr(matrix &x);
void afisare_ecran_vect(vect x);
void afisare_ecran_matr(matrix x);
void afisare_fisier_vect(vect x);
void afisare_fisier_matr(matrix x);
void adunare_vector(vect x, vect y, vect &z); //Andreea - facut
void adunare_vector_grafica(vect v1, vect v2, vect &v3); //Andreea - facut
void adunare_matrice(matrix x, matrix y, matrix &z); //Andreea - facut
void produs_scalar(vect x, vect y, int &suma); //Albert - facut
void produs_scalar_grafica(vect x, vect y, int &suma); //Albert - facut
void produs_vectorial(vect x, vect y, vect &z); //Albert - facut
void produs_vectorial_grafica(vect x, vect y, vect &z); //Albert - facut
void adunare_matrice_grafica(matrix matrix1, matrix matrix2, matrix &matrix3); //Andreea - facut
void scadere_matrice_grafica(matrix matrix1, matrix matrix2, matrix &matrix3); //Andreea - facut
void inmultire_matrice(matrix matrix1, matrix matrix2, matrix &matrix3); //Andreea - facut
void inmultire_matrice_grafica(matrix x, matrix y, matrix &z); //Albert
void putere_vector(vect x, int putere, vect &z); //Andreea - facut
void transpusa_matrice(matrix x, matrix &z); //Andreea - facut
void transpusa_grafica(matrix m1, matrix &m2); //Andreea
int suma_elemente_vector(vect x); //Andreea - facut
void suma_elemente_vector_grafica(vect v1); //Andreea - facut
void shiftare_dreapta_vector(vect x, vect &z, int nr_poz); //Andreea - facut
void shiftare_stanga_vector(vect x, vect &z, int nr_poz); //Andreea - facut
void shiftare_stanga_vector_grafica(vect x, vect &z, int nr_poz); //Albert
void shiftare_dreapta_vector_grafica(vect x, vect &z, int nr_poz); //Albert
void inmultire_vector_scalar(vect x, vect &z, int scalar); //Andreea - facut
void inmultire_scalar_vector_grafica(vect v1, int scalar, vect v2); //Andreea - facut
int suma_diag_principala(matrix x); //Andreea - facut
int suma_sub_diag_principala(matrix x); //Andreea - facut
void suma_diag_principala_grafica(matrix m1); //Andreea - facut
void suma_sub_diag_principala_grafica(matrix m1); //Andreea - facut
void suma_deasupra_diag_principala_grafica(matrix m1); //Andreea
int suma_deasupra_diag_principala(matrix x); //Andreea - facut
int calcul_det(int **matr, int n); //Andreea - facut
int **calcul_minor(int **matr, int lin, int col, int n); //Andreea - facut
int **calcul_inversa(int **matr, int n); //Andreea - facut
void scadere_vector(vect x, vect y, vect &z); //Albert - facut
void scadere_vector_grafica(vect v1, vect v2, vect &v3); //Andreea - facut
void scadere_matrice(matrix x, matrix y, matrix &z); //Albert - facut
void inverseazaLinii(matrix &x, unsigned int i, unsigned int j); //Albert - facut
void determinant_matrice(matrix x, float &determinant); //Albert - facut
void afiseazaInmmultireCoeficient(float coeficient,int x,int y,int timeDelay); //Albert
void stergeInmultireCoeficient(float coeficient,int x,int y,int timeDelay); //Albert
void determinant_matrice_grafica(matrix matrix1, float &determinant); //Albert
void inmultire_scalar_matrice(matrix x, float scalar, matrix &y); //Albert - facut
void inmultire_scalar_matrice_grafica(matrix x, float scalar, matrix &y);
void impartire_matrice(matrix x, matrix y, matrix &rezultat); //Albert - facut
void matrice_identitate(matrix &x); //Albert - facut
void inversare_matrice(matrix x, matrix &y, bool &inversabila); //Albert - facut
void putere_matrice(matrix x, int putere, matrix &z); //Albert - facut
void putere_matrice_grafica(matrix m1, int putere, matrix &m2); //Andreea
int produs_elemente_vector(vect x); //Albert - facut
void produs_elemente_vector_grafica(vect x); //Andreea - facut
int suma_diag_secundara(matrix x); //Albert - facut
void suma_diag_secundara_grafica(matrix m1); //Andreea - facut
int suma_sub_diag_secundara(matrix x); //Albert - facut
void bubbleSort_grafica(vect v1); //Andreea - facut

void bubbleSortCrescator(vect x, vect &z); //Andreea - facut (complexitate O(n^2) caz nefavorabil)
void bubbleSortDescrescator(vect x, vect &z); //Andreea - facut (complexitate O(n^2) caz nefavorabil)
void sortareInsertieCrescator(vect x, vect &z); //Andreea - facut (complexitate O(n^2) caz nefavorabil)
void sortareInsertieDescrescator(vect x, vect &z); //Andreea - facut (complexitate O(n^2) caz nefavorabil)
void sortareSelectieNaivaCrescator(vect x, vect &z); //Andreea - facut(complexitate O(n^2) in toate cazurile)
void sortareSelectieNaivaDescrescator(vect x, vect &z); //Andreea - facut(complexitate O(n^2) in toate cazurile)
void mergeSortCrescator(vect &x, int st, int dr); //Andreea - facut (complexitate O(n*log n))
void mergeArraysCrescator(vect &x, int st, int mijl, int dr); //Andreea - facut
void sortare_numarare(vect x, vect &b); //Andreea - facut (complexitate O(k+n))

void borders_and_lines(int n, int m, int x, int y); //Andreea - facut
void afisare_ecran_matrice_grafica(matrix m1, int color); //Andreea - facut
void afisare_ecran_vector_grafica_orizontala(vect x, int color); //Albert - facut
void putNumber(float nr,int x,int y, int color, int time_delay); //Andreea - facut

void coloreazaLinieMatrice(int linie, matrix matriceAfisata, int culoare, int time_delay); //Albert - facute
void coloreazaColoanaMatrice(int coloana, matrix matriceAfisata, int culoare, int time_delay); //Albert
void inversare_matrice_grafica(matrix matrix1, matrix &matrix2, bool &inversabila); //Albert
void inverseaza_linii_douaMatrici_grafica(matrix &matrix1, matrix &matrix2, unsigned int i, unsigned int j); //Albert
void inverseaza_linii(matrix &x, unsigned int i, unsigned int j); //Albert
void imparte_linie_la_scalar_douaMatrici(int linie, float scalar, matrix &matrix1, matrix &matrix2); //Albert
void obtine_zero_pe_coloana_sub_linie_douaMatrici_grafica(int coloana, int linie, matrix &matrix1, matrix &matrix2, bool &inversabila); //Albert
void obtine_zero_deasupra_diagonalei_douaMatrici_grafica( matrix &matrix1, matrix &matrix2); //Albert
void obtine_zero_pe_coloana_deasupra_linie_douaMatrici_grafica(int coloana, int linie, matrix &matrix1, matrix &matrix2); //Albert
void aduna_linie_ori_coeficient_la_linie_douaMatrici_grafica(int linieDeAdunat, float coeficient, int linieLaCareSeAduna, matrix &matrix1, matrix &matrix2); //Albert
void cautaPozitieLinieElemNenulInColoana_grafica(matrix matrix1, int coloana, int &pozitie); //Albert
void inverseaza_linii_grafica(matrix &matrix1, unsigned int i, unsigned int j); //Albert
void obtine_zero_pe_coloana_sub_linie_grafica(int coloana,int linie, matrix &matrix1); //Albert
void stergeCalculareaCoeficientului(float deimpartit, float impartitor, int x, int y, int culoareFundal, int timeDelay); //Albert
void afiseazaCalculareaCoeficientului(float deimpartit, float impartitor, int x, int y, int culoare, int timeDelay); //Albert
void aduna_linie_ori_coeficient_la_linie_grafica(int linieDeAdunat, float coeficient, int linieLaCareSeAduna, matrix &matrix1, int coloanaPt0); //Albert
void stergeInmultireSemn(int numarInversiuni,float determinant,int x,int y,int timeDelay); //Albert
void stergeInmultireCoeficient(float coeficient, int x, int y, int timeDelay); //Albert
void toString(float number, char convertedString[4]); //Albert
int nr_cifre(float number); //Albert
void interchimba(float &a,float &b); //Albert
void interchimba(int &a,int &b); //Albert
void inverseaza(unsigned int number, unsigned int &invers); //Albert
void afiseazaInmultireSemn(unsigned int numarInversiuni, float determinant, int x, int y, int timeDelay); //Albert
void afiseazaInmultireCoeficient(float coeficient, int x, int y, int timeDelay); //Albert
float trunchiaza(float x); //Albert - facut
void coloreazaDiagonalaPrincipalaMatrice(matrix &matriceDeColorat, int culoare, int timeDelay); //Albert
void coloreazaColoanaIncompletaMatrice(int coloana, int linieStart, int linieSfarsit, matrix matriceDeColorat, int culoare, int time_delay); //Albert
void coloreazaLinieIncompletaMatrice(int linie, int coloanaStart, int coloanaSfarsit, matrix matriceDeColorat, int culoare, int time_delay); //Albert
void coloreazaElemVector(vect v1,int indice,int color,int timeDelay); //Albert - facut
void delElemVector(vect v1, int indice, int timeDelay); //Albert - facut
void stergeElemMatrice(matrix matrix1,int linie,int coloana,int time_delay); //Albert - facut

void citire_tastatura_afisare_matrice(matrix &m1, int x, int y, int color); //Andreea - facut
void citire_fisier_afisare_matrice(matrix &m1, int x, int y, int color); //Andreea - facut
void citire_tastatura_afisare_vector_orizontala(vect &v1, int x, int y, int color); //Albert - facut
void citire_tastatura_afisare_vector_verticala(vect &v1, int x, int y, int color); //Albert - facut
void citire_fisier_afisare_vector_orizontala(vect &v1, int x, int y, int color); //Albert - facut
void citire_fisier_afisare_vector_verticala(vect &v1, int x, int y, int color); //Albert - facut
int meniu_tastaturaSauFisierMatrice(); //Andreea - facut
int meniu_tastaturaSauFisierVector(); //Andreea - facut
int meniu_vectorSauMatrice(); //Andreea - facut
int meniu_functiiVectori(); //Andreea - facut
int meniu_functiiMatrice(); //Andreea - facut
void mesajTastatura(); //Andreea - facut
void buton_intoarcere(); //Andreea - facut
void clean(); //Albert - facut

int main()
{
    initwindow(1000,1000);

    vect v1,v2,v3;
    matrix m1,m2,m3;
    m1.x=30; m1.y=30; m2.x=300; m2.y=30;
    bool vectSauMatr; //0 daca vector, 1 daca matrice
    unsigned int functieApelataVector; //0 daca adunare, 1 scadere, 2 produs scalar, 3 produs vectorial, 4 suma, 5 shift dreapta, 6 shift stanga, 7 scalar, 8 produs, 9 sort, 10 inapoi
    unsigned int functieApelataMatrice; //0 daca adunare, 1 scadere, 2 inmultire, 3 putere, 4 transpusa, 5 diagonala principala, 6 sub diagonala principala, 7 deasupra, 8 diagonala secundara, 9 determinant, 10 inversa, 11 scalar, 12 inapoi
    unsigned int tastaturaSauFisier; //0 daca tastatura, 1 daca fisier, 2 inapoi
    meniuVectSauMatr: vectSauMatr = meniu_vectorSauMatrice();
    if(vectSauMatr==0) {
        meniuFunctiiVect: functieApelataVector = meniu_functiiVectori();
        if(functieApelataVector==10) {
            cleardevice();
            goto meniuVectSauMatr;
        }
        meniuTastaturaSauFisierVect: tastaturaSauFisier = meniu_tastaturaSauFisierVector();
        if(tastaturaSauFisier==2) {
            cleardevice();
            goto meniuFunctiiVect;
        }
        switch(functieApelataVector) {
            case 0: { //adunare - facut
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    v1.x = 30; v1.y = 30;
                    citire_tastatura_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    v2.y = v1.y; v2.x = v1.x+80+40;
                    citire_tastatura_afisare_vector_verticala(v2,v2.x,v2.y,WHITE);
                    adunare_vector_grafica(v1,v2,v3);
                }
                else {
                    cleardevice();
                    v1.x = 30; v1.y = 30;
                    citire_fisier_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    v2.y = v1.y; v2.x = v1.x+80+40;
                    citire_fisier_afisare_vector_verticala(v2,v2.x,v2.y,WHITE);
                    adunare_vector_grafica(v1,v2,v3);
                }
                goto butonVect;
            }
            case 1: { //scadere - facut
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    v1.x = 30; v1.y = 30;
                    citire_tastatura_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    v2.y = v1.y; v2.x = v1.x+80+40;
                    citire_tastatura_afisare_vector_verticala(v2,v2.x,v2.y,WHITE);
                    scadere_vector_grafica(v1,v2,v3);
                }
                else {
                    cleardevice();
                    v1.x = 30; v1.y = 30;
                    citire_fisier_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    v2.y = v1.y; v2.x = v1.x+80+40;
                    citire_fisier_afisare_vector_verticala(v2,v2.x,v2.y,WHITE);
                    scadere_vector_grafica(v1,v2,v3);
                }
                goto butonVect;
            }
            case 2: {//produs_scalar - facut
                int rezultat = 0;
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    v1.x = 30; v1.y = 30;
                    citire_tastatura_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    v2.y = v1.y; v2.x = v1.x+80+40;
                    citire_tastatura_afisare_vector_verticala(v2,v2.x,v2.y,WHITE);
                    produs_scalar_grafica(v1,v2,rezultat);
                }
                else {
                    cleardevice();
                    v1.x = 30; v1.y = 30;
                    citire_fisier_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    v2.y = v1.y; v2.x = v1.x+80+40;
                    citire_fisier_afisare_vector_verticala(v2,v2.x,v2.y,WHITE);
                    produs_scalar_grafica(v1,v2,rezultat);
                }
                goto butonVect;
            }
            case 3: { //produs vectorial - facut
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    v1.x = 30; v1.y = 30;
                    citire_tastatura_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    v2.y = v1.y; v2.x = v1.x+80+40;
                    citire_tastatura_afisare_vector_verticala(v2,v2.x,v2.y,WHITE);
                    produs_vectorial_grafica(v1,v2,v3);
                }
                else {
                    cleardevice();
                    v1.x = 30; v1.y = 30;
                    citire_fisier_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    v2.y = v1.y; v2.x = v1.x+80+40;
                    citire_fisier_afisare_vector_verticala(v2,v2.x,v2.y,WHITE);
                    produs_vectorial_grafica(v1,v2,v3);
                }
                goto butonVect;
            }
            case 4: { //suma elemente - facut
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    v1.x = 30; v1.y = 30;
                    citire_tastatura_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    suma_elemente_vector_grafica(v1);
                }
                else {
                    cleardevice();
                    v1.x = 30; v1.y = 30;
                    citire_fisier_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    suma_elemente_vector_grafica(v1);
                }
                goto butonVect;
            }
            case 5: { //shiftare dreapta - greșit
               int nr_poz;
               if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    v1.x = 30; v1.y = 30;
                    v1.afisatOrizontal = true;
                    citire_tastatura_afisare_vector_orizontala(v1,v1.x,v1.y,WHITE);
                    cout<<"Dati nr de pozitii de shiftat:"<<endl;
                    cin>>nr_poz;
                    shiftare_dreapta_vector_grafica(v1,v2,nr_poz);
                }
                else {
                    cleardevice();
                    v1.x = 30; v1.y = 30;
                    v1.afisatOrizontal = true;
                    citire_fisier_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    fin>>nr_poz;
                    shiftare_dreapta_vector_grafica(v1,v2,nr_poz);
                }
                goto butonVect;
            }
            case 6: {//shiftare stanga - gresit
                int nr_poz;
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    v1.x = 30; v1.y = 30;
                    v1.afisatOrizontal = true;
                    citire_tastatura_afisare_vector_orizontala(v1,v1.x,v1.y,WHITE);
                    cout<<"Dati nr de pozitii de shiftat:"<<endl;
                    cin>>nr_poz;
                    shiftare_stanga_vector_grafica(v1,v2,nr_poz);
                }
                else {
                    cleardevice();
                    v1.afisatOrizontal = true;
                    v1.x = 30; v1.y = 30;
                    citire_fisier_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    fin>>nr_poz;
                    shiftare_stanga_vector_grafica(v1,v2,nr_poz);
                }
                goto butonVect;
            }
            case 7: { //inmultire cu scalar - facut
                float scalar;
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    v1.x = 30; v1.y = 30;
                    citire_tastatura_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    cout<<"\nScalar: ";
                    cin>>scalar; cout<<endl;
                    inmultire_scalar_vector_grafica(v1,scalar,v2);
                }
                else {
                    cleardevice();
                    v1.x = 30; v1.y = 30;
                    citire_fisier_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    fin>>scalar;
                    inmultire_scalar_vector_grafica(v1,scalar,v2);
                }
                goto butonVect;
            }
            case 8: { //produs elemente - facut
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    v1.x = 30; v1.y = 30;
                    citire_tastatura_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    produs_elemente_vector_grafica(v1);
                }
                else {
                    cleardevice();
                    v1.x = 30; v1.y = 30;
                    citire_fisier_afisare_vector_verticala(v1,v1.x,v1.y,WHITE);
                    produs_elemente_vector_grafica(v1);
                }
                goto butonVect;
            }
            case 9: { //bubbleSort - facut
                v1.afisatOrizontal=true;
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    v1.x = 30; v1.y = 30;
                    citire_tastatura_afisare_vector_orizontala(v1,v1.x,v1.y,WHITE);
                    bubbleSort_grafica(v1);
                }
                else {
                    cleardevice();
                    v1.x = 30; v1.y = 30;
                    citire_fisier_afisare_vector_orizontala(v1,v1.x,v1.y,WHITE);
                    bubbleSort_grafica(v1);
                }
                goto butonVect;
            }
            butonVect: buton_intoarcere();
            while(1) {
                int x_click, y_click;
                while(!ismouseclick(WM_LBUTTONDOWN)) delay(100);
                getmouseclick(WM_LBUTTONDOWN,x_click,y_click);
                if(x_click>20 && x_click<230 && y_click>670 && y_click<730) goto meniuTastaturaSauFisierVect; //inapoi
            }
        }
    }
    else {
        meniuFunctiiMatr: functieApelataMatrice = meniu_functiiMatrice();
        if(functieApelataMatrice==12) {
                cleardevice();
                goto meniuVectSauMatr;
        }
        meniuTastaturaSauFisierMatr: tastaturaSauFisier = meniu_tastaturaSauFisierMatrice();
        if(tastaturaSauFisier==2) {
            cleardevice();
            goto meniuFunctiiMatr;
        }
        switch(functieApelataMatrice) {
            case 0: { //adunare - facut
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    citire_tastatura_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    m2.x = m1.x+m1.coloane*80+60;
                    m2.y = m1.y;
                    citire_tastatura_afisare_matrice(m2,m2.x,m2.y,WHITE);
                    adunare_matrice_grafica(m1,m2,m3);
                }
                else {
                    cleardevice();
                    citire_fisier_matr(m1);
                    m2.x = m1.x+m1.coloane*80+60;
                    m2.y = m1.y;
                    citire_fisier_matr(m2);
                    adunare_matrice_grafica(m1,m2,m3);
                }
                goto butonMatr;
            }
            case 1: { //scadere - facut
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    citire_tastatura_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    m2.x = m1.x+m1.coloane*80+60;
                    m2.y = m1.y;
                    citire_tastatura_afisare_matrice(m2,m2.x,m2.y,WHITE);
                    scadere_matrice_grafica(m1,m2,m3);
                }
                else {
                    cleardevice();
                    citire_fisier_matr(m1);
                    m2.x = m1.x+m1.coloane*80+60;
                    m2.y = m1.y;
                    citire_fisier_matr(m2);
                    scadere_matrice_grafica(m1,m2,m3);
                }
                goto butonMatr;
            }
            case 2: { //inmultire - facut
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    citire_tastatura_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    m2.x=m1.x+80*m1.coloane+20+textwidth("x"); m2.y=m1.y;
                    citire_tastatura_afisare_matrice(m2,m2.x,m2.y,WHITE);
                    inmultire_matrice_grafica(m1,m2,m3);
                }
                else {
                    cleardevice();
                    citire_fisier_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    m2.x=m1.x+80*m1.coloane+20+textwidth("x"); m2.y=m1.y;
                    citire_fisier_afisare_matrice(m2,m2.x,m2.y,WHITE);
                    inmultire_matrice_grafica(m1,m2,m3);
                }
                goto butonMatr;
            }
            case 3: { //putere - facut
                int putere;
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    citire_tastatura_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    cout<<"\nPutere: ";
                    cin>>putere; cout<<endl;
                    putere_matrice_grafica(m1,putere,m2);
                }
                else {
                    cleardevice();
                    citire_fisier_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    fin>>putere;
                    putere_matrice_grafica(m1,putere,m2);
                }
                goto butonMatr;
            }
            case 4: { //transpusa - facut
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    citire_tastatura_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    transpusa_grafica(m1,m2);
                }
                else {
                    cleardevice();
                    citire_fisier_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    transpusa_grafica(m1,m2);
                }
                goto butonMatr;
            }
            case 5: { //suma diagonala principala - facut
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    citire_tastatura_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    suma_diag_principala_grafica(m1);
                }
                else {
                    cleardevice();
                    citire_fisier_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    suma_diag_principala_grafica(m1);
                }
                goto butonMatr;
            }
            case 6: { //suma sub diagonala principala - facut
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    citire_tastatura_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    suma_sub_diag_principala_grafica(m1);
                }
                else {
                    cleardevice();
                    citire_fisier_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    suma_sub_diag_principala_grafica(m1);
                }
                goto butonMatr;
            }
            case 7: { //suma deasupra diagonala principala - facut
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    citire_tastatura_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    suma_deasupra_diag_principala_grafica(m1);
                }
                else {
                    cleardevice();
                    citire_fisier_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    suma_deasupra_diag_principala_grafica(m1);
                }
                goto butonMatr;
            }
            case 8: { //suma diagonala secundara - facut
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    citire_tastatura_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    suma_diag_secundara_grafica(m1);
                }
                else {
                    cleardevice();
                    citire_fisier_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    suma_diag_secundara_grafica(m1);
                }
                goto butonMatr;
            }
            case 9: { //determinant - facut
                float determinant;
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    citire_tastatura_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    determinant_matrice_grafica(m1,determinant);
                }
                else {
                    cleardevice();
                    citire_fisier_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    determinant_matrice_grafica(m1,determinant);
                }
                goto butonMatr;
            }
            case 10: { //inversa - facut
                matrix inv;
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    citire_tastatura_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    bool inversabila;
                    inversare_matrice_grafica(m1,inv,inversabila);
                }
                else {
                    cleardevice();
                    citire_fisier_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    bool inversabila;
                    inversare_matrice_grafica(m1,inv,inversabila);
                }
                goto butonMatr;
            }
            case 11: { //scalar - facut
                int scalar;
                if(tastaturaSauFisier==0) {
                    mesajTastatura();
                    citire_tastatura_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    cout<<"\nScalar: ";
                    cin>>scalar; cout<<endl;
                    inmultire_scalar_matrice_grafica(m1,scalar,m2);
                }
                else {
                    cleardevice();
                    citire_fisier_afisare_matrice(m1,m1.x,m1.y,WHITE);
                    fin>>scalar;
                    inmultire_scalar_matrice_grafica(m1,scalar,m2);
                }
                goto butonMatr;
            }
            butonMatr: buton_intoarcere();
            while(1) {
                int x_click, y_click;
                while(!ismouseclick(WM_LBUTTONDOWN)) delay(100);
                getmouseclick(WM_LBUTTONDOWN,x_click,y_click);
                if(x_click>20 && x_click<230 && y_click>670 && y_click<730) goto meniuTastaturaSauFisierMatr; //inapoi
            }
        }
    }
    citire_fisier_afisare_matrice(m1,m1.x,m1.y,WHITE);
    getch();
    return 0;
}
int nr_cifre(float nr) {
    if(nr==0) return 1;

    int cifre=0;
    int zecimale=0;
    int intreg = (int)nr;

    if(nr-intreg!=0) zecimale=1;

    if(intreg<0) intreg=-intreg;

    while(intreg>0) {
        cifre++;
        intreg=intreg/10;
    }
    if(cifre==0) cifre = 1;
    return cifre+zecimale;
}
int nr_caractere(float nr){
    if(nr<0) return 1+nr_cifre(nr);
    return nr_cifre(nr);
}
void interchimba(float &a,float &b){float aux=a;a=b;b=aux;}
void interchimba(int &a,int &b){int aux=a;a=b;b=aux;}
void buton_intoarcere() {
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
    rectangle(20,670,230,730);
    bgiout<<"Inapoi";
    outstreamxy(80,690);
}
void inmultire_scalar_vector_grafica(vect v1, int scalar, vect v2) {
    int x_ori=130, y_ori = (v1.lungime*80+v1.y)/2;
    bgiout<<"x";
    outstreamxy(x_ori,y_ori);
    bgiout<<scalar;
    outstreamxy(x_ori+30,y_ori);
    bgiout<<"=";
    outstreamxy(x_ori+60,y_ori);
    v2.x = x_ori+100; v2.y=v1.y;
    borders_and_lines(v1.lungime,1,v2.x,v2.y);
    for(int i=0;i<v1.lungime;i++) {
        coloreazaElemVector(v1,i,GREEN,400);
        putNumber(scalar,x_ori+30,y_ori,GREEN,400);
        v2.elem[i]=v1.elem[i]*scalar;
        coloreazaElemVector(v2,i,GREEN,400);
        coloreazaElemVector(v1,i,WHITE,0);
        putNumber(scalar,x_ori+30,y_ori,WHITE,0);
        coloreazaElemVector(v2,i,WHITE,400);
    }
}
void bubbleSort_grafica(vect v1) {
    int i,j;
    for(i=0;i<v1.lungime-1;i++) {
        for(j=0;j<v1.lungime-i-1;j++) {
            if(v1.elem[j]>v1.elem[j+1]) {
                coloreazaElemVector(v1,j,GREEN,800);
                coloreazaElemVector(v1,j+1,RED,0);
                interchimba(v1.elem[j],v1.elem[j+1]);
                coloreazaElemVector(v1,j,GREEN,800);
                coloreazaElemVector(v1,j+1,RED,0);
                coloreazaElemVector(v1,j,WHITE,800);
                coloreazaElemVector(v1,j+1,WHITE,0);
            }
        }
    }
}
void produs_elemente_vector_grafica(vect v1) {
    int p=1,i, x_elem, y_elem, x_ori, y_ori;
    x_elem = 130; y_elem = (v1.lungime*80+v1.y)/2;
    x_ori = 170; y_ori = y_elem;
    for(i=0;i<v1.lungime;i++) {
        coloreazaElemVector(v1,i,GREEN,1000);
        bgiout<<v1.elem[i];
        outstreamxy(x_elem,y_elem);
        coloreazaElemVector(v1,i,WHITE,1000);
        x_elem += 70;
        if(i<v1.lungime-1) {
            bgiout<<"x";
            outstreamxy(x_ori,y_ori);
            x_ori += 70;
        }
        p*=v1.elem[i];
    }
    bgiout<<"=";
    outstreamxy(x_ori,y_ori);
    bgiout<<p;
    outstreamxy(x_ori+40,y_ori);
}
void suma_elemente_vector_grafica(vect v1) {
    int s=0,i, x_elem, y_elem, x_plus, y_plus;
    x_elem = 130; y_elem = (v1.lungime*80+v1.y)/2;
    x_plus = 170; y_plus = y_elem;
    for(i=0;i<v1.lungime;i++) {
        bgiout<<v1.elem[i];
        outstreamxy(x_elem,y_elem);
        x_elem += 70;
        if(i<v1.lungime-1) {
            bgiout<<"+";
            outstreamxy(x_plus,y_plus);
            x_plus += 70;
        }
        s+=v1.elem[i];
    }
    bgiout<<"=";
    outstreamxy(x_plus,y_plus);
    bgiout<<s;
    outstreamxy(x_plus+40,y_plus);
}
void scadere_vector_grafica(vect v1, vect v2, vect &v3) {
    if(v1.lungime!=v2.lungime) {
        bgiout<<"Vectorii trebuie sa aiba aceeasi lungime.";
        outstreamxy(v2.x+100,40);
    }
    else {
        int x_egal, y_egal;
        x_egal = v2.x+80+10;
        y_egal = v2.y+v2.lungime*80/2;
        bgiout<<" -";
        outstreamxy(v1.x+90,y_egal);
        bgiout<<"=";
        outstreamxy(x_egal,y_egal);

        v3.x=x_egal+80;
        v3.y=v2.y;
        v3.lungime=v1.lungime;
        borders_and_lines(v3.lungime,1,v3.x,v3.y);

        for(int i=0; i<v1.lungime; i++) {
            coloreazaElemVector(v1,i,GREEN,300);
            coloreazaElemVector(v2,i,GREEN,300);
            v3.elem[i] = v1.elem[i] - v2.elem[i];
            coloreazaElemVector(v3,i,GREEN,300);
            coloreazaElemVector(v1,i,WHITE,300);
            coloreazaElemVector(v2,i,WHITE,0);
            coloreazaElemVector(v3,i,WHITE,0);
        }
    }
}
void adunare_vector_grafica(vect v1, vect v2, vect &v3) {
    if(v1.lungime!=v2.lungime) {
        bgiout<<"Vectorii trebuie sa aiba aceeasi lungime.";
        outstreamxy(v2.x+100,40);
    }
    else {
        int x_egal, y_egal;
        x_egal = v2.x+80+10;
        y_egal = v2.y+v2.lungime*80/2;
        bgiout<<"+";
        outstreamxy(v1.x+90,y_egal);
        bgiout<<"=";
        outstreamxy(x_egal,y_egal);

        v3.x=x_egal+80;
        v3.y=v2.y;
        v3.lungime=v1.lungime;
        borders_and_lines(v3.lungime,1,v3.x,v3.y);

        for(int i=0; i<v1.lungime; i++) {
            coloreazaElemVector(v1,i,GREEN,300);
            coloreazaElemVector(v2,i,GREEN,300);
            v3.elem[i] = v1.elem[i] + v2.elem[i];
            coloreazaElemVector(v3,i,GREEN,300);
            coloreazaElemVector(v1,i,WHITE,300);
            coloreazaElemVector(v2,i,WHITE,0);
            coloreazaElemVector(v3,i,WHITE,0);
        }
    }
}
void suma_diag_secundara_grafica(matrix m1) {
    int i,s=0, x_matrix1_center, y_matrix1_center;
    y_matrix1_center=80/2+m1.y-10;
    x_matrix1_center=80/2+m1.x+(m1.coloane-1)*80;
    if(m1.linii!=m1.coloane) {
        bgiout<<"Introduceti o matrice patratica.";
        outstreamxy(m1.coloane*80+80,m1.y);
    }
    else {
        int x_egal,y_egal,i,j,x_plus,y_plus;
        x_egal = m1.coloane*80+40; y_egal = (m1.linii*80+m1.y)/2;
        x_plus=x_egal+70; y_plus=y_egal;
        int x_elem=x_egal+30,y_elem=y_egal;
        for(i=0;i<m1.linii;i++) {
            stergeElemMatrice(m1,i,m1.linii-i-1,0);
            putNumber(m1.elem[i][m1.linii-i-1],x_matrix1_center,y_matrix1_center,GREEN,1000);
            s+=m1.elem[i][m1.linii-i-1];
            x_matrix1_center -= 80;
            y_matrix1_center += 80;

            bgiout<<trunchiaza(m1.elem[i][m1.linii-i-1]);
            outstreamxy(x_elem,y_elem);
            x_elem=x_plus+20;

            if(i<m1.linii-1) {
                bgiout<<"+";
                outstreamxy(x_plus,y_plus);
                x_plus+=60;
            }
        }
        bgiout<<"= ";
        outstreamxy(x_plus,y_plus);
        bgiout<<trunchiaza(s);
        outstreamxy(x_plus+30,y_plus);
    }
    setcolor(WHITE);
}
void suma_deasupra_diag_principala_grafica(matrix m1) {
    int i,s=0, x_matrix1_center, y_matrix1_center;
    y_matrix1_center=80/2+m1.y-10;
    x_matrix1_center=80/2+m1.x+80;
    if(m1.linii!=m1.coloane) {
        bgiout<<"Introduceti o matrice patratica.";
        outstreamxy(m1.coloane*80+50,m1.y);
    }
    else {
        //bgiout<<" = ";
        int x_egal,y_egal,j,x_plus,y_plus;
        x_egal = m1.coloane*80+40; y_egal = (m1.linii*80+m1.y)/2;
        //outstreamxy(x_egal,y_egal);
        x_plus=x_egal+70; y_plus=y_egal;
        int x_elem=x_egal+35,y_elem=y_egal;
        for(i=0;i<m1.linii;i++) {
            for(j=0;j<m1.coloane;j++) {
                if(i<j) {
                    stergeElemMatrice(m1,i,j,0);
                    putNumber(m1.elem[i][j],x_matrix1_center,y_matrix1_center,GREEN,1000);
                    s+=m1.elem[i][j];

                    bgiout<<trunchiaza(m1.elem[i][j]);
                    outstreamxy(x_elem,y_elem);
                    x_elem=x_plus+20;

                    if(i<m1.linii-2 && j<m1.coloane) {
                        bgiout<<"+";
                        outstreamxy(x_plus,y_plus);
                        x_plus+=60;
                    }
                    x_matrix1_center+=80;
                }
            }
            x_matrix1_center=80/2+m1.x+(i+2)*80;
            y_matrix1_center+=80;
        }
        bgiout<<"= ";
        outstreamxy(x_plus,y_plus);
        bgiout<<trunchiaza(s);
        outstreamxy(x_plus+30,y_plus);
    }
    setcolor(WHITE);
}
void suma_sub_diag_principala_grafica(matrix m1) {
    int i,s=0, x_matrix1_center, y_matrix1_center;
    y_matrix1_center=80/2+m1.y-10;
    x_matrix1_center=80/2+m1.x;
    if(m1.linii!=m1.coloane) {
        bgiout<<"Introduceti o matrice patratica.";
        outstreamxy(m1.coloane*80+50,m1.y);
    }
    else {
        int x_egal,y_egal,j,x_plus,y_plus;
        x_egal = m1.coloane*80+40; y_egal = (m1.linii*80+m1.y)/2;
        x_plus=x_egal+70; y_plus=y_egal;
        int x_elem=x_egal+35,y_elem=y_egal;
        for(i=0;i<m1.linii;i++) {
            for(j=0;j<m1.coloane;j++) {
                if(i>j) {
                    stergeElemMatrice(m1,i,j,0);
                    putNumber(m1.elem[i][j],x_matrix1_center,y_matrix1_center,GREEN,1000);
                    s+=m1.elem[i][j];

                    bgiout<<trunchiaza(m1.elem[i][j]);
                    outstreamxy(x_elem,y_elem);
                    x_elem=x_plus+20;

                    if(i<m1.linii && j<m1.coloane-2) {
                        bgiout<<"+";
                        outstreamxy(x_plus,y_plus);
                        x_plus+=60;
                    }
                    x_matrix1_center+=80;
                }
            }
            x_matrix1_center=80/2+m1.x;
            y_matrix1_center+=80;
        }
        bgiout<<"= ";
        outstreamxy(x_plus,y_plus);
        bgiout<<trunchiaza(s);
        outstreamxy(x_plus+30,y_plus);
    }
    setcolor(WHITE);
}
void suma_diag_principala_grafica(matrix m1) {
    int i,s=0, x_matrix1_center, y_matrix1_center;
    y_matrix1_center=80/2+m1.y-10;
    x_matrix1_center=80/2+m1.x;
    if(m1.linii!=m1.coloane) {
        bgiout<<"Introduceti o matrice patratica.";
        outstreamxy(m1.coloane*80+50,m1.y);
    }
    else {
        int x_egal,y_egal,i,j,x_plus,y_plus;
        x_egal = m1.coloane*80+40; y_egal = (m1.linii*80+m1.y)/2;
        x_plus=x_egal+70; y_plus=y_egal;
        int x_elem=x_egal+30,y_elem=y_egal;
        for(i=0;i<m1.linii;i++) {

            stergeElemMatrice(m1,i,i,999);
            putNumber(m1.elem[i][i],x_matrix1_center,y_matrix1_center,GREEN,1);
            s+=m1.elem[i][i];
            x_matrix1_center += 80;
            y_matrix1_center += 80;

            bgiout<<trunchiaza(m1.elem[i][i]);
            outstreamxy(x_elem,y_elem);
            x_elem=x_plus+20;

            if(i<m1.linii-1) {
                bgiout<<"+";
                outstreamxy(x_plus,y_plus);
                x_plus+=60;
            }
        }
        bgiout<<"= ";
        outstreamxy(x_plus,y_plus);
        bgiout<<trunchiaza(s);
        outstreamxy(x_plus+30,y_plus);
    }
    setcolor(WHITE);
}
void produs_vectorial_grafica(vect vect1, vect vect2, vect &vect3){
    bgiout<<"x";
    outstreamxy(vect1.x+90,(vect1.y+80*vect1.lungime)/2);
    if(vect1.lungime!=3 && vect2.lungime!=3) {
        clean();
        cout<<"Vectorii trebuie sa aiba dimensiunea 3.";
        bgiout<<"Vectorii trebuie sa aiba dimensiunea 3.";
        outstreamxy(10,10);
    }
    else {
        int x_egal,y_egal;
        x_egal = vect2.x+80+10;
        y_egal = vect2.y+vect2.lungime*80/2;
        bgiout<<"=";
        outstreamxy(x_egal,y_egal);

        vect3.x=x_egal+50;
        vect3.y=vect2.y;
        vect3.lungime=vect1.lungime;
        borders_and_lines(vect3.lungime,1,vect3.x,vect3.y);


        coloreazaElemVector(vect1,1,RED,0);
        coloreazaElemVector(vect2,2,RED,0);
        coloreazaElemVector(vect1,2,RED,0);
        coloreazaElemVector(vect2,1,RED,0);

        vect3.elem[0] = vect1.elem[1]*vect2.elem[2] - vect1.elem[2]*vect2.elem[1];
        coloreazaElemVector(vect3,0,RED,0);
        coloreazaElemVector(vect3,0,WHITE,2000);

        coloreazaElemVector(vect1,1,WHITE,0);
        coloreazaElemVector(vect2,2,WHITE,0);
        coloreazaElemVector(vect1,2,WHITE,0);
        coloreazaElemVector(vect2,1,WHITE,0);


        coloreazaElemVector(vect1,2,RED,0);
        coloreazaElemVector(vect2,0,RED,0);
        coloreazaElemVector(vect1,0,RED,0);
        coloreazaElemVector(vect2,2,RED,0);

        vect3.elem[1] = vect1.elem[2]*vect2.elem[0] - vect1.elem[0]*vect2.elem[2];
        coloreazaElemVector(vect3,1,RED,0);
        coloreazaElemVector(vect3,1,WHITE,2000);

        coloreazaElemVector(vect1,2,WHITE,0);
        coloreazaElemVector(vect2,0,WHITE,0);
        coloreazaElemVector(vect1,0,WHITE,0);
        coloreazaElemVector(vect2,2,WHITE,0);


        coloreazaElemVector(vect1,0,RED,0);
        coloreazaElemVector(vect2,1,RED,0);
        coloreazaElemVector(vect1,1,RED,0);
        coloreazaElemVector(vect2,0,RED,0);

        vect3.elem[2] = vect1.elem[0]*vect2.elem[1] - vect1.elem[1]*vect2.elem[0];
        coloreazaElemVector(vect3,2,RED,0);
        coloreazaElemVector(vect3,2,WHITE,2000);

        coloreazaElemVector(vect1,0,WHITE,0);
        coloreazaElemVector(vect2,1,WHITE,0);
        coloreazaElemVector(vect1,1,WHITE,0);
        coloreazaElemVector(vect2,0,WHITE,0);

        vect3.lungime = 3;
    }
}
void transpusa_grafica(matrix m1, matrix &m2) {
    bgiout<<"t";
    outstreamxy(m1.x-20,m1.y);

    bgiout<<" = ";
    int x_egal, y_egal,i,j;
    x_egal = m1.coloane*80+40; y_egal = (m1.linii*80+m1.y)/2;
    outstreamxy(x_egal,y_egal);

    m2.x=x_egal+40; m2.y=m1.y;

    for(i=0; i<m1.linii; ++i) for(j=0; j<m1.coloane; ++j) m2.elem[j][i]=m1.elem[i][j];
    m2.linii=m1.coloane; m2.coloane=m1.linii;
    afisare_ecran_matrice_grafica(m2,WHITE);

    borders_and_lines(m1.coloane,m1.linii,m2.x,m2.y);
    for(i=0; i<m1.linii; ++i) {
        coloreazaLinieMatrice(i,m1,GREEN,1000);
        coloreazaColoanaMatrice(i,m1,RED,1000);
        coloreazaLinieMatrice(i,m2,RED,1000);
        coloreazaColoanaMatrice(i,m2,GREEN,1000);

        coloreazaLinieMatrice(i,m1,WHITE,1000);
        coloreazaColoanaMatrice(i,m1,WHITE,0);
        coloreazaLinieMatrice(i,m2,WHITE,0);
        coloreazaColoanaMatrice(i,m2,WHITE,0);
    }
}
void putere_matrice_grafica(matrix matrix1, int putere, matrix &matrix2){
    unsigned int i;

    if(putere>0){

        matrix matrix1Copie = matrix1;
        matrix1Copie.x = matrix1.x + 80 * matrix1.coloane + textwidth("x")+40;

        afisare_ecran_matrice_grafica(matrix1Copie,WHITE);

        inmultire_matrice_grafica(matrix1,matrix1Copie,matrix2);

        for(i=3;i<=putere;i++) {
            cleardevice();

            matrix2.x = matrix1.x;
            matrix2.y = matrix1.y;
            afisare_ecran_matrice_grafica(matrix2,WHITE);

            matrix1Copie.y = matrix2.y;
            matrix1Copie.x = matrix2.x + 80 * matrix2.coloane + textwidth("x")+40;
            afisare_ecran_matrice_grafica(matrix1Copie,WHITE);

            inmultire_matrice_grafica(matrix2,matrix1Copie,matrix2);
        }
    }
    if(putere<0) {

        bool inversabila;

        putere=-putere;
        inversare_matrice_grafica(matrix1,matrix1,inversabila);

        if(inversabila) {
            cleardevice();

            matrix matrix1Copie = matrix1;
            matrix1Copie.x = matrix1.x + 80 * matrix1.coloane + textwidth("x")+40;

            afisare_ecran_matrice_grafica(matrix1,WHITE);
            afisare_ecran_matrice_grafica(matrix1Copie,WHITE);

            inmultire_matrice_grafica(matrix1,matrix1Copie,matrix2);

            for(i=3;i<=putere;i++) {
                cleardevice();

                matrix2.x = matrix1.x;
                matrix2.y = matrix1.y;
                afisare_ecran_matrice_grafica(matrix2,WHITE);

                matrix1Copie.y = matrix2.y;
                matrix1Copie.x = matrix2.x + 80 * matrix2.coloane + textwidth("x")+40;
                afisare_ecran_matrice_grafica(matrix1Copie,WHITE);

                inmultire_matrice_grafica(matrix2,matrix1Copie,matrix2);
            }
        }
    }
}
void scadere_matrice_grafica(matrix matrix1, matrix matrix2, matrix &matrix3) {
    if(matrix1.linii!=matrix2.linii || matrix1.coloane!=matrix2.coloane) {
        bgiout<<"Matricele trebuie sa aiba aceeasi dimensiune.";
        outstreamxy(30,matrix1.y+matrix1.linii*80+10);
    }
    else {
        bgiout<<"- ";
        outstreamxy(matrix1.coloane*80+matrix1.x+20,(matrix1.linii*80+matrix1.y)/2);

        bgiout<<" = ";
        int x_egal = matrix2.x+matrix2.coloane*80+20;
        outstreamxy(x_egal,(matrix1.linii*80+matrix1.y)/2);

        matrix3.x=x_egal+50;
        matrix3.y=matrix2.y;
        matrix3.linii=matrix1.linii; matrix3.coloane=matrix2.coloane;
        borders_and_lines(matrix3.linii,matrix3.coloane,matrix3.x,matrix3.y);

        int i,j,k,x,x_matrix1_center,y_matrix1_center,x_matrix2_center,y_matrix2_center,x_matrix3_center,y_matrix3_center;
        y_matrix1_center=80/2+matrix1.y-10;
        x_matrix1_center=80/2+matrix1.x;
        y_matrix2_center=80/2+matrix2.y-10;
        x_matrix2_center=80/2+matrix2.x;
        y_matrix3_center=80/2+matrix3.y-10;
        x_matrix3_center=80/2+matrix3.x;

        if(matrix1.linii!=matrix2.linii || matrix1.coloane!=matrix2.coloane) cout<<"Imposibil.";
        else {
            for(i=0;i<matrix1.linii;i++) {
                for(j=0;j<matrix1.coloane;j++) {
                    stergeElemMatrice(matrix1,i,j,299);
                    putNumber(matrix1.elem[i][j],x_matrix1_center,y_matrix1_center,GREEN,1);
                    stergeElemMatrice(matrix1,i,j,299);
                    putNumber(matrix2.elem[i][j],x_matrix2_center,y_matrix2_center,GREEN,1);

                    matrix3.elem[i][j]=matrix1.elem[i][j] - matrix2.elem[i][j];

                    stergeElemMatrice(matrix3,i,j,299);
                    putNumber(matrix3.elem[i][j],x_matrix3_center,y_matrix3_center,GREEN,1);
                    stergeElemMatrice(matrix1,i,j,299);
                    putNumber(matrix1.elem[i][j],x_matrix1_center,y_matrix1_center,WHITE,1);
                    stergeElemMatrice(matrix2,i,j,0);
                    putNumber(matrix2.elem[i][j],x_matrix2_center,y_matrix2_center,WHITE,0);
                    stergeElemMatrice(matrix3,i,j,0);
                    putNumber(matrix3.elem[i][j],x_matrix3_center,y_matrix3_center,WHITE,0);

                    x_matrix1_center+=80; x_matrix2_center+=80; x_matrix3_center+=80;
                }
                x_matrix1_center=80/2+matrix1.x;
                y_matrix1_center+=80;
                x_matrix2_center=80/2+matrix2.x;
                y_matrix2_center+=80;
                x_matrix3_center=80/2+matrix3.x;
                y_matrix3_center+=80;
            }
            matrix3.linii=matrix1.linii;
            matrix3.coloane=matrix2.coloane;
        }
    }
}
void mesajTastatura() {
    cleardevice();
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
    bgiout<<"Introduceti datele in consola standard.";
    outstreamxy(30,30);
    delay(2000);
    cleardevice();
}
int meniu_functiiMatrice() {
    delay(300);
    cleardevice();
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);

    bgiout<<"Dati click pe functia dorita: ";
    outstreamxy(10,10);
    //diferenta x intre dreptunghiuri orizontale = 210, diferenta y intre dreptunghiuri orizontale = 60
    //diferenta y intre dreptunghiuri verticale = 110
    // diferenta y afisare text = 110
    int xSusStanga=20, ySusStanga=40, xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Adunare";
    outstreamxy(60,60);

    xSusStanga=260; ySusStanga=40; xJosDreapta=xSusStanga+210; yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Scadere";
    outstreamxy(310,60);

    xSusStanga=20; ySusStanga=150; xJosDreapta=xSusStanga+210; yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Inmultire";
    outstreamxy(60,170);

    xSusStanga=260; ySusStanga=150; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Putere";
    outstreamxy(310,170);

    xSusStanga=20; ySusStanga=260; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Transpusa";
    outstreamxy(50,280);

    xSusStanga=260; ySusStanga=260; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Suma diagonala";
    outstreamxy(270,270);
    bgiout<<"principala";
    outstreamxy(300,290);

    xSusStanga=20; ySusStanga=370; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Suma sub";
    outstreamxy(40,380);
    bgiout<<"diag. principala";
    outstreamxy(40,400);

    xSusStanga=260; ySusStanga=370; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Suma deasupra";
    outstreamxy(270,380);
    bgiout<<"diag. principala";
    outstreamxy(270,400);

    xSusStanga=20; ySusStanga=480; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Suma diagonala";
    outstreamxy(25,490);
    bgiout<<"secundara";
    outstreamxy(50,510);

    xSusStanga=260; ySusStanga=480; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Determinant";
    outstreamxy(300,500);

    xSusStanga=20; ySusStanga=590; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Inversa";
    outstreamxy(70,610);

    xSusStanga=260; ySusStanga=590; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Inmultire scalar";
    outstreamxy(275,610);

    buton_intoarcere();

    int x_click, y_click;
    while(1) {
        while(!ismouseclick(WM_LBUTTONDOWN)) delay(100);
        getmouseclick(WM_LBUTTONDOWN,x_click,y_click);
        if(x_click>20 && x_click<230 && y_click>40 && y_click<100) return 0; //adunare
        else if(x_click>260 && x_click<470 && y_click>40 && y_click<100) return 1; //scadere
        else if(x_click>20 && x_click<230 && y_click>150 && y_click<210) return 2; //inmultire
        else if(x_click>260 && x_click<470 && y_click>150 && y_click<210) return 3; //putere
        else if(x_click>20 && x_click<230 && y_click>260 && y_click<320) return 4; //transpusa
        else if(x_click>260 && x_click<470 && y_click>260 && y_click<320) return 5; //diagonala principala
        else if(x_click>20 && x_click<230 && y_click>370 && y_click<430) return 6; //sub diag principala
        else if(x_click>260 && x_click<470 && y_click>370 && y_click<430) return 7; //deasupra diag principala
        else if(x_click>20 && x_click<230 && y_click>480 && y_click<540) return 8; //diagonala secundara
        else if(x_click>260 && x_click<470 && y_click>480 && y_click<540) return 9; //determinant
        else if(x_click>20 && x_click<230 && y_click>590 && y_click<650) return 10; //inversa
        else if(x_click>260 && x_click<470 && y_click>590 && y_click<650) return 11; //scalar
        else if(x_click>20 && x_click<230 && y_click>670 && y_click<730) return 12; //inapoi
    }
}
int meniu_functiiVectori() {
    cleardevice();
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);

    bgiout<<"Dati click pe functia dorita: ";
    outstreamxy(10,10);
    //diferenta x intre dreptunghiuri orizontale = 210, diferenta y intre dreptunghiuri orizontale = 60
    //diferenta y intre dreptunghiuri verticale = 110
    // diferenta y afisare text = 110
    int xSusStanga=20, ySusStanga=40, xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Adunare";
    outstreamxy(60,60);

    xSusStanga=260; ySusStanga=40; xJosDreapta=xSusStanga+210; yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Scadere";
    outstreamxy(310,60);

    xSusStanga=20; ySusStanga=150; xJosDreapta=xSusStanga+210; yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Produs scalar";
    outstreamxy(40,170);

    xSusStanga=260; ySusStanga=150; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Produs vectorial";
    outstreamxy(270,170);

    xSusStanga=20; ySusStanga=260; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Suma elemente";
    outstreamxy(30,280);

    xSusStanga=260; ySusStanga=260; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Shiftare dreapta";
    outstreamxy(270,280);

    xSusStanga=20; ySusStanga=370; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Shiftare stanga";
    outstreamxy(40,390);

    xSusStanga=260; ySusStanga=370; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Inmultire scalar";
    outstreamxy(270,390);

    xSusStanga=20; ySusStanga=480; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Produs elemente";
    outstreamxy(25,500);

    xSusStanga=260; ySusStanga=480; xJosDreapta=xSusStanga+210, yJosDreapta=ySusStanga+60;
    rectangle(xSusStanga,ySusStanga,xJosDreapta,yJosDreapta);
    bgiout<<"Bubble sort";
    outstreamxy(300,500);

    buton_intoarcere();

    int x_click, y_click;
    while(1) {
        while(!ismouseclick(WM_LBUTTONDOWN)) delay(100);
        getmouseclick(WM_LBUTTONDOWN,x_click,y_click);
        if(x_click>20 && x_click<230 && y_click>40 && y_click<100) return 0; //adunare
        else if(x_click>260 && x_click<470 && y_click>40 && y_click<100) return 1; //scadere
        else if(x_click>20 && x_click<230 && y_click>150 && y_click<210) return 2; //produs scalar
        else if(x_click>260 && x_click<470 && y_click>150 && y_click<210) return 3; //produs vectorial
        else if(x_click>20 && x_click<230 && y_click>260 && y_click<320) return 4; //suma elemente
        else if(x_click>260 && x_click<470 && y_click>260 && y_click<320) return 5; //shiftare dreapta
        else if(x_click>20 && x_click<230 && y_click>370 && y_click<430) return 6; //shiftare stanga
        else if(x_click>260 && x_click<470 && y_click>370 && y_click<430) return 7; //scalar
        else if(x_click>20 && x_click<230 && y_click>480 && y_click<540) return 8; //produs elemente
        else if(x_click>260 && x_click<470 && y_click>480 && y_click<540) return 9; //bubble sort
        else if(x_click>20 && x_click<230 && y_click>670 && y_click<730) return 10; //inapoi
    }
}
void citire_fisier_afisare_vector_orizontala(vect &v1, int x, int y, int color) {
    int w=80/2+y-10;
    int u=80/2+x;
    fin>>v1.lungime;
    cout<<v1.lungime<<endl<<endl;
    borders_and_lines(1,v1.lungime,x,y);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    for(int i=0;i<v1.lungime;i++) {
        fin>>v1.elem[i];
        cout<<v1.elem[i]<<" ";
        putNumber(v1.elem[i],u,w,color,200);
        u+=80;
    }
    cout<<endl;
}
void citire_fisier_afisare_vector_verticala(vect &v1, int x, int y, int color) {
    int w=80/2+y-10;
    int u=80/2+x;
    fin>>v1.lungime;
    cout<<v1.lungime<<endl<<endl;
    borders_and_lines(v1.lungime,1,x,y);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    for(int i=0;i<v1.lungime;i++) {
        fin>>v1.elem[i];
        cout<<v1.elem[i]<<" ";
        putNumber(v1.elem[i],u,w,color,200);
        w+=80;
    }
    cout<<endl;
}
void coloreazaElemVector(vect v1, int indice, int color, int timeDelay){
    int w=80/2+v1.y-10;
    int u=80/2+v1.x;
    if(v1.afisatOrizontal) u+=80*indice;
    else w+=80*indice;
    delElemVector(v1,indice,timeDelay>1?timeDelay-1:0);
    putNumber(v1.elem[indice],u,w,color,1);
    setcolor(WHITE);
}
void delElemVector(vect v1, int indice,int timeDelay){
    int w=v1.y+1;
    int u=v1.x+1;

    if(v1.afisatOrizontal) u+=80*indice;
    else w+=80*indice;

    delay(timeDelay);
    setfillstyle(SOLID_FILL,BLACK);
    bar(u,w,u+48,w+48);
}
void citire_tastatura_afisare_vector_orizontala(vect &v1, int x, int y, int color) {
    int w=80/2+y-10;
    int u=80/2+x;
    cout<<"Lungime: "; cin>>v1.lungime;
    cout<<"Introduceti elementele vectorului:"<<endl;
    borders_and_lines(1,v1.lungime,x,y);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    for(int i=0;i<v1.lungime;i++) {
        cin>>v1.elem[i];
        putNumber(v1.elem[i],u,w,color,200);
        u+=80;
    }
}
void citire_tastatura_afisare_vector_verticala(vect &v1, int x, int y, int color) {
    int w=80/2+y-10;
    int u=80/2+x;
    cout<<"Lungime: "; cin>>v1.lungime;
    cout<<"Introduceti elementele vectorului:"<<endl;
    borders_and_lines(v1.lungime,1,x,y);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    for(int i=0;i<v1.lungime;i++) {
        cin>>v1.elem[i];
        putNumber(v1.elem[i],u,w,color,200);
        w+=80;
    }
}
int meniu_vectorSauMatrice() {
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
    bgiout<<"Dati click pe tipul de tablou: ";
    outstreamxy(10,10);
    rectangle(20,40,200,100);
    bgiout<<"Vectori";
    outstreamxy(60,60);
    rectangle(230,40,410,100);
    bgiout<<"Matrice";
    outstreamxy(280,60);
    int x_click, y_click;
    while(1) {
        while(!ismouseclick(WM_LBUTTONDOWN)) delay(100);
        getmouseclick(WM_LBUTTONDOWN,x_click,y_click);
        if(x_click>20 && x_click<200 && y_click>40 && y_click<100) return 0; //vector
        else if(x_click>230 && x_click<410 && y_click>40 && y_click<100) return 1; //matrice
    }
}
int meniu_tastaturaSauFisierVector() {
    cleardevice();
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
    bgiout<<"Dati click pe modalitatea de intrare a datelor: ";
    outstreamxy(10,10);
    rectangle(20,40,200,100);
    bgiout<<"Tastatura";
    outstreamxy(55,60);
    rectangle(230,40,410,100);
    bgiout<<"Fisier";
    outstreamxy(285,60);
    buton_intoarcere();
    int x_click,y_click,click_valid=0;
    while(!click_valid) {
        while(!ismouseclick(WM_LBUTTONDOWN)) delay(100);
        getmouseclick(WM_LBUTTONDOWN,x_click,y_click);
        if(x_click>20 && x_click<200 && y_click>40 && y_click<100) return 0; //tastatura
        else if(x_click>230 && x_click<410 && y_click>40 && y_click<100) return 1; //fisier
        else if(x_click>20 && x_click<230 && y_click>670 && y_click<730) return 2; //inapoi
    }
}
int meniu_tastaturaSauFisierMatrice() {
    cleardevice();
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
    bgiout<<"Dati click pe modalitatea de intrare a datelor: ";
    outstreamxy(10,10);
    rectangle(20,40,200,100);
    bgiout<<"Tastatura";
    outstreamxy(55,60);
    rectangle(230,40,410,100);
    bgiout<<"Fisier";
    outstreamxy(285,60);
    buton_intoarcere();
    int x_click,y_click,click_valid=0;
    while(!click_valid) {
        while(!ismouseclick(WM_LBUTTONDOWN)) delay(100);
        getmouseclick(WM_LBUTTONDOWN,x_click,y_click);
        if(x_click>20 && x_click<200 && y_click>40 && y_click<100) return 0; //tastatura
        else if(x_click>230 && x_click<410 && y_click>40 && y_click<100) return 1; //fisier
        else if(x_click>20 && x_click<230 && y_click>670 && y_click<730) return 2; //inapoi
    }
}
void stergeLinieMatrice(int linie, matrix matriceDeColorat, int time_delay) {

    int i,j,u,w;
    int x1=matriceDeColorat.x,
        y1=matriceDeColorat.y;

    w=y1+1;
    u=x1+1;

    w+=80*linie;

    delay(time_delay);

    for(i=0;i<matriceDeColorat.coloane;i++) {
        setfillstyle(SOLID_FILL,BLACK);
        bar(u,w,u+78,w+78);

        u+=80;
    }
}
void coloreazaLinieMatrice(int linie, matrix matriceDeColorat, int culoare, int time_delay) {
    int prec;
    int i,j,u,w;
    int x1=matriceDeColorat.x,
        x2=x1+80,
        y1=matriceDeColorat.y,
        y2=y1+80;



    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=80/2+y1-10;
    u=80/2+x1;

    w+=80*linie;

    stergeLinieMatrice(linie,matriceDeColorat,time_delay>1?time_delay-1:0);
    delay(time_delay>1?1:0);

    for(i=0;i<matriceDeColorat.coloane;i++) {
        setcolor(culoare);
        stergeElemMatrice(matriceDeColorat,linie,i,0);
        bgiout<<trunchiaza(matriceDeColorat.elem[linie][i]);

        int cifre = nr_caractere(matriceDeColorat.elem[linie][i]);
        if(cifre==1) outstreamxy(u,w);
        else if(cifre==2) outstreamxy(u-14,w);
        else if(cifre==3) outstreamxy(u-17,w);
        else outstreamxy(u-30,w);

        u+=80;
    }
}

void stergeLinieIncompletaMatrice(int linie, int coloanaStart, int coloanaSfarsit, matrix matriceDeColorat, int time_delay) {

    int i,j,u,w;
    int x1=matriceDeColorat.x,
        y1=matriceDeColorat.y;

    w=y1+1;
    u=x1+1;

    w+=80*linie;

    delay(time_delay);

    for(i=coloanaStart;i<coloanaSfarsit;i++) {
        setfillstyle(SOLID_FILL,BLACK);
        bar(u,w,u+78,w+78);

        u+=80;
    }
}

void coloreazaLinieIncompletaMatrice(int linie, int coloanaStart, int coloanaSfarsit, matrix matriceDeColorat, int culoare, int time_delay) {
    int prec;
    int i,j,u,w;
    int x1=matriceDeColorat.x,
        x2=x1+80,
        y1=matriceDeColorat.y,
        y2=y1+80;

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=80/2+y1-10;
    u=80/2+x1;

    w+=80*linie;

    stergeLinieIncompletaMatrice(linie,coloanaStart,coloanaSfarsit,matriceDeColorat,time_delay>1?time_delay-1:0);
    delay(time_delay>1?1:0);

    for(i=coloanaStart;i<coloanaSfarsit;i++) {
        setcolor(culoare);
        stergeElemMatrice(matriceDeColorat,linie,j,0);
        bgiout<<trunchiaza(matriceDeColorat.elem[linie][i]);

        int cifre = nr_caractere(matriceDeColorat.elem[linie][i]);
        if(cifre==1) outstreamxy(u,w);
        else if(cifre==2) outstreamxy(u-14,w);
        else if(cifre==3) outstreamxy(u-17,w);
        else outstreamxy(u-30,w);

        u+=80;
    }
}
void stergeColoanaMatrice(int coloana, matrix matriceDeColorat, int time_delay) {

    int i,j,u,w;
    int x1=matriceDeColorat.x,
        y1=matriceDeColorat.y;

    w=y1+1;
    u=x1+1;


    u+=80*coloana;


    delay(time_delay);

    for(j=0;j<matriceDeColorat.linii;j++) {
        setfillstyle(SOLID_FILL,BLACK);
        bar(u,w,u+78,w+78);

        w+=80;
    }
}
void coloreazaColoanaMatrice(int coloana, matrix matriceDeColorat, int culoare, int time_delay) {
    int prec;
    int i,j,u,w;
    int x1=matriceDeColorat.x,
        x2=x1+80,
        y1=matriceDeColorat.y,
        y2=y1+80;

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=80/2+y1-10;
    u=80/2+x1;

    u+=80*coloana;

    stergeColoanaMatrice(coloana,matriceDeColorat,time_delay>1?time_delay-1:0);
    delay(time_delay>1?1:0);

    for(j=0;j<matriceDeColorat.linii;j++) {
        setcolor(culoare);
        stergeElemMatrice(matriceDeColorat,j,coloana,0);
        bgiout<<trunchiaza(matriceDeColorat.elem[j][coloana]);

        int cifre = nr_caractere(matriceDeColorat.elem[j][coloana]);
        if(cifre==1) outstreamxy(u,w);
        else if(cifre==2) outstreamxy(u-14,w);
        else if(cifre==3) outstreamxy(u-17,w);
        else outstreamxy(u-30,w);

        w+=80;
    }
}
void stergeColoanaIncompletaMatrice(int coloana, int linieStart, int linieSfarsit, matrix matriceDeColorat, int time_delay) {

    int i,j,u,w;
    int x1=matriceDeColorat.x,
        y1=matriceDeColorat.y;

    w=y1+1;
    u=x1+1;

    u+=80*coloana;
    w+=80*linieStart;

    delay(time_delay);

    for(j=linieStart;j<=linieSfarsit;j++) {
        setfillstyle(SOLID_FILL,BLACK);
        bar(u,w,u+78,w+78);

        w+=80;
    }
}

void coloreazaColoanaIncompletaMatrice(int coloana, int linieStart, int linieSfarsit, matrix matriceDeColorat, int culoare, int time_delay) {
    int i,j,u,w;
    int x1=matriceDeColorat.x,
        x2=x1+80,
        y1=matriceDeColorat.y,
        y2=y1+80;
    int prec;

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=80/2+y1-10;
    u=80/2+x1;

    u+=80*coloana;
    w+=80*linieStart;

    stergeColoanaIncompletaMatrice(coloana,linieStart,linieSfarsit,matriceDeColorat,time_delay>1?time_delay-1:0);
    delay(time_delay>1?1:0);

    for(j=linieStart;j<=linieSfarsit;j++) {
        setcolor(culoare);
        stergeElemMatrice(matriceDeColorat,j,coloana,0);
        bgiout<<trunchiaza(matriceDeColorat.elem[j][coloana]);

        int cifre = nr_caractere(matriceDeColorat.elem[j][coloana]);
        if(cifre==1) outstreamxy(u,w);
        else if(cifre==2) outstreamxy(u-14,w);
        else if(cifre==3) outstreamxy(u-17,w);
        else outstreamxy(u-30,w);

        w+=80;
    }
}
void stergeDiagonalaPrincipalaMatrice(matrix &matriceDeColorat, int timeDelay) {
    int i,j,u,w;
    int x1=matriceDeColorat.x,
        y1=matriceDeColorat.y;

    w=y1+1;
    u=x1+1;

    delay(timeDelay);

    for(i=0;i<matriceDeColorat.coloane;i++) {
        setfillstyle(SOLID_FILL,BLACK);
        bar(u,w,u+78,w+78);

        u+=80;
        w+=80;
    }
}
void coloreazaDiagonalaPrincipalaMatrice(matrix &matriceDeColorat, int culoare, int timeDelay) {
    int i,j,u,w;
    int x1=matriceDeColorat.x,
        x2=x1+80,
        y1=matriceDeColorat.y,
        y2=y1+80;
    int prec;

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=80/2+y1-10;
    u=80/2+x1;

    stergeDiagonalaPrincipalaMatrice(matriceDeColorat,timeDelay>1?timeDelay-1:0);
    delay(timeDelay>1?1:0);

    for(i=0;i<matriceDeColorat.coloane;i++) {
        setcolor(culoare);
        stergeElemMatrice(matriceDeColorat,i,i,0);
        bgiout<<trunchiaza(matriceDeColorat.elem[i][i]);

        int cifre = nr_caractere(matriceDeColorat.elem[i][i]);
        if(cifre==1) outstreamxy(u,w);
        else if(cifre==2) outstreamxy(u-14,w);
        else if(cifre==3) outstreamxy(u-17,w);
        else outstreamxy(u-30,w);

        u+=80;
        w+=80;
    }
}

float trunchiaza(float x){
    x = x*10;
    x=(int) x;
    return (float)x /10;
}

void afiseazaInmultireCoeficient(float coeficient, int x, int y, int timeDelay) {

    setcolor(GREEN);
    bgiout<<"x("<<trunchiaza(coeficient)<<")+";
    delay(timeDelay);
    outstreamxy(x,y);
    setcolor(WHITE);
}
void afiseazaImpartireLinie(float coeficient, int x, int y, int timeDelay) {

    setcolor(GREEN);
    bgiout<<"/("<<trunchiaza(coeficient)<<")";
    delay(timeDelay);
    outstreamxy(x,y);
    setcolor(WHITE);
}
void afiseazaInmultireSemn(unsigned int numarInversiuni, float determinant, int x, int y, int timeDelay) {

    delay(timeDelay);

    bgiout<<"determinant=(-1)  x"<<trunchiaza(determinant);
    outstreamxy(x,y);

    setcolor(RED);
    bgiout<<numarInversiuni;
    outstreamxy(x+textwidth("determinant=(-1)"),y-10);
    setcolor(WHITE);
}
void inverseaza(int number, int &invers) {
    int copie = number;
    invers = 0;

    if(number<0)
        copie=-copie;

    while(copie){
        invers = invers*10 + copie%10;
        copie/=10;
    }

    if(number<0)
        invers=-invers;
}
void nrCifre(int number, unsigned int &nrCaractere) {
    if(number!=0) {
        unsigned int copie = number;
        nrCaractere = 0;
        while(copie){
            copie/=10;
            nrCaractere++;
        }
    }
    else nrCaractere = 1;
}
void toString(float number,char convertedString[4]){
    unsigned int nrCaractere = 0;
    int invers = 0;

    nrCaractere = nr_caractere(number);

    inverseaza(number,invers);

    unsigned int i;

    if(number<0)
        convertedString[0]='-';

    for(i=number<0?1:0;i<nrCaractere;i++){
        convertedString[i]=(char)(invers%10+'0');
        invers/=10;
    }
    convertedString[i]='.';
    convertedString[++i]='\0';
}
void stergeInmultireCoeficient(float coeficient,int x,int y,int timeDelay){

    char coeficient_sir[4];
    toString(coeficient,coeficient_sir);

    setfillstyle(SOLID_FILL, BLACK);
    delay(timeDelay);
    bar(x,y,x+textwidth("x(")+textwidth(coeficient_sir)+textwidth(")+")+10 , y+textheight("("));
    setcolor(WHITE);

}
void stergeImpartireLinie(float coeficient,int x,int y,int timeDelay){

    char coeficient_sir[4];
    toString(coeficient,coeficient_sir);

    setfillstyle(SOLID_FILL, BLACK);
    delay(timeDelay);
    bar(x,y,x+textwidth("/(")+textwidth(coeficient_sir)+textwidth(")")+20,y+textheight("/"));
    setcolor(WHITE);

}
void stergeInmultireSemn(int numarInversiuni,float determinant,int x,int y,int timeDelay){
    char determinant_sir[4];
    toString(determinant,determinant_sir);

    delay(timeDelay);

    setcolor(BLACK);
    bar(x,y-10,x+textwidth("determinant=(-1) x")+textwidth(determinant_sir)+textwidth(".00"),y+textheight("("));
    setcolor(WHITE);
}
void aduna_linie_ori_coeficient_la_linie_grafica(int linieDeAdunat, float coeficient, int linieLaCareSeAduna, matrix &matrix1, int coloanaPt0) {
    int i,j,k;
    i=linieDeAdunat;
    j=linieLaCareSeAduna;

    coloreazaLinieMatrice(i,matrix1,GREEN,0);
    afiseazaInmultireCoeficient(coeficient,matrix1.x+80*matrix1.coloane+10,matrix1.y+80*i+(80-textheight("0"))/2,0);
    coloreazaLinieMatrice(j,matrix1,RED,300);


    stergeInmultireCoeficient(coeficient,matrix1.x+80*matrix1.coloane+10,matrix1.y+80*i+(80-textheight("0"))/2,300);
    coloreazaLinieMatrice(i,matrix1,WHITE,0);

    for(k=0;k<matrix1.coloane;k++) matrix1.elem[j][k] = coeficient*matrix1.elem[i][k] + matrix1.elem[j][k];
    matrix1.elem[j][coloanaPt0]=0;

    coloreazaLinieMatrice(j,matrix1,WHITE,500);

}
void afiseazaCalculareaCoeficientului(float deimpartit, float impartitor, int x, int y, int culoare, int timeDelay) {
    float rezultat = deimpartit/impartitor;
    setcolor(culoare);
    bgiout<<trunchiaza(deimpartit)<<"/"<<trunchiaza(impartitor)<<"="<<trunchiaza(rezultat);
    delay(timeDelay);
    outstreamxy(x,y);
}
void stergeCalculareaCoeficientului(float deimpartit, float impartitor, int x, int y, int culoareFundal, int timeDelay) {
    float rezultat = deimpartit/impartitor;
    int inaltimeText,latimeText;
    setfillstyle(SOLID_FILL,culoareFundal);
    char deimpartit_text[4],impartitor_text[4],rezultat_text[4];

    toString(deimpartit,deimpartit_text);
    toString(impartitor,impartitor_text);
    toString(rezultat,rezultat_text);

    latimeText = textwidth(deimpartit_text)+textwidth("/")+textwidth(impartitor_text)+textwidth("=")+textwidth(rezultat_text)+20;
    inaltimeText = textheight("/");
    delay(timeDelay);
    bar(x,y,x+latimeText,y+inaltimeText);
}

void obtine_zero_pe_coloana_sub_linie_grafica(int coloana,int linie, matrix &matrix1) {
    int i,j;
    float coeficient;
    i=coloana;
    j=linie;
    int x_calcul,y_calcul;

    for(j=i+1;j<matrix1.linii;j++) {
        coeficient = matrix1.elem[j][i]/matrix1.elem[i][i];

        stergeElemMatrice(matrix1,i,i,0);
        putNumber(matrix1.elem[i][i],matrix1.x+80/2+80*i,matrix1.y+(80-textheight("0"))/2+80*i,RED,0);
        stergeElemMatrice(matrix1,j,i,0);
        putNumber(matrix1.elem[j][i],matrix1.x+80/2+80*i,matrix1.y+(80-textheight("0"))/2+80*j,RED,0);

        x_calcul = matrix1.x+80*matrix1.coloane+30;
        y_calcul = matrix1.y+80*matrix1.linii/2;
        afiseazaCalculareaCoeficientului(matrix1.elem[j][i],matrix1.elem[i][i],x_calcul,y_calcul,RED,0);
        stergeCalculareaCoeficientului(matrix1.elem[j][i],matrix1.elem[i][i],x_calcul,y_calcul,BLACK,1000);

        stergeElemMatrice(matrix1,i,i,0);
        putNumber(matrix1.elem[i][i],matrix1.x+80/2+80*i,matrix1.y+(80-textheight("0"))/2+80*i,WHITE,0);
        stergeElemMatrice(matrix1,j,i,0);
        putNumber(matrix1.elem[j][i],matrix1.x+80/2+80*i,matrix1.y+(80-textheight("0"))/2+80*j,WHITE,0);

        aduna_linie_ori_coeficient_la_linie_grafica(i,-coeficient,j,matrix1,i);
    }
}
void inverseaza_linii_grafica(matrix &matrix1, unsigned int i, unsigned int j) {
    coloreazaLinieMatrice(i,matrix1,RED,0);
    coloreazaLinieMatrice(j,matrix1,GREEN,1000);

    for(int k=0;k<matrix1.linii;k++) interchimba(matrix1.elem[i][k],matrix1.elem[j][k]);

    coloreazaLinieMatrice(i,matrix1,GREEN,0);
    coloreazaLinieMatrice(j,matrix1,RED,1000);

    coloreazaLinieMatrice(i,matrix1,WHITE,0);
    coloreazaLinieMatrice(j,matrix1,WHITE,0);
}

void cautaPozitieLinieElemNenulInColoana_grafica(matrix matrix1, int coloana, int &pozitie) {
    int j,x_matrix1_center,y_matrix1_center;

    y_matrix1_center=80/2+matrix1.y-10;
    x_matrix1_center=80/2+matrix1.x;

    y_matrix1_center+=coloana*80;
    x_matrix1_center+=coloana*80;

    for(j=coloana;j<matrix1.linii;j++) {
      stergeElemMatrice(matrix1,j,coloana,0);
      putNumber(matrix1.elem[j][coloana],x_matrix1_center,y_matrix1_center,RED,0);
      stergeElemMatrice(matrix1,j,coloana,999);
      putNumber(matrix1.elem[j][coloana],x_matrix1_center,y_matrix1_center,WHITE,1);

      if(matrix1.elem[j][coloana]!=0) break;

      y_matrix1_center += 80;
    }

    pozitie = j;
}
void determinant_matrice_grafica(matrix matrix1, float &determinant) {
    int i,j,k;
    unsigned int nrInversari=0;
    int x_determinant,y_determinant,x_nrInversari,y_nrInversari;
    bool matriceSingulara = false;

    x_determinant = matrix1.x+80*matrix1.coloane+80;
    y_determinant = matrix1.y+80*matrix1.linii/2;

    x_nrInversari = matrix1.x;
    y_nrInversari = matrix1.y+80*matrix1.linii+50;


    for(i=0;i<matrix1.coloane-1;i++){

        coloreazaColoanaMatrice(i,matrix1,RED,0);
        coloreazaColoanaMatrice(i,matrix1,WHITE,450);

        cautaPozitieLinieElemNenulInColoana_grafica(matrix1,i,j);

        if(j==matrix1.linii){
            determinant=0;
            matriceSingulara = true;
            setcolor(WHITE);
            bgiout<<"determinant="<<trunchiaza(determinant);
            outstreamxy(x_determinant,y_determinant);
            break;
        }
        else {
            if(j!=i) {
                inverseaza_linii_grafica(matrix1,i,j);
                nrInversari++;
                setcolor(WHITE);
                bgiout<<"Numar inversari linii = "<<nrInversari;
                outstreamxy(x_nrInversari,y_nrInversari);
            }

            coloreazaColoanaIncompletaMatrice(i,j+1,matrix1.linii-1,matrix1,RED,0);
            coloreazaColoanaIncompletaMatrice(i,j+1,matrix1.linii-1,matrix1,WHITE,450);

            obtine_zero_pe_coloana_sub_linie_grafica(i,j,matrix1);
        }
    }

    if(!matriceSingulara) {

        determinant = 1;
        for(j=0;j<matrix1.linii;j++) determinant*=matrix1.elem[j][j];
        coloreazaDiagonalaPrincipalaMatrice(matrix1,RED,0);
//time

        setcolor(WHITE);
        if(determinant!=0){
            setcolor(WHITE);
            bgiout<<"determinant="<<trunchiaza(determinant);
            outstreamxy(x_determinant,y_determinant);
            coloreazaDiagonalaPrincipalaMatrice(matrix1,WHITE,450);

            afiseazaInmultireSemn(nrInversari,determinant,x_determinant,y_determinant,0);

            determinant*=(nrInversari%2==0)?1:-1;
            stergeInmultireSemn(nrInversari,determinant,x_determinant,y_determinant,1000);

            bgiout<<"determinant="<<trunchiaza(determinant);;
            outstreamxy(x_determinant,y_determinant);
        }
        else {
             determinant=0;
             bgiout<<"determinant="<<determinant;
             outstreamxy(x_determinant,y_determinant);
             coloreazaDiagonalaPrincipalaMatrice(matrix1,WHITE,450);
            }
    }
}
void aduna_linie_ori_coeficient_la_linie_douaMatrici_grafica(int linieDeAdunat, float coeficient, int linieLaCareSeAduna, matrix &matrix1, matrix &matrix2) {
        int i,j,k;
        i=linieDeAdunat;
        j=linieLaCareSeAduna;

        coloreazaLinieMatrice(i,matrix1,GREEN,0);
        coloreazaLinieMatrice(i,matrix2,GREEN,0);
        afiseazaInmultireCoeficient(coeficient,matrix2.x+80*matrix2.coloane+10,matrix1.y+80*i+(80-textheight("0"))/2,1000);
        coloreazaLinieMatrice(j,matrix1,RED,1000);
        coloreazaLinieMatrice(j,matrix2,RED,0);

        coloreazaLinieMatrice(i,matrix1,WHITE,0);
        coloreazaLinieMatrice(i,matrix2,WHITE,0);
        stergeInmultireCoeficient(coeficient,matrix2.x+80*matrix2.coloane+10,matrix1.y+80*i+(80-textheight("0"))/2,1000);

        for(k=0;k<matrix1.coloane;k++) {
            matrix1.elem[j][k]=coeficient*matrix1.elem[i][k]+matrix1.elem[j][k];
            matrix2.elem[j][k]=coeficient*matrix2.elem[i][k]+matrix2.elem[j][k];
        }
        matrix1.elem[j][i] = 0;

        coloreazaLinieMatrice(j,matrix1,RED,1000);
        coloreazaLinieMatrice(j,matrix2,RED,0);
        coloreazaLinieMatrice(j,matrix1,WHITE,0);
        coloreazaLinieMatrice(j,matrix2,WHITE,0);
}
void obtine_zero_pe_coloana_deasupra_linie_douaMatrici_grafica(int coloana, int linie, matrix &matrix1, matrix &matrix2) {
        int i,j;
        int x_calcul,y_calcul;
        float coeficient;
        i=coloana;
        j=linie;

        for(j=i-1;j>=0;j--) {
            cout<<i<<' '<<j;
            coeficient = matrix1.elem[j][i];

            stergeElemMatrice(matrix1,i,i,0);
            putNumber(matrix1.elem[i][i],matrix1.x+80/2+80*i,matrix1.y+(80-textheight("0"))/2+80*i,RED,0);
            stergeElemMatrice(matrix1,j,i,0);
            putNumber(matrix1.elem[j][i],matrix1.x+80/2+80*i,matrix1.y+(80-textheight("0"))/2+80*j,RED,0);

            x_calcul = matrix2.x+80*matrix2.coloane+30;
            y_calcul = matrix1.y+80*matrix1.linii/2;
            afiseazaCalculareaCoeficientului(matrix1.elem[j][i],matrix1.elem[i][i],x_calcul,y_calcul,RED,0);
            stergeCalculareaCoeficientului(matrix1.elem[j][i],matrix1.elem[i][i],x_calcul,y_calcul,BLACK,1000);

            stergeElemMatrice(matrix1,i,i,0);
            putNumber(matrix1.elem[i][i],matrix1.x+80/2+80*i,matrix1.y+(80-textheight("0"))/2+80*i,WHITE,0);
            stergeElemMatrice(matrix1,j,i,0);
            putNumber(matrix1.elem[j][i],matrix1.x+80/2+80*i,matrix1.y+(80-textheight("0"))/2+80*j,WHITE,0);

            //aduna_linie_ori_coeficient_la_linie_grafica(i,-coeficient,j,matrix2,i);
            aduna_linie_ori_coeficient_la_linie_douaMatrici_grafica(i,-coeficient,j,matrix1,matrix2);
            matrix1.elem[j][i] = 0;
        }
}
void obtine_zero_deasupra_diagonalei_douaMatrici_grafica( matrix &matrix1, matrix &matrix2) {
    int j;
    for(j=matrix1.linii-1;j>0;j--) {

        coloreazaColoanaIncompletaMatrice(j,j,0,matrix1,RED,0);
        coloreazaColoanaIncompletaMatrice(j,j,0,matrix1,WHITE,1000);

        obtine_zero_pe_coloana_deasupra_linie_douaMatrici_grafica(j,j,matrix1,matrix2);
    }
}
void obtine_zero_pe_coloana_sub_linie_douaMatrici_grafica(int coloana, int linie, matrix &matrix1, matrix &matrix2, bool &inversabila) {
        int i,j,k;
        int x_calcul,y_calcul;
        float coeficient;
        bool numaiZerouri=false;
        j=linie;
        i=coloana;

        for(j=i+1;j<matrix1.linii && inversabila;j++) {
            coeficient=matrix1.elem[j][i]/matrix1.elem[i][i];

            stergeElemMatrice(matrix1,i,i,0);
            putNumber(matrix1.elem[i][i],matrix1.x+80/2+80*i,matrix1.y+(80-textheight("0"))/2+80*i,RED,0);
            stergeElemMatrice(matrix1,j,i,0);
            putNumber(matrix1.elem[j][i],matrix1.x+80/2+80*i,matrix1.y+(80-textheight("0"))/2+80*j,RED,0);

            x_calcul = matrix2.x+80*matrix2.coloane+50;
            y_calcul = matrix1.y+80*matrix1.linii/2;
            afiseazaCalculareaCoeficientului(matrix1.elem[j][i],matrix1.elem[i][i],x_calcul,y_calcul,RED,1000);
            stergeCalculareaCoeficientului(matrix1.elem[j][i],matrix1.elem[i][i],x_calcul,y_calcul,BLACK,0);

            stergeElemMatrice(matrix1,i,i,0);
            putNumber(matrix1.elem[i][i],matrix1.x+80/2+80*i,matrix1.y+(80-textheight("0"))/2+80*i,WHITE,0);
            stergeElemMatrice(matrix1,j,i,0);
            putNumber(matrix1.elem[j][i],matrix1.x+80/2+80*i,matrix1.y+(80-textheight("0"))/2+80*j,WHITE,0);

            aduna_linie_ori_coeficient_la_linie_douaMatrici_grafica(i,-coeficient,j,matrix1,matrix2);

            numaiZerouri=true;
            for(k=0;k<matrix1.coloane;k++)
                if(matrix1.elem[j][k]!=0) numaiZerouri=false;

            if(numaiZerouri) {
                clean();
            	bgiout<<"Matricea nu este inversabila";
            	outstreamxy(10,10);
                inversabila=false;
            }
        }
}
void imparte_linie_la_scalar_douaMatrici(int linie, float scalar, matrix &matrix1, matrix &matrix2) {
    int i,j;
    i=linie;

    coloreazaLinieMatrice(i,matrix1,RED,800);
    coloreazaLinieMatrice(i,matrix2,RED,0);

    for(j=0;j<matrix1.coloane;j++){
        matrix1.elem[i][j]/=scalar;
        matrix2.elem[i][j]/=scalar;
    }

    coloreazaLinieMatrice(i,matrix1,RED,800);
    coloreazaLinieMatrice(i,matrix2,RED,0);

    coloreazaLinieMatrice(i,matrix1,WHITE,800);
    coloreazaLinieMatrice(i,matrix2,WHITE,0);
}

void inverseaza_linii(matrix &x, unsigned int i, unsigned int j) {
    int k;
    for(k=0;k<x.linii;k++) interchimba(x.elem[i][k],x.elem[j][k]);
}
void inverseaza_linii_douaMatrici_grafica(matrix &matrix1, matrix &matrix2, unsigned int i, unsigned int j) {

    coloreazaLinieMatrice(i,matrix1,RED,0);
    coloreazaLinieMatrice(i,matrix2,RED,0);
    coloreazaLinieMatrice(j,matrix1,GREEN,0);
    coloreazaLinieMatrice(j,matrix2,GREEN,0);

    for(int k=0;k<matrix1.linii;k++) interchimba(matrix1.elem[i][k],matrix1.elem[j][k]);
    for(int k=0;k<matrix2.linii;k++) interchimba(matrix2.elem[i][k],matrix2.elem[j][k]);

    coloreazaLinieMatrice(i,matrix1,GREEN,800);
    coloreazaLinieMatrice(i,matrix2,GREEN,0);
    coloreazaLinieMatrice(j,matrix1,RED,800);
    coloreazaLinieMatrice(j,matrix2,RED,0);

    coloreazaLinieMatrice(i,matrix1,WHITE,0);
    coloreazaLinieMatrice(i,matrix2,WHITE,0);
    coloreazaLinieMatrice(j,matrix1,WHITE,0);
    coloreazaLinieMatrice(j,matrix2,WHITE,0);
}
void inversare_matrice_grafica(matrix matrix1, matrix &matrix2,bool &inversabila) {
    matrix inv;
    inv.linii=matrix1.linii;
    inv.coloane=matrix1.linii;
    bool vida=true;
    matrice_identitate(inv);

    inv.x = matrix1.x+80*matrix1.coloane+5;
    inv.y=matrix1.y;
    afisare_ecran_matrice_grafica(inv,WHITE);

    int i,j;
    float lambda=0;
    bool numaiZerouri=false;
    unsigned int nrInversari=0;
    float elemNenul;

    inversabila=true;

    for(i=0;i<matrix1.coloane && inversabila;i++) {
        coloreazaColoanaMatrice(i,matrix1,RED,0);
        coloreazaColoanaMatrice(i,matrix2,RED,0);
        coloreazaColoanaMatrice(i,matrix1,WHITE,800);
        coloreazaColoanaMatrice(i,matrix2,WHITE,0);

        cautaPozitieLinieElemNenulInColoana_grafica(matrix1,i,j);

        if(j==matrix1.linii) {
            clean();
            bgiout<<"Matricea nu este inversabila";
            outstreamxy(10,10);
            inversabila=false;
        }
        else {
            if(j!=i) inverseaza_linii_douaMatrici_grafica(matrix1,inv,i,j);
            elemNenul=matrix1.elem[i][i];

            afiseazaImpartireLinie(elemNenul,inv.x+inv.coloane*80+10,inv.y + 80/2 + i*80 - textheight("/")/2,0);

            imparte_linie_la_scalar_douaMatrici(i,elemNenul,matrix1,inv);

            stergeImpartireLinie(elemNenul,inv.x + inv.coloane*80 + 10,inv.y + 80/2 + i*80 - textheight("/")/2,450);

            coloreazaColoanaIncompletaMatrice(i,j,matrix1.linii-1,matrix1,RED,0);
            coloreazaColoanaIncompletaMatrice(i,j,matrix1.linii-1,matrix1,WHITE,800);

            obtine_zero_pe_coloana_sub_linie_douaMatrici_grafica(i,i,matrix1,inv,inversabila);
        }
    }
    if(inversabila) {
        obtine_zero_deasupra_diagonalei_douaMatrici_grafica(matrix1,inv);
        int x_initial,y_initial;
        x_initial = matrix2.x;
        y_initial = matrix2.y;
        matrix2=inv;
        matrix2.x = x_initial;
        matrix2.y = y_initial;
   }
}
void citire_fisier_afisare_matrice(matrix &m1, int x, int y, int color) {
    int w=80/2+y-10;
    int u=80/2+x;
    fin>>m1.linii>>m1.coloane; cout<<m1.linii<<" "<<m1.coloane<<endl<<endl;
    borders_and_lines(m1.linii,m1.coloane,x,y);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    for(int i=0;i<m1.linii;i++) {
        for(int j=0;j<m1.coloane;j++) {
            fin>>m1.elem[i][j]; cout<<m1.elem[i][j]<<" ";
            stergeElemMatrice(m1,i,j,49);
            putNumber(m1.elem[i][j],u,w,color,1);
            u+=80;
        }
        u=80/2+x;
        w+=80; cout<<endl;
    }
    cout<<endl;
}
void citire_tastatura_afisare_matrice(matrix &m1, int x, int y, int color) {
    int w=80/2+y-10;
    int u=80/2+x;
    cout<<"Nr linii: "; cin>>m1.linii;
    cout<<"Nr coloane: "; cin>>m1.coloane;
    cout<<"Introduceti elementele matricei:"<<endl;
    borders_and_lines(m1.linii,m1.coloane,x,y);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    for(int i=0;i<m1.linii;i++) {
        for(int j=0;j<m1.coloane;j++) {
            cin>>m1.elem[i][j];
            stergeElemMatrice(m1,i,j,199);
            putNumber(m1.elem[i][j],u,w,color,1);
            u+=80;
        }
        u=80/2+x;
        w+=80;
    }
}

void putNumber(float nr, int x, int y, int color, int time_delay) {
    int caractere;
    setcolor(color);
    caractere = nr_caractere(nr);
    bgiout<<trunchiaza(nr);
    if(caractere==1) outstreamxy(x,y);
    else if(caractere==2) outstreamxy(x-14,y);
    else if(caractere==3) outstreamxy(x-23,y);
    else outstreamxy(x-33,y); //cu minus
}
void stergeElemMatrice(matrix matrix1,int linie,int coloana,int time_delay){
    int prec;
    int i,j,u,w;
    int x1=matrix1.x,
        y1=matrix1.y;

    w=y1+1;
    u=x1+1;

    w+=80*linie;
    u+=80*coloana;

    setfillstyle(SOLID_FILL,BLACK);
    delay(time_delay);
    bar(u,w,u+78,w+78);
}
void afisare_ecran_vector_grafica_orizontala(vect v1, int color){
    int w=80/2+v1.y-10;
    int u=80/2+v1.x;

    borders_and_lines(1,v1.lungime,v1.x,v1.y);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);

    for(int i=0;i<v1.lungime;i++) {
        delElemVector(v1,i,0);
        putNumber(v1.elem[i],u,w,color,200);
        u+=80;
    }
}

void afisare_ecran_matrice_grafica(matrix m1, int color) {
    int w=80/2+m1.y-10;
    int u=80/2+m1.x;
    borders_and_lines(m1.linii,m1.coloane,m1.x,m1.y);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    for(int i=0;i<m1.linii;i++) {
        for(int j=0;j<m1.coloane;j++) {
            stergeElemMatrice(m1,i,j,0);
            putNumber(m1.elem[i][j],u,w,color,200);
            u+=80;
        }
        u=80/2+m1.x;
        w+=80;
    }
}
void adunare_matrice_grafica(matrix matrix1, matrix matrix2, matrix &matrix3) {
    if(matrix1.linii!=matrix2.linii || matrix1.coloane!=matrix2.coloane) {
        bgiout<<"Matricele trebuie sa aiba aceeasi dimensiune.";
        outstreamxy(30,matrix1.y+matrix1.linii*80+10);
    }
    else {
        bgiout<<"+ ";
        outstreamxy(matrix1.coloane*80+matrix1.x+20,(matrix1.linii*80+matrix1.y)/2);

        bgiout<<" = ";
        int x_egal = matrix2.x+matrix2.coloane*80+20;
        outstreamxy(x_egal,(matrix1.linii*80+matrix1.y)/2);

        matrix3.x=x_egal+50;
        matrix3.y=matrix2.y;
        matrix3.linii=matrix1.linii; matrix3.coloane=matrix2.coloane;
        borders_and_lines(matrix3.linii,matrix3.coloane,matrix3.x,matrix3.y);

        int i,j,k,x_matrix1_center,y_matrix1_center,x_matrix2_center,y_matrix2_center,x_matrix3_center,y_matrix3_center;
        y_matrix1_center=80/2+matrix1.y-10;
        x_matrix1_center=80/2+matrix1.x;
        y_matrix2_center=80/2+matrix2.y-10;
        x_matrix2_center=80/2+matrix2.x;
        y_matrix3_center=80/2+matrix3.y-10;
        x_matrix3_center=80/2+matrix3.x;

        if(matrix1.linii!=matrix2.linii || matrix1.coloane!=matrix2.coloane) cout<<"Imposibil.";
        else {
            for(i=0;i<matrix1.linii;i++) {
                for(j=0;j<matrix1.coloane;j++) {
                    stergeElemMatrice(matrix1,i,j,299);
                    putNumber(matrix1.elem[i][j],x_matrix1_center,y_matrix1_center,GREEN,1);
                    stergeElemMatrice(matrix2,i,j,299);
                    putNumber(matrix2.elem[i][j],x_matrix2_center,y_matrix2_center,GREEN,1);

                    matrix3.elem[i][j]=matrix1.elem[i][j] + matrix2.elem[i][j];

                    stergeElemMatrice(matrix3,i,j,299);
                    putNumber(matrix3.elem[i][j],x_matrix3_center,y_matrix3_center,GREEN,1);
                    stergeElemMatrice(matrix1,i,j,299);
                    putNumber(matrix1.elem[i][j],x_matrix1_center,y_matrix1_center,WHITE,1);
                    stergeElemMatrice(matrix2,i,j,0);
                    putNumber(matrix2.elem[i][j],x_matrix2_center,y_matrix2_center,WHITE,0);
                    stergeElemMatrice(matrix3,i,j,0);
                    putNumber(matrix3.elem[i][j],x_matrix3_center,y_matrix3_center,WHITE,0);
                    x_matrix1_center+=80; x_matrix2_center+=80; x_matrix3_center+=80;
                }
                x_matrix1_center=80/2+matrix1.x;
                y_matrix1_center+=80;
                x_matrix2_center=80/2+matrix2.x;
                y_matrix2_center+=80;
                x_matrix3_center=80/2+matrix3.x;
                y_matrix3_center+=80;
            }
            matrix3.linii=matrix1.linii;
            matrix3.coloane=matrix2.coloane;
        }
    }
}
void inmultire_scalar_matrice_grafica(matrix matrix1, float scalar, matrix &matrix2) {
    bgiout<<"x ";
    outstreamxy(matrix1.coloane*80+matrix1.x+20,(matrix1.linii*80+matrix1.y)/2);
    int x_scalar=matrix1.coloane*80+matrix1.x+40;
    int y_scalar=(matrix1.linii*80+matrix1.y)/2;
    putNumber(scalar,x_scalar,y_scalar,WHITE,0);
    bgiout<<" = ";
    outstreamxy(x_scalar+20,y_scalar);

    matrix2.x=x_scalar+70;
    matrix2.y=matrix1.y;
    matrix2.linii=matrix1.linii; matrix2.coloane=matrix1.coloane;
    borders_and_lines(matrix2.linii,matrix2.coloane,matrix2.x,matrix2.y);

    int i,j,x_matrix1_center,y_matrix1_center,x_matrix2_center,y_matrix2_center;
    y_matrix1_center=80/2+matrix1.y-10;
    x_matrix1_center=80/2+matrix1.x;
    y_matrix2_center=80/2+matrix2.y-10;
    x_matrix2_center=80/2+matrix2.x;
    for(i=0;i<matrix1.linii;i++) {
        for(j=0;j<matrix1.coloane;j++) {
            stergeElemMatrice(matrix1,i,j,299);
            putNumber(matrix1.elem[i][j],x_matrix1_center,y_matrix1_center,GREEN,1);
            putNumber(scalar,x_scalar,y_scalar,GREEN,300);
            matrix2.elem[i][j]=matrix1.elem[i][j]*scalar;
            stergeElemMatrice(matrix2,i,j,299);
            putNumber(matrix2.elem[i][j],x_matrix2_center,y_matrix2_center,GREEN,1);
            stergeElemMatrice(matrix1,i,j,299);
            putNumber(matrix1.elem[i][j],x_matrix1_center,y_matrix1_center,WHITE,1);
            putNumber(scalar,x_scalar,y_scalar,WHITE,0);
            stergeElemMatrice(matrix2,i,j,0);
            putNumber(matrix2.elem[i][j],x_matrix2_center,y_matrix2_center,WHITE,0);
            x_matrix1_center+=80; x_matrix2_center+=80;
        }
        x_matrix1_center=80/2+matrix1.x; x_matrix2_center=80/2+matrix2.x;
        y_matrix1_center+=80; y_matrix2_center+=80;
    }
}
void borders_and_lines(int n, int m, int x, int y) {
    int i,j,z,t,spatiu_x,spatiu_y;
    spatiu_x=x; spatiu_y=y;
    z=m*80+spatiu_x; t=n*80+spatiu_y;
    setcolor(WHITE);
    rectangle(x,y,z,t);
    x+=80; z=x;
    for(i=0;i<m-1;i++) {
        line(x,y,z,t);
        x+=80; z+=80;
    }
    x=spatiu_y+80; z=x; t=m*80+spatiu_x;
    for(i=0;i<n-1;i++) {
        line(spatiu_x,x,t,z);
        x+=80; z+=80;
    }
}
void sortare_numarare(vect x, vect &b) { //k valoarea maxima din x[], c[] vector de frecventa, b[] tabloul sortat
    int i,c[DMAX],k;
    k=x.elem[0];
    for(i=1;i<x.lungime;i++) if(x.elem[i]>k) k=x.elem[i];
    for(i=1;i<=k;i++) c[i]=0;
    for(i=0;i<x.lungime;i++) c[x.elem[i]]++;
    for(i=2;i<=k;i++) c[i]+=c[i-1]; //in c[i] vor fi cate elemente sunt mai mici decat i
    for(i=x.lungime-1;i>=0;i--) {
        b.elem[c[x.elem[i]]-1]=x.elem[i];
        c[x.elem[i]]--;
    }
    b.lungime=x.lungime;
}
void mergeArraysCrescator(vect &x, int st, int mijl, int dr) {
    int i,j,k,n1=mijl-st+1,n2=dr-mijl;
    int left[n1],right[n2];
    for(i=0;i<n1;i++) left[i]=x.elem[st+i];
    for(j=0;j<n2;j++) right[j]=x.elem[mijl+1+j];
    for(i=0,j=0,k=st;i<n1 && j<n2;k++) {
        if (left[i]<=right[j]) x.elem[k]=left[i++];
        else x.elem[k]=right[j++];
    }
    while(i<n1) x.elem[k++]=left[i++];
    while(j<n2) x.elem[k++]=right[j++];
}
void mergeSortCrescator(vect &x, int st, int dr) {
    if(st<dr) {
        int mijl=(st+dr)/2;
        mergeSortCrescator(x,st,mijl);
        mergeSortCrescator(x,mijl+1,dr);
        mergeArraysCrescator(x,st,mijl,dr);
    }
}
void sortareSelectieNaivaDescrescator(vect x, vect &z) {
    int i,j,imax;
    for(i=x.lungime-1;i>0;i--) {
        imax=i;
        for(j=i-1;j>=0;j--)
            if(x.elem[j]<x.elem[imax])
                imax=j;
        if(i!=imax)
            interchimba(x.elem[i],x.elem[imax]);
    }
    for(i=0;i<x.lungime;i++) z.elem[i]=x.elem[i];
    z.lungime=x.lungime;
}
void sortareSelectieNaivaCrescator(vect x, vect &z) {
    int i,j,imax;
    for(i=x.lungime-1;i>0;i--) {
        imax=i;
        for(j=i-1;j>=0;j--)
            if(x.elem[j]>x.elem[imax])
                imax=j;
        if(i!=imax)
            interchimba(x.elem[i],x.elem[imax]);
    }
    for(i=0;i<x.lungime;i++) z.elem[i]=x.elem[i];
    z.lungime=x.lungime;
}
void sortareInsertieDescrescator(vect x, vect &z) {
    int i,j,temp;
    for(i=1;i<x.lungime;i++) {
        temp=x.elem[i];
        for(j=i-1;j>=0 && x.elem[j]<temp;j--) x.elem[j+1]=x.elem[j];
        if(x.elem[j+1]!=temp) x.elem[j+1]=temp;
    }
    for(i=0;i<x.lungime;i++) z.elem[i]=x.elem[i];
    z.lungime=x.lungime;
}
void sortareInsertieCrescator(vect x, vect &z) {
    int i,j,temp;
    for(i=1;i<x.lungime;i++) {
        temp=x.elem[i];
        for(j=i-1;j>=0 && x.elem[j]>temp;j--) x.elem[j+1]=x.elem[j];
        if(x.elem[j+1]!=temp) x.elem[j+1]=temp;
    }
    for(i=0;i<x.lungime;i++) z.elem[i]=x.elem[i];
    z.lungime=x.lungime;
}
void bubbleSortCrescator(vect x, vect &z) {
    int i,j;
    for(i=0;i<x.lungime-1;i++) {
        for(j=0;j<x.lungime-i-1;j++) {
            if(x.elem[j]>x.elem[j+1]) interchimba(x.elem[j],x.elem[j+1]);
        }
    }
    for(i=0;i<x.lungime;i++) z.elem[i]=x.elem[i];
    z.lungime=x.lungime;
}
void bubbleSortDescrescator(vect x, vect &z) {
    int i,j;
    for(i=0;i<x.lungime-1;i++) {
        for(j=0;j<x.lungime-i-1;j++) {
            if(x.elem[j]<x.elem[j+1]) interchimba(x.elem[j],x.elem[j+1]);
        }
    }
    for(i=0;i<x.lungime;i++) z.elem[i]=x.elem[i];
    z.lungime=x.lungime;
}
int suma_sub_diag_secundara(matrix x) {
    int i,j,suma=0;
    for(i=1;i<x.linii;i++) for(j=x.coloane-i;j<x.coloane;j++) suma+=x.elem[i][j];
    return suma;
}
int suma_diag_secundara(matrix x) {
    int i,suma=0;
    if(x.linii!=x.coloane) cout<<"Introduceti o matrice patratica.";
    else {
        for(i=0;i<x.linii;i++) suma+=x.elem[i][x.linii-i-1];
        return suma;
    }
}
int produs_elemente_vector(vect x) {
    int produs=1;
    for(int i=0;i<x.lungime;i++) produs*=x.elem[i];
    return produs;
}
void putere_matrice(matrix x, int putere, matrix &z) {
    unsigned int i;

    if(putere>0) {
        inmultire_matrice(x,x,z);
        for(i=3;i<=putere;i++) inmultire_matrice(z,x,z);
    }
    if(putere<0) {
        bool inversabila;
        putere=-putere;
        inversare_matrice(x,x,inversabila);

        if(inversabila) {
            inmultire_matrice(x,x,z);
            for(i=3;i<=putere;i++) inmultire_matrice(z,x,z);
        }
        else cout<<"Matrice neinversabila.\n";
    }
}
void inversare_matrice(matrix x, matrix &y, bool &inversabila) {
    matrix inv;
    inv.linii=x.linii;
    inv.coloane=x.linii;
    bool vida=true;
    matrice_identitate(inv);
    int i,j,k;
    float lambda=0;
    bool numaiZerouri=false;
    unsigned int nrInversari=0;
    float elemNenul;

    inversabila=true;

    for(i=0;i<x.coloane && inversabila;i++) {
        for(j=i;j<x.linii;j++) if(x.elem[j][i]!=0) break;
        if(j==x.linii) {
            cout<<"Matricea nu este inversabila";
            inversabila=false;
        }
        else {
            if(j!=i) {
                inverseaza_linii(x,i,j);
                inverseaza_linii(inv,i,j);
                nrInversari++;
            }
            elemNenul=x.elem[i][i];
            for(j=0;j<x.coloane;j++) {
                x.elem[i][j]/=elemNenul;
                inv.elem[i][j]/=elemNenul;
            }
            for(j=i+1;j<x.linii && inversabila;j++) {
                lambda=x.elem[j][i]/x.elem[i][i];
                numaiZerouri=true;
                for(k=0;k<x.coloane;k++) {
                    x.elem[j][k]=x.elem[j][k]-lambda*x.elem[i][k];
                    inv.elem[j][k]=inv.elem[j][k]-lambda*inv.elem[i][k];
                    if(x.elem[j][k]!=0) numaiZerouri=false;
                }
                if(numaiZerouri) {
                    cout<<"Matricea nu este inversabila";
                    inversabila=false;
                }
            }
        }
    }
    if(inversabila) {
        for(i=x.coloane-1;i>0;i--) {
            for(j=i-1;j>=0;j--) {
                lambda=x.elem[j][i];
                x.elem[j][i]=0;
                for(k=0;k<inv.coloane;k++) inv.elem[j][k]=inv.elem[j][k]-lambda*inv.elem[i][k];
            }
        }
        y=inv;
   }
}
void matrice_identitate(matrix &x) {
    unsigned int i,j;
    for(i=0;i<x.linii;i++)
    for(j=0;j<x.linii;j++)
        if(i==j)
            x.elem[i][j]=1;
        else
            x.elem[i][j]=0;
}
void impartire_matrice(matrix x, matrix y, matrix &rezultat) {
    matrix inversa;
    bool inversabila = true;
    inversare_matrice(y,inversa,inversabila);
    if(inversabila) inmultire_matrice(x,inversa,rezultat);
    else cout<<endl<<"A doua matrice nu este inversabila"<<endl;
    /* exemplu bun
    3 3
    10 20 30
    20 30 30
    10 20 20

    3 3
    1 1 3
    2 1 1
    1 1 1
    */
}
void inmultire_scalar_matrice(matrix x, float scalar, matrix &y) {
    int i,j;
    for(i=0;i<x.linii;i++) for(j=0;j<x.coloane;j++) y.elem[i][j]=x.elem[i][j]*scalar;
    y.linii=x.linii;
    y.coloane=x.coloane;
}
void inverseazaLinii(matrix &x, unsigned int i, unsigned int j) {
    for(int k=0;k<x.linii;k++) interchimba(x.elem[i][k],x.elem[j][k]);
}
void determinant_matrice(matrix x, float &determinant) {
    int i,j,k;
    float lambda;
    unsigned int nrInversari=0;
    for(i=0;i<x.linii-1;i++) {
        for(j=i;j<x.linii;j++) if(x.elem[j][i]!=0) break;
        if(j==x.linii) {
            determinant=0;
            break;
        }
        else {
            if(j!=i) {
                inverseazaLinii(x,i,j);
                nrInversari++;
            }
            for(j=i+1;j<x.linii;j++) {
                lambda=x.elem[j][i]/x.elem[i][i];
                for(k=0;k<x.coloane;k++) x.elem[j][k]=x.elem[j][k]-lambda*x.elem[i][k];
            }
            determinant=(nrInversari%2==0)?1:-1;
            for(j=0;j<x.linii;j++) determinant*=x.elem[j][j];
       }
    }
}
void scadere_matrice(matrix x, matrix y, matrix &z) {
    int i,j;
    if(x.linii!=y.linii) cout<<"Matricele trebuie sa aiba acelasi numar de linii pentru operatia de scadere."<<endl;
    else if(x.coloane!=y.coloane) cout<<"Matricele trebuie sa aiba acelasi numar de coloane pentru operatia de scadere."<<endl;
    else for(i=0;i<x.linii;i++)
            for(j=0;j<x.coloane;j++) {
                z.elem[i][j] = x.elem[i][j]-y.elem[i][j];
                z.coloane=x.coloane;
                z.linii=x.linii;
            }
}
void scadere_vector(vect x, vect y, vect &z) {
    if (x.lungime!=y.lungime) cout<<"Vectorii trebuie sa aiba lungimi egale pentru operatia de scadere."<<endl;
    else {
        for(int i=0;i<x.lungime;i++) z.elem[i]=x.elem[i]-y.elem[i];
        z.lungime=x.lungime;
    }
}
int **calcul_inversa(int **matr,int n) {
    int **rez=new int *[n],i,j,**minor,k,p;
    for(i=0;i<n;i++) rez[i]=new int[n];
    for(i=0;i<n;i++) {
        for(j=0;j<n;j++) {
            minor=calcul_minor(matr,j,i,n);
            rez[i][j]=((i+j)%2?1:-1)*calcul_det(minor,n-1);
        }
    }
    return rez;
}
int calcul_det(int **matr,int n) { //recursiv
    if(n==1) return matr[0][0];
    int i,s=0;
    for(i=0;i<n;i++) s+=matr[0][i]*(i%2?1:-1)*calcul_det(calcul_minor(matr,0,i,n),n-1);
    return s;
}
int **calcul_minor(int **matr,int lin,int col,int n) {
    int i,j,**a=new int*[n-1];
    for(i=0;i<n-1;i++) a[i]=new int[n-1];
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-1;j++) {
            if(i<lin) {
                if(j<col) a[i][j]=matr[i][j];
                else a[i][j]=matr[i][j+1];
            }
            else if(j<col) a[i][j]=matr[i+1][j];
            else a[i][j]=matr[i+1][j+1];
        }
    }
    return a;
}
int suma_deasupra_diag_principala(matrix x) {
    int s=0,i,j;
    for(i=0;i<x.linii;i++) for(j=0;j<x.coloane;j++) if(i<j) s+=x.elem[i][j];
    return s;
}
int suma_sub_diag_principala(matrix x) {
    int s=0,i,j;
    for(i=1;i<x.linii;i++) for(j=0;j<x.coloane;j++) if(i>j) s+=x.elem[i][j];
    return s;
}
int suma_diag_principala(matrix x) {
    int i,s=0;
    if(x.linii!=x.coloane) cout<<"Introduceti o matrice patratica.\n";
    else {
        for(i=0;i<x.linii;i++) s+=x.elem[i][i];
        return s;
    }
}
void inmultire_vector_scalar(vect x, vect &z, int scalar) {
    int i;
    for(i=0;i<x.lungime;i++) z.elem[i]=x.elem[i]*scalar;
    z.lungime=x.lungime;
}
void shiftare_stanga_vector(vect x, vect &z, int nr_poz) {
    int i,k=0;
    for(i=0;i<nr_poz;i++) z.elem[x.lungime-nr_poz+i]=x.elem[i];
    for(i=nr_poz;i<x.lungime;i++) z.elem[k++]=x.elem[i];
    z.lungime=x.lungime;
}
void shiftare_stanga_vector_grafica(vect x, vect &z, int nr_poz) {
    int i,j,k=0;
    int elem;
    for(j=0;j<nr_poz;j++) {
        elem = x.elem[0];
        cleardevice();
        afisare_ecran_vector_grafica_orizontala(x,WHITE);
        for(i=0;i<x.lungime-1;i++){
            delElemVector(x,i,0);
            coloreazaElemVector(x,i,RED,0);
            delElemVector(x,i+1,0);
            coloreazaElemVector(x,i+1,RED,0);

            x.elem[i]=x.elem[i+1];

            delElemVector(x,i,449);
            coloreazaElemVector(x,i,WHITE,1);
            delElemVector(x,i+1,0);
            coloreazaElemVector(x,i+1,WHITE,0);
        }
        delElemVector(x,x.lungime-1,0);
        coloreazaElemVector(x,x.lungime-1,RED,0);
        x.elem[x.lungime-1] = elem;
        delElemVector(x,x.lungime-1,0);
        coloreazaElemVector(x,x.lungime-1,RED,0);

        delElemVector(x,x.lungime-1,449);
        coloreazaElemVector(x,x.lungime-1,WHITE,1);
    }
    z=x;
}
void shiftare_dreapta_vector(vect x,vect &z,int nr_poz) {
    int i,k=0;
    for(i=x.lungime-nr_poz;i<x.lungime;i++) z.elem[k++]=x.elem[i];
    for(i=nr_poz;i<x.lungime;i++) z.elem[i]=x.elem[i-nr_poz];
    z.lungime=x.lungime;
}
void shiftare_dreapta_vector_grafica(vect x,vect &z,int nr_poz) {
    int i,j,k=0,aux,elemAnterior;

     for(j=0;j<nr_poz;j++){
        elemAnterior = x.elem[0];
        cleardevice();
        afisare_ecran_vector_grafica_orizontala(x,WHITE);
        for(i=1;i<x.lungime;i++) {
            delElemVector(x,i-1,0);
            coloreazaElemVector(x,i-1,RED,0);
            delElemVector(x,i,0);
            coloreazaElemVector(x,i,RED,0);

            aux = x.elem[i];
            x.elem[i] = elemAnterior;
            elemAnterior = aux;

            delElemVector(x,i-1,449);
            coloreazaElemVector(x,i-1,WHITE,1);
            delElemVector(x,i,0);
            coloreazaElemVector(x,i,WHITE,0);
        }
        delElemVector(x,0,0);
        coloreazaElemVector(x,0,RED,0);
        x.elem[0] = elemAnterior;
        delElemVector(x,i,449);
        coloreazaElemVector(x,0,WHITE,1);
     }
    z=x;
}
int suma_elemente_vector(vect x) {
    int s=0,i;
    for(i=0;i<x.lungime;i++) s+=x.elem[i];
    return s;
}
void produs_scalar_grafica(vect vect1, vect vect2, int &suma){
    int i;
    int produs;
    if(vect1.lungime!=vect2.lungime) cout<<"Vectori trebuie sa aiba dimensiuni egale";
    else{
        bgiout<<"x";
        outstreamxy(vect1.x+80+20,(vect1.y+vect1.lungime*80)/2);

        int x_egal,y_egal;
        x_egal = vect2.x+80+10;
        y_egal = (vect2.y+vect2.lungime*80)/2;
        bgiout<<"=";
        outstreamxy(x_egal,y_egal);

        int x_produs,y_produs,x_plus,y_plus;
        x_produs = x_egal+textwidth("=")+10;
        y_produs = y_egal;
        y_plus = y_egal;


        char produs_sir[4];
        suma=0;

        for(i=0;i<vect1.lungime;i++){

            produs = vect1.elem[i]*vect2.elem[i];
            suma += produs;

            delElemVector(vect1,i,0);
            coloreazaElemVector(vect1,i,RED,0);
            delElemVector(vect2,i,0);
            coloreazaElemVector(vect2,i,RED,0);

            bgiout<<produs;
            outstreamxy(x_produs,y_produs);

            toString(produs,produs_sir);

            x_plus = x_produs + textwidth(produs_sir)+ 10;

            x_produs += textwidth(produs_sir) + textwidth("+")+ 20;

            if(i<vect1.lungime-1) {
                bgiout<<"+";
                outstreamxy(x_plus,y_plus);
            }

            delElemVector(vect1,i,449);
            coloreazaElemVector(vect1,i,WHITE,1);
            delElemVector(vect2,i,0);
            coloreazaElemVector(vect2,i,WHITE,0);
        }
        bgiout<<"=";
        outstreamxy(x_plus,y_plus);
        bgiout<<suma;
        outstreamxy(x_plus+textwidth("=")+10,y_plus);
    }
}
void produs_scalar(vect x, vect y, int &suma) {
    int i;
    if(x.lungime!=3 && y.lungime!=3) cout<<"Vectori trebuie sa aiba dimensiuni egale";
    else for(i=0;i<x.lungime;i++) suma+=x.elem[i]*y.elem[i];
}
void produs_vectorial(vect x, vect y, vect &z){
    if(x.lungime!=3 && y.lungime!=3) cout<<"Vectori trebuie sa aiba dimensiunea 3";
    else {
        z.elem[0] = x.elem[2]*y.elem[3] - x.elem[3]*y.elem[2];
        z.elem[1] = x.elem[3]*y.elem[1] - x.elem[1]*y.elem[3];
        z.elem[2] = x.elem[1]*y.elem[2] - x.elem[2]*y.elem[1];
        z.lungime = 3;
    }
}
void transpusa_matrice(matrix x,matrix &z) {
    int i,j;
    for(i=0;i<x.linii;i++) for(j=0;j<x.coloane;j++) z.elem[j][i]=x.elem[i][j];
    z.linii=x.coloane;
    z.coloane=x.linii;
}
void inmultire_matrice_grafica(matrix matrix1, matrix matrix2, matrix &matrix3) { //nr de coloane al primei matrice trebuie sa fie egal cu nr de linii al celei de-a doua matrice
    bgiout<<"x";
    outstreamxy(matrix1.coloane*80+matrix1.x+10,(matrix1.linii*80+matrix1.y)/2);

    bgiout<<"=";
    int x_egal = matrix2.x+matrix2.coloane*80+10;
    outstreamxy(x_egal,(matrix1.linii*80+matrix1.y)/2);

    matrix3.x=x_egal+textwidth("=")+10;
    matrix3.y=matrix2.y;
    matrix3.linii=matrix1.linii; matrix3.coloane=matrix2.coloane;
    borders_and_lines(matrix3.linii,matrix3.coloane,matrix3.x,matrix3.y);

    int i,j,k,x_matrix3_center,y_matrix3_center;

    y_matrix3_center=80/2+matrix3.y-10;
    x_matrix3_center=80/2+matrix3.x;

    if(matrix1.coloane!=matrix2.linii) {clean();bgiout<<"Imposibil";outstreamxy(10,10);}
    else {
        for(i=0;i<matrix1.linii;i++) for(j=0;j<matrix2.coloane;j++) matrix3.elem[i][j]=0;
        for(i=0;i<matrix1.linii;i++) {
            for(j=0;j<matrix2.coloane;j++) {
                for(k=0;k<matrix1.coloane;k++) matrix3.elem[i][j]+=matrix1.elem[i][k]*matrix2.elem[k][j];

                stergeLinieMatrice(i,matrix1,399);
                coloreazaLinieMatrice(i,matrix1,GREEN,1);
                stergeColoanaMatrice(j,matrix2,399);
                coloreazaColoanaMatrice(j,matrix2,GREEN,1);
                stergeElemMatrice(matrix3,i,j,399);
                putNumber(matrix3.elem[i][j],x_matrix3_center,y_matrix3_center,GREEN,1);

                stergeElemMatrice(matrix3,i,j,399);
                putNumber(matrix3.elem[i][j],x_matrix3_center,y_matrix3_center,WHITE,1);
                stergeColoanaMatrice(j,matrix2,0);
                coloreazaColoanaMatrice(j,matrix2,WHITE,0);
                stergeLinieMatrice(i,matrix1,0);
                coloreazaLinieMatrice(i,matrix1,WHITE,0);

                x_matrix3_center+=80;
            }
            x_matrix3_center=80/2+matrix3.x;
            y_matrix3_center+=80;
        }
        matrix3.linii=matrix1.linii;
        matrix3.coloane=matrix2.coloane;
    }
}
void clean(){
    setfillstyle(SOLID_FILL,BLACK);
    bar(0,0,1000,670);
}
void inmultire_matrice(matrix matrix1, matrix matrix2, matrix &matrix3) { //nr de coloane al primei matrice trebuie sa fie egal cu nr de linii al celei de-a doua matrice
    int i,j,k;
    if(matrix1.coloane!=matrix2.linii) {
        clean();
        bgiout<<"Imposibil.";
        outstreamxy(10,10);
    }
    else {
        for(i=0;i<matrix1.linii;i++) for(j=0;j<matrix2.coloane;j++) matrix3.elem[i][j]=0;
        for(i=0;i<matrix1.linii;i++) {
            for(j=0;j<matrix2.coloane;j++) {
                for(k=0;k<matrix1.coloane;k++) matrix3.elem[i][j]+=matrix1.elem[i][k]*matrix2.elem[k][j];
            }
        }
        matrix3.linii=matrix1.linii;
        matrix3.coloane=matrix2.coloane;
    }
}
void adunare_matrice(matrix x, matrix y, matrix &z) {
    int i,j;
    for(i=0;i<x.linii && i<y.linii;i++) {
        for(j=0;j<x.coloane && j<y.coloane;j++) {
            z.elem[i][j]=x.elem[i][j]+y.elem[i][j];
        }
        z.coloane=x.coloane; //daca au acelasi nr de coloane
        for(;j<x.coloane;j++) {
            z.elem[i][j]=x.elem[i][j];
            z.coloane=x.coloane;
        }
        for(;j<y.coloane;j++) {
            z.elem[i][j]=y.elem[i][j];
            z.coloane=y.coloane;
        }
    }
    z.linii=x.linii; //daca au acelasi nr de linii
    for(;i<x.linii;i++) {
        for(j=0;j<x.coloane;j++) z.elem[i][j]=x.elem[i][j];
        z.linii=x.linii;
    }
    for(;i<y.linii;i++) {
        for(j=0;j<y.coloane;j++) z.elem[i][j]=y.elem[i][j];
        z.linii=y.linii;
    }
}
void adunare_vector(vect x, vect y, vect &z) {
    int i;
    for(i=0;i<x.lungime && i<y.lungime;i++) z.elem[i]=x.elem[i]+y.elem[i];
    z.lungime=x.lungime; //daca au aceeasi lungime
    for(;i<x.lungime;i++) {
        z.elem[i]=x.elem[i];
        z.lungime=x.lungime;
    }
    for(;i<y.lungime;i++) {
        z.elem[i]=y.elem[i];
        z.lungime=y.lungime;
    }
}
void citire_fisier_vect(vect &x) {
    int i;
    fin>>x.lungime;
    for(i=0;i<x.lungime;i++) fin>>x.elem[i];
}
void citire_fisier_matr(matrix &x) {
    int i,j;
    fin>>x.linii;
    fin>>x.coloane;
    for(i=0;i<x.linii;i++) {
        for(j=0;j<x.coloane;j++) {
            fin>>x.elem[i][j];
        }
    }
}
void afisare_fisier_vect(vect x) {
    int i,j;
    for(i=0;i<x.lungime;i++) fout<<x.elem[i]<<" ";
    fout<<endl;
}
void afisare_fisier_matr(matrix x) {
    int i,j;
    for(i=0;i<x.linii;i++) {
        for(j=0;j<x.coloane;j++) {
            fout<<x.elem[i][j]<<" ";
        }
        fout<<endl;
    }
}
void citire_tastatura_vect(vect &x) {
    int i;
    cin>>x.lungime;
    for(i=0;i<x.lungime;i++) cin>>x.elem[i];
}
void citire_tastatura_matr(matrix &x) {
    int i,j;
    cin>>x.linii;
    cin>>x.coloane;
    for(i=0;i<x.linii;i++) {
        for(j=0;j<x.coloane;j++) {
            cin>>x.elem[i][j];
        }
    }
}
void afisare_ecran_vect(vect x) {
    int i;
    for(i=0;i<x.lungime;i++) cout<<x.elem[i]<<" ";
    cout<<endl;
}
void afisare_ecran_matr(matrix x) {
    int i,j;
    for(i=0;i<x.linii;i++) {
        for(j=0;j<x.coloane;j++) {
            cout<<x.elem[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
