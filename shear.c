#include<stdio.h>
#include<graphics.h>
#include<math.h>
#define X 300
#define Y 250
double inputVec[3][1];
double outputVec[3][1];
double transMat[3][3]={0,0};
double tempTransMat[3][3]={0,0};
void setVal(double *x,double *y)
{
	*x=outputVec[0][0];
	*y=outputVec[1][0];

}
void createMatrix(double x ,double y)
{
	inputVec[0][0]=x;
	inputVec[1][0]=y;
	inputVec[2][0]=1;
}
void multiply()
{
	int i,j,k;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			outputVec[i][j]=0;
			for(k=0;k<3;k++)
			outputVec[i][j]+=transMat[i][k]*inputVec[k][j];
			
		}	
	}
}
void createTempTransform(double a,double b,double c,double d,double e,double f)
{
	tempTransMat[0][0]=a;
	tempTransMat[0][1]=b;
	tempTransMat[0][2]=c;
	tempTransMat[1][0]=d;
	tempTransMat[1][1]=e;
	tempTransMat[1][2]=f;
	tempTransMat[2][0]=0;
	tempTransMat[2][1]=0;
	tempTransMat[2][2]=1;
}
void createTransformMat(double a,double b,double c,double d,double e,double f)
{
	transMat[0][0]=a;
	transMat[0][1]=b;
	transMat[0][2]=c;
	transMat[1][0]=d;
	transMat[1][1]=e;
	transMat[1][2]=f;
	transMat[2][0]=0;
	transMat[2][1]=0;
	transMat[2][2]=1;
}
void mulTransforms()
{
	int i,j,k;
	double temp[3][3];
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			temp[i][j]=0;
			for(k=0;k<3;k++)
			{
				temp[i][j]+=tempTransMat[i][k]*transMat[k][j];

			}
		}
	}
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
		{
			transMat[i][j]=temp[i][j];
		}
}
void drawAxes()
{
	line(X,0,X,2*Y);
	line(0,Y,2*X,Y);

}
void rect(double x1,double y1,double x2,double y2,double x3,double y3,double x4,double y4)
{
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x1,y1);
}
void postTransform(double *x,double *y,double a,double b,double c,double d,double e,double f)
{
	createMatrix(*x,*y);
	createTempTransform(a,b,c,d,e,f);
	createTransformMat(1,0,-X,0,1,-Y);
	mulTransforms();
	createTempTransform(1,0,X,0,1,Y);
	mulTransforms();
	multiply();
	setVal(x,y);

}
int main()
{
	int gmode=DETECT,gdriver;
	double x1,y1,x2,y2,x3,y3,x4,y4;
	printf("Enter the coordinate of the rectangle");
	scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);

	//shifting to origin
	createMatrix(x1,y1);
	createTransformMat(1,0,X,0,-1,Y);
	multiply();
	setVal(&x1,&y1);

	createMatrix(x2,y2);
	createTransformMat(1,0,X,0,-1,Y);
	multiply();
	setVal(&x2,&y2);

	createMatrix(x3,y3);
	createTransformMat(1,0,X,0,-1,Y);
	multiply();
	setVal(&x3,&y3);

	createMatrix(x4,y4);
	createTransformMat(1,0,X,0,-1,Y);
	multiply();
	setVal(&x4,&y4);
	
	double sh,shy;
	scanf("%lf",&sh);
	initgraph(&gmode,&gdriver,NULL);
	drawAxes();
	rect(x1,y1,x2,y2,x3,y3,x4,y4);
	
	
	createMatrix(x1,y1);
	createTempTransform(1,0,0,-sh,1,0);
	createTransformMat(1,0,-x1,0,1,-y1);
	mulTransforms();
	createTempTransform(1,0,x1,0,1,y1);
	mulTransforms();
	multiply();
	setVal(&x1,&y1);
	
	createMatrix(x2,y2);
	createTempTransform(1,0,0,-sh,1,0);
	createTransformMat(1,0,-x1,0,1,-y1);
	mulTransforms();
	createTempTransform(1,0,x1,0,1,y1);
	mulTransforms();
	multiply();
	setVal(&x2,&y2);

	createMatrix(x3,y3);
	createTempTransform(1,0,0,-sh,1,0);
	createTransformMat(1,0,-x1,0,1,-y1);
	mulTransforms();
	createTempTransform(1,0,x1,0,1,y1);
	mulTransforms();
	multiply();
	setVal(&x3,&y3);

	createMatrix(x4,y4);
	createTempTransform(1,0,0,-sh,1,0);
	createTransformMat(1,0,-x1,0,1,-y1);
	mulTransforms();
	createTempTransform(1,0,x1,0,1,y1);
	mulTransforms();
	multiply();
	setVal(&x4,&y4);
	
	rect(x1,y1,x2,y2,x3,y3,x4,y4);
	getch();
	closegraph();
	
	return 0;
}
