#include <iostream>
#include <fstream>
#include <cmath>
#include <graphics.h>
#define DMAX 100
using namespace std;
ifstream fin("tabl.in");
ofstream fout("tabl.out");
struct vect {
    int lungime;
    int elem[DMAX];
};
struct matrix {
    int linii,coloane;
    float elem[DMAX][DMAX];
    int x,y;
};

void citire_tastatura_vect(vect &x);
//void citire_tastatura_matr(matrix &x);
void citire_fisier_vect(vect &x);
void citire_fisier_matr(matrix &x);
void afisare_ecran_vect(vect x);
void afisare_ecran_matr(matrix x);
//void afisare_fisier_vect(vect x);
//void afisare_fisier_matr(matrix x);
void adunare_vector(vect x, vect y, vect &z); //Andreea - facut
void adunare_matrice(matrix x, matrix y, matrix &z); //Andreea - facut
void inmultire_vector(vect x, vect y, vect &z); //Andreea - facut
void inmultire_matrice(matrix x, matrix y, matrix &z); //Andreea - facut
void putere_vector(vect x, int putere, vect &z); //Andreea - facut
void transpusa_matrice(matrix x, matrix &z); //Andreea - facut
int suma_elemente_vector(vect x); //Andreea - facut
void shiftare_dreapta_vector(vect x, vect &z, int nr_poz); //Andreea - facut
void shiftare_stanga_vector(vect x, vect &z, int nr_poz); //Andreea - facut
void inmultire_vector_scalar(vect x, vect &z, int scalar); //Andreea - facut
int suma_diag_principala(matrix x); //Andreea - facut
int suma_sub_diag_principala(matrix x); //Andreea - facut
int suma_deasupra_diag_principala(matrix x); //Andreea - facut
int calcul_det(int **matr, int n); //Andreea - facut
int **calcul_minor(int **matr, int lin, int col, int n); //Andreea - facut
int **calcul_inversa(int **matr, int n); //Andreea - facut
void scadere_vector(vect x, vect y, vect &z); //Albert - facut
void scadere_matrice(matrix x, matrix y, matrix &z); //Albert - facut
void inverseaza_linii(matrix &x, unsigned int i, unsigned int j); //Albert - facut
void determinant_matrice(matrix x, float &determinant); //Albert - facut
void afiseazaInmmultireCoeficient(float coeficient,int x,int y,int timeDelay);
void stergeInmmultireCoeficient(float coeficient,int x,int y,int timeDelay);
void determinant_matrice_grafica(matrix matrix1, float &determinant); //ALbert
void inmultire_scalar_matrice(matrix x, int scalar, matrix &y); //Albert - facut
void inmultire_scalar_matrice_grafica(matrix x, int scalar, matrix &y); //Albert
void impartire_matrice(matrix x, matrix y, matrix &rezultat); //Albert - facut
void matrice_identitate(matrix &x, bool esteVida); //Albert - facut
void inversare_matrice(matrix x, matrix &y); //Albert - facut
void inversare_matrice_grafica(matrix matrix1, matrix &matrix2); //Albert
void putere_matrice(matrix x, int putere, matrix &z); //Albert - facut
int produs_elemente_vector(vect x); //Albert - facut
int suma_diag_secundara(matrix x); //Albert - facut
int suma_sub_diag_secundara(matrix x); //Albert - facut

void bubbleSortCrescator(vect x, vect &z); //Andreea - facut (complexitate O(n^2) caz nefavorabil)
void bubbleSortDescrescator(vect x, vect &z); //Andreea - facut (complexitate O(n^2) caz nefavorabil)
void sortareInsertieCrescator(vect x, vect &z); //Andreea - facut (complexitate O(n^2) caz nefavorabil)
void sortareInsertieDescrescator(vect x, vect &z); //Andreea - facut (complexitate O(n^2) caz nefavorabil)
void sortareSelectieNaivaCrescator(vect x, vect &z); //Andreea - facut(complexitate O(n^2) in toate cazurile)
void sortareSelectieNaivaDescrescator(vect x, vect &z); //Andreea - facut(complexitate O(n^2) in toate cazurile)
void sortare_selectie_sistematica(vect x, vect &z);
void mergeSortCrescator(vect &x, int st, int dr); //Andreea - facut (complexitate O(n*log n))
void mergeArraysCrescator(vect &x, int st, int mijl, int dr); //Andreea - facut
void quickSort();
void sortare_numarare(vect x, vect &b); //Andreea - facut (complexitate O(k+n))

void borders_and_lines(int n, int m, int x, int y); //Andreea - facut
void afisare_matrice(matrix v, int x1, int y1, int color); //Andreea - facut
void inmultire_scalar(matrix v, matrix &z, int scalar);
void putNumber(int nr,int x,int y, int color, int time_delay); //Andreea - facut
void coloreazaLinieMatrice(int linie,matrix matriceAfisata,int culoare,int time_delay); //Albert - facut
void coloreazaColoanaMatrice(int coloana,matrix matriceAfisata,int culoare,int time_delay); //Albert - facut

void citire_tastatura_afisare_matrice(matrix &m1, int x, int y, int color); //Andreea - facut
void citire_fisier_afisare_matrice(matrix &m1, int x, int y, int color); //Andreea - facut
int main()
{
    initwindow(1000,1000);

    /*matrix m1,m2;
    m1.x=30; m1.y=30; int scalar;
    //citire_fisier_afisare_matrice(m1,m1.x,m1.y,WHITE);
    citire_tastatura_afisare_matrice(m1,m1.x,m1.y,WHITE);
    fin>>scalar;
    inmultire_scalar(m1,m2,scalar);

    getch();
    cleardevice();

    matrix m3,m4,m5;
    m3.x=30; m3.y=30;
    citire_fisier_afisare_matrice(m3,m3.x,m3.y,WHITE);
    m4.x=m3.x+50*m3.coloane+60; m4.y=30;
    citire_fisier_afisare_matrice(m4,m4.x,m4.y,WHITE);
    inmultire_matrice(m3,m4,m5);

    getch();
    cleardevice();*/

    matrix m6;
    m6.x=30; m6.y=30;
    citire_tastatura_afisare_matrice(m6,m6.x,m6.y,WHITE);
    float determinant;
    determinant_matrice_grafica(m6,determinant);

    getch();
   // cleardevice();

/*
    matrix m7,m8;
    m7.x=30; m7.y=30;
    citire_tastatura_afisare_matrice(m7,m7.x,m7.y,WHITE);
    m8.x=m7.x+50*m7.coloane+5; m8.y=30;
    inversare_matrice_grafica(m7,m8);
*/
    //getch();

    return 0;
}
void citire_fisier_afisare_matrice(matrix &m1, int x, int y, int color) {
    int w=50/2+y-10;
    int u=50/2+x;
    fin>>m1.linii>>m1.coloane;
    borders_and_lines(m1.linii,m1.coloane,x,y);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    for(int i=0;i<m1.linii;i++) {
        for(int j=0;j<m1.coloane;j++) {
            fin>>m1.elem[i][j];
            putNumber(m1.elem[i][j],u,w,color,50);
            u+=50;
        }
        u=50/2+x;
        w+=50;
    }
}
void citire_tastatura_afisare_matrice(matrix &m1, int x, int y, int color) {
    int w=50/2+y-10;
    int u=50/2+x;
    cin>>m1.linii>>m1.coloane;
    borders_and_lines(m1.linii,m1.coloane,x,y);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    for(int i=0;i<m1.linii;i++) {
        for(int j=0;j<m1.coloane;j++) {
            cin>>m1.elem[i][j];
            putNumber(m1.elem[i][j],u,w,color,200);
            u+=50;
        }
        u=50/2+x;
        w+=50;
    }
}

void afisare_ecran_matrice_grafica(matrix &m1, int color) {
    int w=50/2+m1.y-10;
    int u=50/2+m1.x;
    borders_and_lines(m1.linii,m1.coloane,m1.x,m1.y);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    for(int i=0;i<m1.linii;i++) {
        for(int j=0;j<m1.coloane;j++) {
            putNumber(m1.elem[i][j],u,w,color,200);
            u+=50;
        }
        u=50/2+m1.x;
        w+=50;
    }
}

void putNumber(int nr,int x,int y, int color, int time_delay) {
    setcolor(color);
    bgiout<<nr;
    delay(time_delay);
    if(nr<10) outstreamxy(x,y);
    else outstreamxy(x-11,y);
}

void putNumberInMatrix(){
}

void coloreazaLinieMatrice(int linie,matrix matriceDeColorat,int culoare,int time_delay){
    int i,j,u,w;
    int x1=matriceDeColorat.x,
        x2=x1+50,
        y1=matriceDeColorat.y,
        y2=y1+50;

    delay(time_delay);

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=50/2+y1-10;
    u=50/2+x1;

    w+=50*linie;

    for(i=0;i<matriceDeColorat.coloane;i++) {

        setcolor(culoare);
        bgiout<<matriceDeColorat.elem[linie][i];

        if(matriceDeColorat.elem[linie][i]<10) outstreamxy(u,w);
        else outstreamxy(u-11,w);

        u+=50;
    }
}

void coloreazaLinieIncompletaMatrice(int linie,int coloanaStart,int coloanaSfarsit,matrix matriceDeColorat,int culoare,int time_delay){
    int i,j,u,w;
    int x1=matriceDeColorat.x,
        x2=x1+50,
        y1=matriceDeColorat.y,
        y2=y1+50;

    delay(time_delay);

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=50/2+y1-10;
    u=50/2+x1;

    w+=50*linie;

    for(i=coloanaStart;i<coloanaSfarsit;i++) {

        setcolor(culoare);
        bgiout<<matriceDeColorat.elem[linie][i];

        if(matriceDeColorat.elem[linie][i]<10) outstreamxy(u,w);
        else outstreamxy(u-11,w);

        u+=50;
    }
}

void coloreazaColoanaMatrice(int coloana,matrix matriceDeColorat,int culoare,int time_delay){
    int i,j,u,w;
    int x1=matriceDeColorat.x,
        x2=x1+50,
        y1=matriceDeColorat.y,
        y2=y1+50;

    delay(time_delay);

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=50/2+y1-10;
    u=50/2+x1;

    u+=50*coloana;

    for(j=0;j<matriceDeColorat.linii;j++) {

        setcolor(culoare);
        bgiout<<matriceDeColorat.elem[j][coloana];

        if(matriceDeColorat.elem[j][coloana]<10) outstreamxy(u,w);
        else outstreamxy(u-11,w);

        w+=50;
    }
}

void coloreazaColoanaIncompletaMatrice(int coloana,int linieStart,int linieSfarsit,matrix matriceDeColorat,int culoare,int time_delay){
    int i,j,u,w;
    int x1=matriceDeColorat.x,
        x2=x1+50,
        y1=matriceDeColorat.y,
        y2=y1+50;

    delay(time_delay);

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=50/2+y1-10;
    u=50/2+x1;

    u+=50*coloana;
    w+=50*linieStart;

    for(j=linieStart;j<=linieSfarsit;j++) {

        setcolor(culoare);
        bgiout<<matriceDeColorat.elem[j][coloana];

        if(matriceDeColorat.elem[j][coloana]<10) outstreamxy(u,w);
        else outstreamxy(u-11,w);

        w+=50;
    }
}

void coloreazaDiagonalaPrincipalaMatrice(matrix &matriceDeColorat,int culoare,int timeDelay){

    int i,j,u,w;
    int x1=matriceDeColorat.x,
        x2=x1+50,
        y1=matriceDeColorat.y,
        y2=y1+50;

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=50/2+y1-10;
    u=50/2+x1;

    delay(timeDelay);

    for(i=0;i<matriceDeColorat.coloane;i++) {

        setcolor(culoare);
        bgiout<<matriceDeColorat.elem[i][i];

        if(matriceDeColorat.elem[i][i]<10) outstreamxy(u,w);
        else outstreamxy(u-11,w);

        u+=50;
        w+=50;
    }

}

void afisare_matrice(matrix matrix1, int x1, int y1,int color) {
    int i,j,u,w;
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=50/2+y1-10;
    u=50/2+x1;
    for(j=0;j<matrix1.linii;j++) {
        for(i=0;i<matrix1.coloane;i++) {
            putNumber(matrix1.elem[j][i],u,w,color,30);
            u+=50;
        }
        u=50/2+x1;
        w+=50;
    }
}


void inmultire_scalar_grafica(matrix matrix1, matrix &matrix2, int scalar) {
    bgiout<<"x ";
    outstreamxy(matrix1.coloane*50+matrix1.x+20,(matrix1.linii*50+matrix1.y)/2);
    int x_scalar=matrix1.coloane*50+matrix1.x+40;
    int y_scalar=(matrix1.linii*50+matrix1.y)/2;
    putNumber(scalar,x_scalar,y_scalar,WHITE,10);
    bgiout<<" = ";
    outstreamxy(x_scalar+20,y_scalar);

    matrix2.x=x_scalar+70;
    matrix2.y=matrix1.y;
    matrix2.linii=matrix1.linii; matrix2.coloane=matrix1.coloane;
    borders_and_lines(matrix2.linii,matrix2.coloane,matrix2.x,matrix2.y);

    int i,j,x_matrix1_center,y_matrix1_center,x_matrix2_center,y_matrix2_center;
    y_matrix1_center=50/2+matrix1.y-10;
    x_matrix1_center=50/2+matrix1.x;
    y_matrix2_center=50/2+matrix2.y-10;
    x_matrix2_center=50/2+matrix2.x;
    for(i=0;i<matrix1.linii;i++) {
        for(j=0;j<matrix1.coloane;j++) {
            putNumber
            (matrix1.elem[i][j],x_matrix1_center,y_matrix1_center,RED,450);
            putNumber(scalar,x_scalar,y_scalar,RED,500);
            matrix2.elem[i][j]=matrix1.elem[i][j]*scalar;
            putNumber(matrix2.elem[i][j],x_matrix2_center,y_matrix2_center,RED,450);
            putNumber(matrix1.elem[i][j],x_matrix1_center,y_matrix1_center,WHITE,450);
            putNumber(scalar,x_scalar,y_scalar,WHITE,0);
            putNumber(matrix2.elem[i][j],x_matrix2_center,y_matrix2_center,WHITE,0);
            x_matrix1_center+=50; x_matrix2_center+=50;
        }
        x_matrix1_center=50/2+matrix1.x; x_matrix2_center=50/2+matrix2.x;
        y_matrix1_center+=50; y_matrix2_center+=50;
    }
}
void borders_and_lines(int n, int m, int x, int y) {
    int i,j,z,t,spatiu_x,spatiu_y;
    spatiu_x=x; spatiu_y=y;
    z=m*50+spatiu_x; t=n*50+spatiu_y;
    setcolor(WHITE);
    rectangle(x,y,z,t);
    x+=50; z=x;
    for(i=0;i<m-1;i++) {
        line(x,y,z,t);
        x+=50; z+=50;
    }
    x=spatiu_y+50; z=x; t=m*50+spatiu_x;
    for(i=0;i<n-1;i++) {
        line(spatiu_x,x,t,z);
        x+=50; z+=50;
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
            swap(x.elem[i],x.elem[imax]);
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
            swap(x.elem[i],x.elem[imax]);
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
            if(x.elem[j]>x.elem[j+1]) swap(x.elem[j],x.elem[j+1]);
        }
    }
    for(i=0;i<x.lungime;i++) z.elem[i]=x.elem[i];
    z.lungime=x.lungime;
}
void bubbleSortDescrescator(vect x, vect &z) {
    int i,j;
    for(i=0;i<x.lungime-1;i++) {
        for(j=0;j<x.lungime-i-1;j++) {
            if(x.elem[j]<x.elem[j+1]) swap(x.elem[j],x.elem[j+1]);
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
    inmultire_matrice(x,x,z);
    if(putere>0) for(i=3;i<=putere;i++) inmultire_matrice(z,x,z);
    if(putere<0) {
        putere=-putere;
        inversare_matrice(x,x);
        inmultire_matrice(x,x,z);
        for(i=3;i<=putere;i++) inmultire_matrice(z,x,z);
    }
}

void matrice_identitate(matrix &x, bool esteVida) {
    unsigned int i;
    if(esteVida) for(i=0;i<x.linii;i++) x.elem[i][i]=1;
}
void impartire_matrice(matrix x, matrix y, matrix &rezultat) {
    matrix inversa;
    inversare_matrice(y,inversa);
    inmultire_matrice(x,inversa,rezultat);
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
void inmultire_scalar_matrice(matrix x, int scalar, matrix &y) {
    int i,j;
    for(i=0;i<x.linii;i++) for(j=0;j<x.coloane;j++) y.elem[i][j]=x.elem[i][j]*scalar;
    y.linii=x.linii;
    y.coloane=x.coloane;
}

void afiseazaInmultireCoeficient(float coeficient,int x,int y,int timeDelay){

    setcolor(GREEN);
    bgiout<<"x("<<coeficient<<")+";
    delay(timeDelay);
    outstreamxy(x,y);
    setcolor(WHITE);

}

void afiseazaInmultireSemn(unsigned int numarInversiuni,float determinant,int x,int y,int timeDelay){

    delay(timeDelay);

    bgiout<<"determinant=(-1) x"<<determinant;
    outstreamxy(x,y);

    setcolor(RED);
    bgiout<<numarInversiuni;
    outstreamxy(x+textwidth("determinant=(-1)"),y-10);
    setcolor(WHITE);
}

void inverseaza(unsigned int number,unsigned int &invers){
    unsigned int copie = number;
    invers = 0;
    while(copie){
        invers = invers*10 + copie%10;
        copie/=10;
    }
}

void nrCifre(unsigned int number,unsigned int &nrCaractere){

    if(number!=0){
        unsigned int copie = number;
        nrCaractere = 0;
        while(copie){
            copie/=10;
            nrCaractere++;
        }
    }
    else nrCaractere = 1;
}

void toString(unsigned int number,char convertedString[4]){
    unsigned int nrCaractere = 0;
    unsigned int invers = 0;

    nrCifre(number,nrCaractere);
    inverseaza(number,invers);


    unsigned int i;

    for(i=0;i<nrCaractere;i++){
        convertedString[i]=invers%10+'0';
        number/=10;
    }
}

void stergeInmultireCoeficient(float coeficient,int x,int y,int timeDelay){

    char coeficient_sir[4];
    toString(coeficient,coeficient_sir);

    setcolor(BLACK);
    delay(timeDelay);
    bar(x,y,x+textwidth("x(")+textwidth(coeficient_sir)+textwidth(")+"),y+textheight("("));
    setcolor(WHITE);

}

void stergeInmultireSemn(unsigned int numarInversiuni,float determinant,int x,int y,int timeDelay){
    char determinant_sir[4];
    toString(determinant,determinant_sir);

    delay(timeDelay);

    setcolor(BLACK);
    bar(x,y-10,x+textwidth("determinant=(-1) x")+textwidth(determinant_sir),y+textheight("("));
    setcolor(WHITE);
}

void aduna_linie_ori_coeficient_la_linie(int linieDeAdunat,float coeficient,int linieLaCareSeAduna,matrix &matrix1){
    int i,j,k;
    i=linieDeAdunat;
    j=linieLaCareSeAduna;

    coloreazaLinieMatrice(i,matrix1,GREEN,0);
    afiseazaInmultireCoeficient(coeficient,matrix1.x+50*matrix1.coloane+10,matrix1.y+50*i+13,450);
    coloreazaLinieMatrice(j,matrix1,RED,450);

    coloreazaLinieMatrice(i,matrix1,WHITE,0);
    stergeInmultireCoeficient(coeficient,matrix1.x+50*matrix1.coloane+10,matrix1.y+50*i+13,0);

    for(k=0;k<matrix1.coloane;k++)
        matrix1.elem[j][k] = coeficient*matrix1.elem[i][k] + matrix1.elem[j][k];

    coloreazaLinieMatrice(j,matrix1,RED,450);
    coloreazaLinieMatrice(j,matrix1,WHITE,0);

}

void afiseazaCalculareaCoeficientului(float deimpartit,float impartitor,int x,int y,int culoare,int timeDelay){
    float rezultat = deimpartit/impartitor;
    setcolor(culoare);
    bgiout<<deimpartit<<"/"<<impartitor<<"="<<rezultat;
    delay(timeDelay);
    outstreamxy(x,y);
}


void stergeCalculareaCoeficientului(float deimpartit,float impartitor,int x,int y,int culoareFundal,int timeDelay){
    float rezultat = deimpartit/impartitor;
    int inaltimeText,latimeText;
    setfillstyle(SOLID_FILL,culoareFundal);
    char deimpartit_text[4],impartitor_text[4],rezultat_text[4];

    toString(deimpartit,deimpartit_text);
    toString(impartitor,impartitor_text);
    toString(rezultat,rezultat_text);

    latimeText = textwidth(deimpartit_text)+textwidth("/")+textwidth(impartitor_text)+textwidth("=")+textwidth(rezultat_text);
    inaltimeText = textheight("/");
    bar(x,y,x+latimeText,y+inaltimeText);
    delay(timeDelay);
    outstreamxy(x,y);
}

void obtine_zero_pe_coloana_sub_linie_grafica(int coloana,int linie, matrix &matrix1){

    int i,j;
    float coeficient;
    i=coloana;
    j=linie;
    int x_calcul,y_calcul;

    for(j=i+1;j<matrix1.linii;j++) {

        coeficient = matrix1.elem[j][i]/matrix1.elem[i][i];

        putNumber(matrix1.elem[i][i],matrix1.x+25+50*i,matrix1.y+15+50*i,RED,0);
        putNumber(matrix1.elem[j][i],matrix1.x+25+50*i,matrix1.y+15+50*j,RED,0);

        x_calcul = matrix1.x+50*matrix1.coloane+30;
        y_calcul = matrix1.y+50*matrix1.linii/2;
        afiseazaCalculareaCoeficientului(matrix1.elem[j][i],matrix1.elem[i][i],x_calcul,y_calcul,RED,0);
        stergeCalculareaCoeficientului(matrix1.elem[j][i],matrix1.elem[i][i],x_calcul,y_calcul,BLACK,450);

        putNumber(matrix1.elem[i][i],matrix1.x+25+50*i,matrix1.y+15+50*i,WHITE,0);
        putNumber(matrix1.elem[j][i],matrix1.x+25+50*i,matrix1.y+15+50*j,WHITE,0);


        aduna_linie_ori_coeficient_la_linie(i,-coeficient,j,matrix1);
        }
}

void inverseaza_linii_grafica(matrix &matrix1, unsigned int i, unsigned int j) {

    coloreazaLinieMatrice(i,matrix1,RED,0);
    coloreazaLinieMatrice(j,matrix1,GREEN,450);

    for(int k=0;k<matrix1.linii;k++) swap(matrix1.elem[i][k],matrix1.elem[j][k]);

    coloreazaLinieMatrice(i,matrix1,GREEN,0);
    coloreazaLinieMatrice(j,matrix1,RED,450);

    coloreazaLinieMatrice(i,matrix1,WHITE,0);
    coloreazaLinieMatrice(j,matrix1,WHITE,0);
}

void cautaPozitieLinieElemNenulInColoana_grafica(matrix matrix1,int coloana,int &pozitie){

    int j,x_matrix1_center,y_matrix1_center;

    y_matrix1_center=50/2+matrix1.y-10;
    x_matrix1_center=50/2+matrix1.x;

    y_matrix1_center+=coloana*50;
    x_matrix1_center+=coloana*50;

        for(j=coloana;j<matrix1.linii;j++){

          putNumber(matrix1.elem[j][coloana],x_matrix1_center,y_matrix1_center,RED,0);
          putNumber(matrix1.elem[j][coloana],x_matrix1_center,y_matrix1_center,WHITE,450);

          if(matrix1.elem[j][coloana]!=0) break;

          y_matrix1_center += 50;
        }

    pozitie = j;
}

void determinant_matrice_grafica(matrix matrix1, float &determinant) {
    int i,j,k;
    unsigned int nrInversari=0;
    int x_determinant,y_determinant,x_nrInversari,y_nrInversari;
    bool matriceSingulara = false;

    x_determinant = matrix1.x+50*matrix1.coloane+60;
    y_determinant = matrix1.y+50*matrix1.linii/2;

    x_nrInversari = matrix1.x;
    y_nrInversari = matrix1.y+50*matrix1.linii+20;


    for(i=0;i<matrix1.coloane-1;i++){

        coloreazaColoanaMatrice(i,matrix1,RED,0);
        coloreazaColoanaMatrice(i,matrix1,WHITE,450);

        cautaPozitieLinieElemNenulInColoana_grafica(matrix1,i,j);

        if(j==matrix1.linii){
            determinant=0;
            matriceSingulara = true;
            setcolor(WHITE);
            bgiout<<"determinant="<<determinant;
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

    if(!matriceSingulara){

        determinant = 1;
        for(j=0;j<matrix1.linii;j++) determinant*=matrix1.elem[j][j];
        coloreazaDiagonalaPrincipalaMatrice(matrix1,RED,0);
//time
        setcolor(WHITE);
        bgiout<<"determinant="<<determinant;
        outstreamxy(x_determinant,y_determinant);
        coloreazaDiagonalaPrincipalaMatrice(matrix1,WHITE,450);

        afiseazaInmultireSemn(nrInversari,determinant,x_determinant,y_determinant,0);

        determinant*=(nrInversari%2==0)?1:-1;
        stergeInmultireSemn(nrInversari,determinant,x_determinant,y_determinant,1000);

        bgiout<<"determinant="<<determinant;
        outstreamxy(x_determinant,y_determinant);
    }
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
                inverseaza_linii(x,i,j);
                nrInversari++;
            }
            for(j=i+1;j<x.linii;j++) {
                lambda=x.elem[j][i]/x.elem[i][i];
                for(k=0;k<x.coloane;k++) x.elem[j][k]=x.elem[j][k]-lambda*x.elem[i][k];
            }
       }
    }
    determinant=(nrInversari%2==0)?1:-1;
    for(j=0;j<x.linii;j++) determinant*=x.elem[j][j];
}

void aduna_linie_ori_coeficient_la_linie_douaMatrici_grafica(int linieDeAdunat,float coeficient,int linieLaCareSeAduna,matrix &matrix1,matrix &matrix2){

        int i,j,k;
        i=linieDeAdunat;
        j=linieLaCareSeAduna;

        coloreazaLinieMatrice(i,matrix1,GREEN,0);
        coloreazaLinieMatrice(i,matrix2,GREEN,0);
        afiseazaInmultireCoeficient(coeficient,matrix2.x+50*matrix2.coloane+10,matrix1.y+50*i+13,450);
        coloreazaLinieMatrice(j,matrix1,RED,450);
        coloreazaLinieMatrice(j,matrix2,RED,0);

        coloreazaLinieMatrice(i,matrix1,WHITE,0);
        coloreazaLinieMatrice(i,matrix2,WHITE,0);
        stergeInmultireCoeficient(coeficient,matrix2.x+50*matrix2.coloane+10,matrix1.y+50*i+13,450);

        for(k=0;k<matrix1.coloane;k++) {
            matrix1.elem[j][k]=coeficient*matrix1.elem[i][k]+matrix1.elem[j][k];
            matrix2.elem[j][k]=coeficient*matrix2.elem[i][k]+matrix2.elem[j][k];
        }
        coloreazaLinieMatrice(j,matrix1,RED,450);
        coloreazaLinieMatrice(j,matrix2,RED,0);
        coloreazaLinieMatrice(j,matrix1,WHITE,0);
        coloreazaLinieMatrice(j,matrix2,WHITE,0);
}

void obtine_zero_pe_coloana_deasupra_linie_douaMatrici_grafica(int coloana,int linie, matrix &matrix1,matrix &matrix2){
        int i,j;
        int x_calcul,y_calcul;
        float coeficient;
        i=coloana;
        j=linie;

            for(j=i-1;j>=0;j--) {
                coeficient = matrix1.elem[j][i];
                matrix1.elem[j][i] = 0;

                putNumber(matrix1.elem[i][i],matrix1.x+25+50*i,matrix1.y+15+50*i,RED,0);
                putNumber(matrix1.elem[j][i],matrix1.x+25+50*i,matrix1.y+15+50*j,RED,0);

                x_calcul = matrix2.x+50*matrix2.coloane+30;
                y_calcul = matrix1.y+50*matrix1.linii/2;
                afiseazaCalculareaCoeficientului(matrix1.elem[j][i],matrix1.elem[i][i],x_calcul,y_calcul,RED,0);
                stergeCalculareaCoeficientului(matrix1.elem[j][i],matrix1.elem[i][i],x_calcul,y_calcul,BLACK,450);

                putNumber(matrix1.elem[i][i],matrix1.x+25+50*i,matrix1.y+15+50*i,WHITE,0);
                putNumber(matrix1.elem[j][i],matrix1.x+25+50*i,matrix1.y+15+50*j,WHITE,0);

                aduna_linie_ori_coeficient_la_linie(i,-coeficient,j,matrix2);

            }
}

void obtine_zero_deasupra_diagonalei_douaMatrici_grafica(int linie,matrix &matrix1,matrix &matrix2){
    int i=linie;
        for(i=matrix1.coloane-1;i>0;i--) {

            coloreazaColoanaIncompletaMatrice(i,i,0,matrix1,RED,0);
            coloreazaColoanaIncompletaMatrice(i,i,0,matrix1,WHITE,450);

            obtine_zero_pe_coloana_deasupra_linie_douaMatrici_grafica(i,i,matrix1,matrix2);
        }
}

void obtine_zero_pe_coloana_sub_linie_douaMatrici_grafica(int coloana,int linie,matrix &matrix1,matrix &matrix2,bool &inversabila){

        int i,j,k;
        int x_calcul,y_calcul;
        float coeficient;
        bool numaiZerouri=false;
        j=linie;
        i=coloana;

        for(j=i+1;j<matrix1.linii && inversabila;j++) {

            coeficient=matrix1.elem[j][i]/matrix1.elem[i][i];

            putNumber(matrix1.elem[i][i],matrix1.x+25+50*i,matrix1.y+15+50*i,RED,0);
            putNumber(matrix1.elem[j][i],matrix1.x+25+50*i,matrix1.y+15+50*j,RED,0);

            x_calcul = matrix2.x+50*matrix2.coloane+50;
            y_calcul = matrix1.y+50*matrix1.linii/2;
            afiseazaCalculareaCoeficientului(matrix1.elem[j][i],matrix1.elem[i][i],x_calcul,y_calcul,RED,450);getch();
            stergeCalculareaCoeficientului(matrix1.elem[j][i],matrix1.elem[i][i],x_calcul,y_calcul,BLACK,0);

            putNumber(matrix1.elem[i][i],matrix1.x+25+50*i,matrix1.y+15+50*i,WHITE,0);
            putNumber(matrix1.elem[j][i],matrix1.x+25+50*i,matrix1.y+15+50*j,WHITE,0);

            aduna_linie_ori_coeficient_la_linie_douaMatrici_grafica(i,-coeficient,j,matrix1,matrix2);

            numaiZerouri=true;
            for(k=0;k<matrix1.coloane;k++)
                if(matrix1.elem[j][k]!=0) numaiZerouri=false;

            if(numaiZerouri) {
                cout<<"Matricea nu este inversabila";
                inversabila=false;
            }
        }
}


void imparte_linie_la_scalar_douaMatrici(int linie,int scalar,matrix &matrix1,matrix &matrix2){
    int i,j;
    i=linie;

    coloreazaLinieMatrice(i,matrix1,RED,450);
    coloreazaLinieMatrice(i,matrix2,RED,0);

    for(j=0;j<matrix1.coloane;j++){
        matrix1.elem[i][j]/=scalar;
        matrix2.elem[i][j]/=scalar;
    }

    coloreazaLinieMatrice(i,matrix1,RED,450);
    coloreazaLinieMatrice(i,matrix2,RED,0);

    coloreazaLinieMatrice(i,matrix1,WHITE,450);
    coloreazaLinieMatrice(i,matrix2,WHITE,0);
}

void inverseaza_linii(matrix &x, unsigned int i, unsigned int j){
    int k;
    for(k=0;k<x.linii;k++)
        swap(x.elem[i][k],x.elem[j][k]);
};

void inverseaza_linii_douaMatrici_grafica(matrix &matrix1, matrix &matrix2, unsigned int i, unsigned int j) {

    coloreazaLinieMatrice(i,matrix1,RED,0);
    coloreazaLinieMatrice(i,matrix2,RED,0);
    coloreazaLinieMatrice(j,matrix1,GREEN,0);
    coloreazaLinieMatrice(j,matrix2,GREEN,0);

    for(int k=0;k<matrix1.linii;k++) swap(matrix1.elem[i][k],matrix1.elem[j][k]);
    for(int k=0;k<matrix2.linii;k++) swap(matrix2.elem[i][k],matrix2.elem[j][k]);

    coloreazaLinieMatrice(i,matrix1,GREEN,450);
    coloreazaLinieMatrice(i,matrix2,GREEN,0);
    coloreazaLinieMatrice(j,matrix1,RED,450);
    coloreazaLinieMatrice(j,matrix2,RED,0);

    coloreazaLinieMatrice(i,matrix1,WHITE,0);
    coloreazaLinieMatrice(i,matrix2,WHITE,0);
    coloreazaLinieMatrice(j,matrix1,WHITE,0);
    coloreazaLinieMatrice(j,matrix2,WHITE,0);
}

void inversare_matrice_grafica(matrix matrix1, matrix &matrix2) {

    matrix inv;
    inv.linii=matrix1.linii;
    inv.coloane=matrix1.linii;
    bool vida=true;
    matrice_identitate(inv,vida);

    inv.x = matrix1.x+50*matrix1.coloane+5;
    inv.y=30;
    afisare_ecran_matrice_grafica(inv,WHITE);

    int i,j;
    float lambda=0;
    bool numaiZerouri=false;
    bool inversabila=true;
    unsigned int nrInversari=0;
    float elemNenul;

    for(i=0;i<matrix1.coloane && inversabila;i++) {

        coloreazaColoanaMatrice(i,matrix1,RED,450);
        coloreazaColoanaMatrice(i,matrix2,RED,0);
        coloreazaColoanaMatrice(i,matrix1,WHITE,450);
        coloreazaColoanaMatrice(i,matrix2,WHITE,0);

        cautaPozitieLinieElemNenulInColoana_grafica(matrix1,i,j);

        if(j==matrix1.linii) {
            cout<<"Matricea nu este inversabila";
            inversabila=false;
        }
        else {
            if(j!=i) {
                inverseaza_linii_douaMatrici_grafica(matrix1,inv,i,j);
                getch();
            }
            elemNenul=matrix1.elem[i][i];

            //putNumber(elemNenul,matrix1.x+25+i*50,matrix1.y+13+i*50,RED,0);
            getch();
            imparte_linie_la_scalar_douaMatrici(i,elemNenul,matrix1,inv);

            cout<<"sure";
            getch();

            coloreazaColoanaIncompletaMatrice(i,j,matrix1.linii-1,matrix1,RED,0);
            coloreazaColoanaIncompletaMatrice(i,j,matrix1.linii-1,matrix1,WHITE,450);

            getch();
            cout<<"unknown"<<endl;

            obtine_zero_pe_coloana_sub_linie_douaMatrici_grafica(i,i,matrix1,inv,inversabila);
            getch();

        }
    }
    if(inversabila) {
        obtine_zero_pe_coloana_deasupra_linie_douaMatrici_grafica(i,i,matrix1,inv);
        matrix2=inv;
   }
}

void inversare_matrice(matrix matrix1, matrix &matrix2) {
    matrix inv;
    inv.linii=matrix1.linii;
    inv.coloane=matrix1.linii;
    bool vida=true;
    matrice_identitate(inv,vida);
    int i,j,k;
    float lambda=0;
    bool numaiZerouri=false;
    bool inversabila=true;
    unsigned int nrInversari=0;
    float elemNenul;
    for(i=0;i<matrix1.coloane && inversabila;i++) {
        for(j=i;j<matrix1.linii;j++) if(matrix1.elem[j][i]!=0) break;
        if(j==matrix1.linii) {
            cout<<"Matricea nu este inversabila";
            inversabila=false;
        }
        else {
            if(j!=i) {
                inverseaza_linii(matrix1,i,j);
                inverseaza_linii(inv,i,j);
                nrInversari++;
            }
            elemNenul=matrix1.elem[i][i];
            for(j=0;j<matrix1.coloane;j++) {
                matrix1.elem[i][j]/=elemNenul;
                inv.elem[i][j]/=elemNenul;
            }
            for(j=i+1;j<matrix1.linii && inversabila;j++) {
                lambda=matrix1.elem[j][i]/matrix1.elem[i][i];
                numaiZerouri=true;
                for(k=0;k<matrix1.coloane;k++) {
                    matrix1.elem[j][k]=matrix1.elem[j][k]-lambda*matrix1.elem[i][k];
                    inv.elem[j][k]=inv.elem[j][k]-lambda*inv.elem[i][k];
                    if(matrix1.elem[j][k]!=0) numaiZerouri=false;
                }
                if(numaiZerouri) {
                    cout<<"Matricea nu este inversabila";
                    inversabila=false;
                }
            }
        }
    }
    if(inversabila) {
        for(i=matrix1.coloane-1;i>0;i--) {
            for(j=i-1;j>=0;j--) {
                lambda=matrix1.elem[j][i];
                matrix1.elem[j][i]=0;
                for(k=0;k<inv.coloane;k++) inv.elem[j][k]=inv.elem[j][k]-lambda*inv.elem[i][k];
            }
        }
        matrix2=inv;
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
void shiftare_dreapta_vector(vect x,vect &z,int nr_poz) {
    int i,k=0;
    for(i=x.lungime-nr_poz;i<x.lungime;i++) z.elem[k++]=x.elem[i];
    for(i=nr_poz;i<x.lungime;i++) z.elem[i]=x.elem[i-nr_poz];
    z.lungime=x.lungime;
}
int suma_elemente_vector(vect x) {
    int s=0,i;
    for(i=0;i<x.lungime;i++) s+=x.elem[i];
    return s;
}
void inmultire_vector(vect x,vect y,vect &z) {
    int i;
    for(i=0;i<x.lungime && i<y.lungime;i++) {
        z.elem[i]=x.elem[i]*y.elem[i];
    }
    z.lungime=x.lungime;
    for(;i<x.lungime;i++) {
        z.elem[i]=x.elem[i];
        z.lungime=x.lungime;
    }
    for(;i<y.lungime;i++) {
        z.elem[i]=y.elem[i];
        z.lungime=y.lungime;
    }
}
void transpusa_matrice(matrix x,matrix &z) {
    int i,j;
    for(i=0;i<x.linii;i++) {
        for(j=0;j<x.coloane;j++) z.elem[j][i]=x.elem[i][j];
    }
    z.linii=x.coloane;
    z.coloane=x.linii;
}
void putere_vector(vect x, int putere, vect &z) {
    int i;
    for(i=0;i<x.lungime;i++) {
        z.elem[i]=pow(x.elem[i],putere);
    }
    z.lungime=x.lungime;
}

void inmultire_matrice(matrix x, matrix y, matrix &z) { //nr de linii al primei matrice trebuie sa fie egal cu nr de coloane al celei de-a doua matrice
    int i,j,k;
    if(x.linii!=y.coloane) cout<<"Imposibil.";
    else {
        for(i=0;i<x.linii;i++) for(j=0;j<y.coloane;j++) z.elem[i][j]=0;
        for(i=0;i<x.linii;i++) {
            for(j=0;j<y.coloane;j++) {
                for(k=0;k<x.coloane;k++) z.elem[i][j]+=x.elem[i][k]*y.elem[k][j];
            }
        }
        z.linii=x.linii;
        z.coloane=y.coloane;
    }
}

void inmultire_matrice_grafica(matrix matrix1, matrix matrix2, matrix &matrix3) { //nr de linii al primei matrice trebuie sa fie egal cu nr de coloane al celei de-a doua matrice

    bgiout<<"x ";
    outstreamxy(matrix1.coloane*50+matrix1.x+20,(matrix1.linii*50+matrix1.y)/2);

    bgiout<<" = ";
    int x_egal = matrix2.x+matrix2.coloane*50+20;
    outstreamxy(x_egal,(matrix1.linii*50+matrix1.y)/2);

    matrix3.x=x_egal+50;
    matrix3.y=matrix2.y;
    matrix3.linii=matrix1.linii; matrix3.coloane=matrix2.coloane;
    borders_and_lines(matrix3.linii,matrix3.coloane,matrix3.x,matrix3.y);

    int i,j,k,x_matrix3_center,y_matrix3_center;

    y_matrix3_center=50/2+matrix3.y-10;
    x_matrix3_center=50/2+matrix3.x;

    if(matrix1.linii!=matrix2.coloane) cout<<"Imposibil.";
    else {
        for(i=0;i<matrix1.linii;i++) for(j=0;j<matrix2.coloane;j++) matrix3.elem[i][j]=0;

        for(i=0;i<matrix1.linii;i++) {
            for(j=0;j<matrix2.coloane;j++) {

                for(k=0;k<matrix1.coloane;k++)
                    matrix3.elem[i][j]+=matrix1.elem[i][k]*matrix2.elem[k][j];

                coloreazaLinieMatrice(i,matrix1,RED,450);
                coloreazaColoanaMatrice(j,matrix2,RED,500);
                putNumber(matrix3.elem[i][j],x_matrix3_center,y_matrix3_center,RED,450);

                putNumber(matrix3.elem[i][j],x_matrix3_center,y_matrix3_center,WHITE,450);
                coloreazaColoanaMatrice(j,matrix2,WHITE,0);
                coloreazaLinieMatrice(i,matrix1,WHITE,0);

                x_matrix3_center+=50;
            }
            x_matrix3_center=50/2+matrix3.x;
            y_matrix3_center+=50;
        }
        matrix3.linii=matrix1.linii;
        matrix3.coloane=matrix2.coloane;
    }
}

/*void adunare_matrice_grafica(matrix matrix1, matrix matrix2, matrix &matrix3) { //nr de linii al primei matrice trebuie sa fie egal cu nr de coloane al celei de-a doua matrice

    bgiout<<"+ ";
    outstreamxy(matrix1.coloane*50+matrix1.x+20,(matrix1.linii*50+matrix1.y)/2);

    bgiout<<" = ";
    int x_egal = matrix2.x+matrix2.coloane*50+20;
    outstreamxy(x_egal,(matrix1.linii*50+matrix1.y)/2);

    matrix3.x=x_egal+50;
    matrix3.y=matrix2.y;
    matrix3.linii=matrix1.linii; matrix3.coloane=matrix2.coloane;
    borders_and_lines(matrix3.linii,matrix3.coloane,matrix3.x,matrix3.y);

    int i,j,k,x_matrix3_center,y_matrix3_center;

    y_matrix3_center=50/2+matrix3.y-10;
    x_matrix3_center=50/2+matrix3.x;

    if(matrix1.linii!=matrix2.coloane) cout<<"Imposibil.";
    else {
        for(i=0;i<matrix1.linii;i++) for(j=0;j<matrix2.coloane;j++) matrix3.elem[i][j]=0;

        for(i=0;i<matrix1.linii;i++) {
            for(j=0;j<matrix2.coloane;j++) {

                matrix3.elem[i][j] = matrix1.elem[i][j] + matrix2.elem[i][j];
                putNumber(matrix3.elem[i][j],x_matrix3_center,y_matrix3_center,RED,450);
                putNumber(matrix3.elem[i][j],x_matrix3_center,y_matrix3_center,WHITE,450);

                x_matrix3_center+=50;
            }
            x_matrix3_center=50/2+matrix3.x;
            y_matrix3_center+=50;
        }
        matrix3.linii=matrix1.linii;
        matrix3.coloane=matrix2.coloane;
    }
}*/

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
