#include <iostream>
#include <graphics.h>
#include <fstream>
using namespace std;
ifstream fin("gr.in");
int main()
{
    initwindow(600,600);
    int n,m,i,j;
    int x,y,z,t;
    fin>>n>>m;
    x=y=10; z=m*50+x; t=n*50+x;
    setcolor(WHITE);
    rectangle(x,y,z,t);
    x=60; z=x;
    for(i=0;i<m-1;i++) {
        line(x,y,z,t);
        x+=50; z+=50;
    }
    x=60; z=x; t=m*50+10;
    for(i=0;i<n-1;i++) {
        line(y,x,t,z);
        x+=50; z+=50;
    }
    int v[20],x1=10,x2=60,y1=10,y2=60;
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
    int u,w;
    u=(x2-x1)/2;
    w=(y2-y1)/2;
    for(j=0;j<n;j++) {
        for(i=0;i<m;i++) {
            fin>>v[i];
            if(v[i]<10) {
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
                setcolor(RED);
                bgiout<<v[i];
                delay(200);
                outstreamxy(u,w);
                setcolor(15);
                bgiout<<v[i];
                delay(1000);
                outstreamxy(u,w);
            }
            else if(v[i]>9 && v[i]<100) {
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
                bgiout<<v[i];
                outstreamxy(u-8,w);
            }
            else if(v[i]>99 && v[i]<1000) {
                settextstyle(SIMPLEX_FONT,HORIZ_DIR,2);
                bgiout<<v[i];
                outstreamxy(u-13,w);
            }
            else {
                settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
                bgiout<<v[i];
                outstreamxy(u-13,w);
            } //pentru numere mai mari de 1000 iese in afara
            u+=x2-x1;
        }
        u=(x2-x1)/2;
        w+=y2-y1;
    }

    getch();
    return 0;
}
