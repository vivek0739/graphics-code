#include<stdio.h>
#include<graphics.h>
#define abs(a) ((a>0)?a:-a)
#define round(a) ((int)(a+0.5))

int main()
{
	int gd=DETECT,gm;
	float xinc,yinc;
	int x1,y1,x2,y2,dx,dy;
	int step;
	float x,y;
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	initgraph(&gd,&gm,NULL);
	
	dx=x2-x1;
	dy=y2-y1;
	
	if(abs(dx)>abs(dy))
		step=abs(dx);
	else
		step=abs(dy);
	
	xinc=(float)dx/(float)step;
	yinc=(float)dy/(float)step;
	x=x1,y=y1;
	//printf("%d %f\n",dy,xinc);
	putpixel(x1,y1,8);
	while(y<=y2)
	{
		x+=xinc;
		y+=yinc;
		putpixel(round(x),round(y),8);
		

	}
	
	getch();
	closegraph();
	
	return 0;
}
