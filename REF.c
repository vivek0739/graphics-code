/*along y=x line */
#include<stdio.h>
#include<graphics.h>
int maxx, maxy, midx, midy;
void tri(int x1, int x2, int x3, int y1, int y2, int y3)
{
	x1=midx+x1;
	x2=midx+x2;
	x3=midx+x3;
	y1=midy-y1;
	y2=midy-y2;
	y3=midy-y3;
	moveto(x1, y1);
	lineto(x2, y2);
	lineto(x3, y3);
	lineto(x1, y1);
}
int main()
{
	int gdriver=DETECT,gmode;
	int x1=10,x2=70,x3=40,y1=20,y2=20,y3=100,x,y;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	setbkcolor(BLUE);
	maxx=getmaxx();
	midx=maxx/2;
	maxy=getmaxy();
	midy=maxy/2;
	line(0,midy,maxx, midy);
	line(midx,0,midx, maxy);
	tri(x1,x2,x3,y1,y2,y3);
	x1=x1^y1,x2=x2^y2,x3=x3^y3;
	y1=x1^y1,y2=x2^y2,y3=x3^y3;
	x1=x1^y1,x2=x2^y2,x3=x3^y3;
	tri(x1,x2,x3,y1,y2,y3);
	getch();
	closegraph();
}
