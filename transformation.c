#include<stdio.h>
#include<graphics.h>
#include<math.h>
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
	int gd=DETECT,gm;
	float xinc,yinc;
	int x1,y1,x2,y2,x3,y3,tx=50,ty=100,types;	
	int sx=2,sy=2;
	double theta=30.0;
	
	scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
	initgraph(&gd,&gm,NULL);
	cleardevice();
	setbkcolor(BLUE);
	maxx=getmaxx();
	midx=maxx/2;
	maxy=getmaxy();
	midy=maxy/2;
	line(0,midy,maxx, midy);
	line(midx,0,midx, maxy);
	tri(x1,x2,x3,y1,y2,y3);
	scanf("%d",&types);
	switch(types)
	{
		case 1:
		{
			//translation
			
			//scanf("%d",&tx);
			//scanf("%d",&ty);
		
			
			
			x1+=tx;
			x2+=tx;
			x3+=tx;
			y1+=ty;
			y2+=ty;
			y3+=ty;
			tri(x1,x2,x3,y1,y2,y3);
			break;
		}
		case 2:
		{
			//rotation
			
			
			theta=theta*3.14/180;
			
			x1=abs(x1*cos(theta)-y1*sin(theta));
			x2=abs(x2*cos(theta)-y2*sin(theta));
			x3=abs(x3*cos(theta)-y3*sin(theta));
			y1=abs(x1*sin(theta)+y1*cos(theta));
			y2=abs(x2*sin(theta)+y2*cos(theta));
			y3=abs(x3*sin(theta)+y3*cos(theta));
			//printf("%d %d %d %d",x1,y1,x2,y2);
			tri(x1,x2,x3,y1,y2,y3);
			
			break;
		}
		case 3:
		{
			//scaling
			x1*=sx;
			y1*=sy;
			x2*=sx;
			y2*=sy;
			x3*=sx;
			y3*=sy;
			tri(x1,x2,x3,y1,y2,y3);
			break;

		}
	}
	getch();
	closegraph();
	
	return 0;
}
