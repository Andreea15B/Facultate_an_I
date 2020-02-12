// http://www.cs.colorado.edu/~main/cs1300/doc/bgi/bgi.html
#include<iostream>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int main()
{
	int gd=0,gm;
	initgraph(&gd,&gm,"");
	rectangle(250,50,350,350);
	circle(300,100,50);
	circle(300,200,50);
	circle(300,300,50);
	line(80,80,80,500);
	line(80,80,250,80);

 	while(!kbhit())
	{
		int x=100;
		setfillstyle(1,RED);
		floodfill(x+200,100,WHITE);
		delay(500);
		setfillstyle(1,BLACK);
		floodfill(x+200,100,WHITE);
		setfillstyle(1,YELLOW);
		floodfill(x+200,200,WHITE);
		delay(500);
		setfillstyle(1,BLACK);
		floodfill(x+200,200,WHITE);
		setfillstyle(1,GREEN);
		floodfill(x+200,300,WHITE);
		delay(300);
		setfillstyle(1,BLACK);
		floodfill(x+200,300,WHITE);
	}
 	getch();
	closegraph();
}
