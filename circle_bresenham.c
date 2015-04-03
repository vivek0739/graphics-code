#include<stdio.h>

#include<graphics.h>
#include<math.h>

void main()
{
	int gd=DETECT,gm;
	int r,x,y,p,xc=320,yc=240;
	
	printf("Enter the radius");
	scanf("%d",&r);
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	cleardevice();
	setbkcolor(BLUE);
	x=0;
	y=r;
	putpixel(xc+x,yc-y,1);
	p=1-r;
	for(x=0;x<=y;)
	{	
		x++;
		if(p<0)
		{
			y=y;
			p+=2*x+1;

		}
		else
		{
		    y=y-1;
			p+=2*x+1-2*y;
			
		}
		putpixel(xc+x,yc-y,3);
		putpixel(xc-x,yc-y,3);
		putpixel(xc+x,yc+y,3);
		putpixel(xc-x,yc+y,3);
		putpixel(xc+y,yc-x,3);
		putpixel(xc-y,yc-x,3);
		putpixel(xc+y,yc+x,3);
		putpixel(xc-y,yc+x,3);
	}
	getch();
	closegraph();

}
