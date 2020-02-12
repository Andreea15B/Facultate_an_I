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
//void afisare_ecran_matr(matrix x);
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
void inmultire_scalar_matrice(matrix x, int scalar, matrix &y); //Albert - facut
void impartire_matrice(matrix x, matrix y, matrix &rezultat); //Albert - facut
void matrice_identitate(matrix &x, bool esteVida); //Albert - facut
void inversare_matrice(matrix x, matrix &y); //Albert - facut
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
    matrix m1,m2;
    m1.x=30; m1.y=30; int scalar;
    citire_fisier_afisare_matrice(m1,m1.x,m1.y,WHITE);
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
    return 0;
}
void citire_fisier_afisare_matrice(matrix &m1, int x, int y, int color) {
    int w=50/2+y-10;
    int u=50/2+x;
    fin>>m1.linii>>m1.coloane; cout<<m1.linii<<' '<<m1.coloane<<endl;
    borders_and_lines(m1.linii,m1.coloane,x,y);
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    for(int i=0;i<m1.linii;i++) {
        for(int j=0;j<m1.coloane;j++) {
            fin>>m1.elem[i][j]; cout<<m1.elem[i][j];
            putNumber(m1.elem[i][j],u,w,color,50);
            u+=50;
        }
        u=50/2+x;
        w+=50; cout<<endl;
    } cout<<endl;
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
void putNumber(int nr,int x,int y, int color, int time_delay) {
    setcolor(color);
    bgiout<<nr;
    delay(time_delay);
    if(nr<10) outstreamxy(x,y);
    else outstreamxy(x-11,y);
}

void coloreazaLinieMatrice(int linie,matrix matriceDeColorat,int culoare,int time_delay){
    int i,j,u,w;
    int x1=matriceDeColorat.x,
        x2=x1+50,
        y1=matriceDeColorat.y,
        y2=y1+50;

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=50/2+y1-10;
    u=50/2+x1;

    w+=50*linie;

    for(i=0;i<matriceDeColorat.linii;i++) {

        setcolor(culoare);
        bgiout<<matriceDeColorat.elem[linie][i];

        if(matriceDeColorat.elem[linie][i]<10) outstreamxy(u,w);
        else outstreamxy(u-11,w);

        u+=50;
    }
    delay(time_delay);
}

void coloreazaColoanaMatrice(int coloana,matrix matriceDeColorat,int culoare,int time_delay){
    int i,j,u,w;
    int x1=matriceDeColorat.x,
        x2=x1+50,
        y1=matriceDeColorat.y,
        y2=y1+50;

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
    delay(time_delay);
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
void inmultire_scalar(matrix matrix1, matrix &matrix2, int scalar) {
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
void inversare_matrice(matrix x, matrix &y) {
    matrix inv;
    inv.linii=x.linii;
    inv.coloane=x.linii;
    bool vida=true;
    matrice_identitate(inv,vida);
    int i,j,k;
    float lambda=0;
    bool numaiZerouri=false;
    bool inversabila=true;
    unsigned int nrInversari=0;
    float elemNenul;
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
void inverseaza_linii(matrix &x, unsigned int i, unsigned int j) {
    for(int k=0;k<x.linii;k++) swap(x.elem[i][k],x.elem[j][k]);
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
void inmultire_matrice(matrix matrix1, matrix matrix2, matrix &matrix3) { //nr de linii al primei matrice trebuie sa fie egal cu nr de coloane al celei de-a doua matrice

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

                for(k=0;k<matrix1.coloane;k++) matrix3.elem[i][j]+=matrix1.elem[i][k]*matrix2.elem[k][j];
                cout<<matrix3.elem[i][j];

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
