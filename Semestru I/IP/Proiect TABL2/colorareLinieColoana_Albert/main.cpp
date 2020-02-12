#include <iostream>
#include <graphics.h>
using namespace std;
#define DMAX 100
struct vect {
    int v[DMAX];
    int lungime;
};
struct matrix {
    float m[DMAX][DMAX];
    unsigned int linii,coloane;
};
struct punct{
    unsigned int x;
    unsigned int y;
};
struct matriceAfisata{
    matrix *dateMatrice;
    punct spatiuTabel;
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
void afisareCifreMatrice(matrix matriceDeAfisat,punct spatiuTabel){
    int i,j,u,w;
    int x1=spatiuTabel.x,
        x2=x1+50,
        y1=spatiuTabel.y,
        y2=y1+50;
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=50/2+y1-10;
    u=50/2+x1;
    for(j=0;j<matriceDeAfisat.linii;j++) {
        for(i=0;i<matriceDeAfisat.coloane;i++) {
            setcolor(WHITE);
            bgiout<<matriceDeAfisat.m[j][i];
            delay(100);
            if(matriceDeAfisat.m[j][i]<10) outstreamxy(u,w);
            else outstreamxy(u-11,w);
            u+=50;
        }
        u=50/2+x1;
        w+=50;
    }
}
void borduriSiLinii(unsigned int n, unsigned int m, punct spatiuTabel){
    int i,j,x,y,z,t;
    x=spatiuTabel.x; y=spatiuTabel.y;
    z=m*50+spatiuTabel.x; t=n*50+spatiuTabel.y;
    setcolor(WHITE);
    rectangle(x,y,z,t);
    x+=50; z=x;
    for(i=0;i<m-1;i++) {
        line(x,y,z,t);
        x+=50; z+=50;
    }
    x=spatiuTabel.y+50; z=x; t=m*50+spatiuTabel.x;
    for(i=0;i<n-1;i++) {
        line(spatiuTabel.x,x,t,z);
        x+=50; z+=50;
    }
}
void afisare_ecran_matrice(matrix *x,punct spatiuTabel,matriceAfisata &xAfisata) {
    afisareCifreMatrice(*x,spatiuTabel);
    borduriSiLinii(x->linii,x->coloane,spatiuTabel);
    xAfisata.spatiuTabel = spatiuTabel;
    xAfisata.dateMatrice = x;
};
void coloreazaLinieMatrice(int linie,matriceAfisata matriceDePeEcran,int culoare){
    int i,j,u,w;
    int x1=matriceDePeEcran.spatiuTabel.x,
        x2=x1+50,
        y1=matriceDePeEcran.spatiuTabel.y,
        y2=y1+50;
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=50/2+y1-10;
    u=50/2+x1;
    w+=50*linie;
    for(i=0;i<matriceDePeEcran.dateMatrice->coloane;i++) {
        setcolor(culoare);
        bgiout<<matriceDePeEcran.dateMatrice->m[linie][i];
        if(matriceDePeEcran.dateMatrice->m[linie][i]<10) outstreamxy(u,w);
        else outstreamxy(u-11,w);
        u+=50;
    }
}
void coloreazaColoanaMatrice(int coloana,matriceAfisata matriceDePeEcran,int culoare){
    int i,j,u,w;
    int x1=matriceDePeEcran.spatiuTabel.x,
        x2=x1+50,
        y1=matriceDePeEcran.spatiuTabel.y,
        y2=y1+50;

    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=50/2+y1-10;
    u=50/2+x1;

    u+=50*coloana;

    for(j=0;j<matriceDePeEcran.dateMatrice->linii;j++) {

        setcolor(culoare);
        bgiout<<matriceDePeEcran.dateMatrice->m[j][coloana];

        if(matriceDePeEcran.dateMatrice->m[j][coloana]<10) outstreamxy(u,w);
        else outstreamxy(u-11,w);

        w+=50;
    }
}

int main()
{
    matrix x;

    citire_tastatura_matrice(x);

    initwindow(1000,1000);

    punct spatiuTabel;

    //spatiuTabel = {10,10};
    spatiuTabel.x = 10;
    spatiuTabel.y = 10;

    matriceAfisata xAfisata;
    afisare_ecran_matrice(&x,spatiuTabel,xAfisata);

    getch();

    coloreazaLinieMatrice(0,xAfisata,GREEN);

    getch();

    coloreazaColoanaMatrice(1,xAfisata,BLUE);

    getch();

    return 0;
}
