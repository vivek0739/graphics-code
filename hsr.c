#include<graphics.h>
#include<stdio.h>
#define MAX_SIZE 10
#define MAX_NO_OF_POLY 10
#define MAX_X 202
#define MAX_Y 202
#define SHIFT_X 300
int g_polyCount;
int g_edgeCount[10];
int g_polylist[MAX_NO_OF_POLY][MAX_SIZE][3];
int depth[MAX_NO_OF_POLY];
int g_zbuff[MAX_Y][MAX_X];
void sort(int *x ,int k)
{
	int i,j,t;
	for(i=0;i<k-1;i++)
	{
		for(j=i+1;j<k;j++)
		if(x[i]>x[j])
		{
			t=x[i];
			x[i]=x[j];
			x[j]=t;
		}
	}
}
void getPoly()
{
	static int count;
	int n,i;
	scanf("%d%d",&g_edgeCount[count],&depth[count]);
	for(i=0;i<g_edgeCount[count];i++)
	{
		g_polylist[count][i][2]=depth[count];
		scanf("%d%d",&g_polylist[count][i][0],&g_polylist[count][i][1]);
	}
	g_polylist[count][i][0]=g_polylist[count][0][0];
		g_polylist[count][i][1]=g_polylist[count][0][1];
		count++;
}
void printpoly(int i)
{
	int j;
	setcolor(i+2);
	for(j=0;j<g_edgeCount[i];j++)
	{
		line(g_polylist[i][j][0]+SHIFT_X,g_polylist[i][j][1],g_polylist[i][j+1][0]+SHIFT_X,g_polylist[i][j+1][1]);
	}
}
void hsr(int in)
{
	int xi[MAX_X];
	float slope[10];
	int dx,dy;
	int i,j;
	for(i=0;i<g_edgeCount[in];i++)
	{
		dx=g_polylist[in][i+1][0]-g_polylist[in][i][0];
		dy=g_polylist[in][i+1][1]-g_polylist[in][i][1];
		if(dy==0) slope[i]=1.0;
		else if(dx==0) slope[i]=0.0;
		else slope[i]=(float)dx/dy;
	}
	int y;
	for(y=0;y<202;y++)
	{
		int k=0;
		for(i=0;i<g_edgeCount[in];i++)
		{
			if((g_polylist[in][i+1][1]>=y &&g_polylist[in][i][1]<y ) || (g_polylist[in][i+1][1]<y && g_polylist[in][i][1]>=y))
			{
				xi[k++]=g_polylist[in][i][0]+slope[i]*(y- g_polylist[in][i][1]);
			}

		}
		sort(xi,k);
		for(i=0;i<k;i+=2)
		{
			for(j=xi[i];j<=xi[i+1];j++)
			{
				if(g_zbuff[y][j]<depth[in])
				{
					g_zbuff[y][j]=depth[in];
					putpixel(j,y,in+2);
				}
			}
		}

	}
	getch();
}
int main()
{
	int gd=DETECT,gm;
	int i;
	scanf("%d",&g_polyCount);
	for(i=0;i<g_polyCount;i++)
	 getPoly();
	 initgraph(&gd,&gm,NULL);
	 rectangle(1,1,200,200);
	 rectangle(1+SHIFT_X,1,200+SHIFT_X,200);
	 outtextxy(1,202,"after removal");\
	 outtextxy(1+SHIFT_X,202,"before removal");
	 for(i=0;i<g_polyCount;i++)
	 {
	 	printpoly(i);
	
	 }
	
	 getch();
	 for(i=0;i<g_polyCount;i++)
	 {
	 	hsr(i);
		
	 }
	 getch();
}