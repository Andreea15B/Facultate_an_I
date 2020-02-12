#include <iostream>
#include <graphics.h>
#include <fstream>
using namespace std;
ifstream fin("gr.in");
struct matrix{
    int col,lin;
    int elem[20][20];
    int x,y;
};
void borders_and_lines(int n, int m, int x, int y);
void afisare_cifre(matrix v, int x1, int y1);
void inmultire(matrix v, matrix &z, int scalar, int x_scalar, int y_scalar);
void colorNumber(int nr,int x,int y, int color, int time_delay);
int main()
{
    initwindow(1000,1000);

    int scalar,i,j;
    matrix matrix1,matrix2;
    matrix1.x=20; matrix1.y=30;
    fin>>matrix1.lin>>matrix1.col;
    borders_and_lines(matrix1.lin,matrix1.col,matrix1.x,matrix1.y);

    for(i=0;i<matrix1.lin;i++) for(j=0;j<matrix1.col;j++) fin>>matrix1.elem[i][j];
    afisare_cifre(matrix1,matrix1.x,matrix1.y);

    fin>>scalar;
    bgiout<<"x ";
    outstreamxy(matrix1.col*50+matrix1.x+20,(matrix1.lin*50+matrix1.y)/2);
    int x_scalar=matrix1.col*50+matrix1.x+40;
    int y_scalar=(matrix1.lin*50+matrix1.y)/2;
    colorNumber(scalar,x_scalar,y_scalar,WHITE,10);
    bgiout<<" = ";
    outstreamxy(x_scalar+20,y_scalar);

    matrix2.x=x_scalar+70;
    matrix2.y=matrix1.y;
    matrix2.lin=matrix1.lin; matrix2.col=matrix1.col;
    borders_and_lines(matrix2.lin,matrix2.col,matrix2.x,matrix2.y);

    inmultire(matrix1,matrix2,scalar,x_scalar,y_scalar);

    getch();
    return 0;
}
void colorNumber(int nr,int x,int y, int color, int time_delay) {
    setcolor(color);
    bgiout<<nr;
    delay(time_delay);
    if(nr<10) outstreamxy(x,y);
    else outstreamxy(x-11,y);
}
void afisare_cifre(matrix matrix1, int x1, int y1) {
    int i,j,u,w;
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
    w=50/2+y1-10;
    u=50/2+x1;
    for(j=0;j<matrix1.lin;j++) {
        for(i=0;i<matrix1.col;i++) {
            colorNumber(matrix1.elem[j][i],u,w,WHITE,10);
            u+=50;
        }
        u=50/2+x1;
        w+=50;
    }
}

void inmultire(matrix matrix1, matrix &matrix2, int scalar, int x_scalar, int y_scalar) {
    int i,j,x_matrix1_center,y_matrix1_center,x_matrix2_center,y_matrix2_center;
    y_matrix1_center=50/2+matrix1.y-10;
    x_matrix1_center=50/2+matrix1.x;
    y_matrix2_center=50/2+matrix2.y-10;
    x_matrix2_center=50/2+matrix2.x;
    for(i=0;i<matrix1.lin;i++) {
        for(j=0;j<matrix1.col;j++) {
            colorNumber(matrix1.elem[i][j],x_matrix1_center,y_matrix1_center,RED,450);
            colorNumber(scalar,x_scalar,y_scalar,RED,500);
            matrix2.elem[i][j]=matrix1.elem[i][j]*scalar;
            colorNumber(matrix2.elem[i][j],x_matrix2_center,y_matrix2_center,RED,450);
            colorNumber(matrix1.elem[i][j],x_matrix1_center,y_matrix1_center,WHITE,450);
            colorNumber(scalar,x_scalar,y_scalar,WHITE,0);
            colorNumber(matrix2.elem[i][j],x_matrix2_center,y_matrix2_center,WHITE,0);
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
