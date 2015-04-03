#include <stdio.h>
//#include <conio.h>
#include <graphics.h>
#define MAX_POLY_SIZE 10
#define MAX_NO_OF_POLY 10
#define MAX_X 202
#define MAX_Y 202
#define SHIFT_X 300
int g_polyList[MAX_NO_OF_POLY][MAX_POLY_SIZE][3];
int g_edgeCount[MAX_NO_OF_POLY];
int g_polyCount;
char depth[10];
char g_zBuf[MAX_Y][MAX_X];
FILE *fp;
void sort(int *a, int size)
{
	int t, i, j;
	for(i=0;i<size-1;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(a[i]>a[j])
			{
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
}
void getPoly()
{
	static int count;
	int i;
	printf("Enter the no. of edges of polygon %d: ", count+1);
	fscanf(fp,"%d",&g_edgeCount[count]);
	printf("Enter the depth of the polygon %d: ", count+1);
	fscanf(fp,"%d",&depth[count]);
	for(i=0;i<g_edgeCount[count];i++)
	{
		g_polyList[count][i][2]=depth[count];
		printf("\tX%d(<300) Y%d(<200) : ",i+1,i+1);
		fscanf(fp,"%d%d",&g_polyList[count][i][0],&g_polyList[count][i][1]);
	}
	g_polyList[count][i][0]=g_polyList[count][0][0];
	g_polyList[count][i][1]=g_polyList[count][0][1];
	count++;
}
void printPoly(int i)
{
	int j;
	char str[30];
	setcolor(i+2);
//	line(205, 10+i*10, 210, 10+i*10);
	sprintf(str,"depth %d", depth[i]);
	outtextxy(212, 10+i*10, str);
	for(j=0;j<g_edgeCount[i];j++)
	{
		line(g_polyList[i][j][0]+SHIFT_X,g_polyList[i][j][1],g_polyList[i][j+1][0]+SHIFT_X,g_polyList[i][j+1][1]);
	}
}
void HSR(int in)
{
	int n,i,j,k,gd,gm,dy,dx;
	int x,y,temp;
	int xi[200];
	float slope[200];
	for(i=0;i<g_edgeCount[in];i++)
	{
		dy=g_polyList[in][i+1][1]-g_polyList[in][i][1];
		dx=g_polyList[in][i+1][0]-g_polyList[in][i][0];
		if(dy==0) slope[i]=1.0;
		if(dx==0) slope[i]=0.0;
		if((dy!=0)&&(dx!=0))
		{
			slope[i]=(float) dx/dy;
		}
	}
	for(y=0;y< 200;y++)
	{
		k=0;
		for(i=0;i<g_edgeCount[in];i++)
		{
			if( ((g_polyList[in][i][1]<=y)&&(g_polyList[in][i+1][1]>y))||
				((g_polyList[in][i][1]>y)&&(g_polyList[in][i+1][1]<=y)))
			{
				xi[k]=(int)(g_polyList[in][i][0]+slope[i]*(y-g_polyList[in][i][1]));
				k++;
			}
		}
		sort(xi, k);
		for(i=0;i<k;i+=2)
		{
			for(j=xi[i];j<xi[i+1];j++)
			{
				if(g_zBuf[y][j]<depth[in])
				{
					putpixel(j, y, in+2);
					g_zBuf[y][j]=depth[in];
				}
			}
		}
		getch();
	}
	getch();
}
int main()
{
	int n,i,j,k,gd,gm,dy,dx;
	int x,y,temp;
	int xi[MAX_POLY_SIZE];
	float slope[20];
	//clrscr();
	fp=fopen("DATA.TXT", "r");
	if(fp==NULL)
	{
		printf("Unable to open the file data.txt");
		getch();
		exit(0);
	}
	printf("Enter the total no of polygon(<7) : ");
	scanf("%d",&g_polyCount);
	for(i=0;i<g_polyCount;i++)
	{
		getPoly();
	}
	detectgraph(&gd,&gm);
	initgraph(&gd,&gm,NULL);
	rectangle(1,1,200,200);
	rectangle(1+SHIFT_X,1,200+SHIFT_X,200);
	outtextxy(2,210,"Fig 1: After HSR");
	outtextxy(2+SHIFT_X,210,"Fig 2:Before HSR");
	for(i=0;i<g_polyCount;i++)
	{
		printPoly(i);
	}
	getch();
	for(i=0;i<g_polyCount;i++)
	{
		HSR(i);
	}
	printf("done");
	getch();
	closegraph();
	fclose(fp);
	return 0;
}
