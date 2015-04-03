#include<stdio.h>
#include<graphics.h>
int main()
{
	int gd=DETECT,gm;
	float xinc,yinc;
	int x1,y1,x2,y2,dx,dy,p;
	int step;
	float x,y;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	initgraph(&gd,&gm,NULL);
	dx=x2-x1;
	dy=y2-y1;
	p=2*dy-dx;
	x=x1;
	y=y1;
	putpixel(x,y,5);
	while(x<=x2)
	{
		x++;
		if(p>0)
		{
			y++;
			p+=2*dx;
		}
		p+=2*dy;
		putpixel(x,y,5);
	}
	getch();
	closegraph();
	
	return 0;
}
