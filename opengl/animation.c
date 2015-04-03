//program to show animation using opengl

#include<stdio.h>
#include<GL/glut.h>
GLfloat angle=0.0f;
int refreshMills=30;
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glTranslatef(-0.5f,0.4f,0.0f);
	glRotatef(angle,0.0f,0.0f,1.0f);
	glBegin(GL_QUADS);
	glColor3f(1.0f,0.0f,0.0f);
	glVertex3f(-0.3f,-0.3f,0.0f);
	glVertex3f(0.3f,-0.3f,0.0f);
	glVertex3f(0.3f,0.3f,0.0f);
	glVertex3f(-0.3f,0.3f,0.0f);
	glEnd();
	glPopMatrix();
	glutSwapBuffers();
	angle+=2.0f;
}
void Timer(int value)
{
	glutPostRedisplay();
	glutTimerFunc(refreshMills,Timer,0);
	
}
void reshape(GLsizei width,GLsizei height)
{
	if(height == 0) height=1;
	GLfloat aspect=(GLfloat)width/(GLfloat)height;
	glViewport(0,0,width,height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
}
int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(640,480);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Animation via Idle Function");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0,Timer,0);
	glClearColor(1.0f,1.0f,1.0f,1.0f);
	glutMainLoop();
	return 0;
}
