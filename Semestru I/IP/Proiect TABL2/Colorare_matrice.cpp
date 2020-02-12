#include <iostream>
#include <graphics.h>
#include <fstream>
using namespace std;
ifstream fin("gr.in");
int main()
{
    initwindow(600,600);
    int i,v[20],x1=10,x2=60,y1=10,y2=60,n,m,j;
    settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
    int u,w;
    u=(x2-x1)/2;
    w=(y2-y1)/2;
    fin>>n>>m;
    for(j=0;j<n;j++) {
        for(i=0;i<m;i++) {
            fin>>v[i];
            if(v[i]<10) {
                settextstyle(TRIPLEX_FONT,HORIZ_DIR,3);
                bgiout<<v[i];
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
    int x,y,z,t;
    x=y=10; z=m*50+x; t=n*50+x;
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
    setfillstyle(SOLID_FILL, 4);
    for(i=11;i<n*50+10;i+=50) {
        for(j=11;j<m*50+10;j+=50) {floodfill(j,i,15); delay(100);}
    }
    getch();
    return 0;
}
