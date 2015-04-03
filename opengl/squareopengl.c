#include <stdio.h> 
#include <GL/glut.h>

void display(void) 
{ 
	glClearColor(1.0f,1.0f,1.0f,1.0f); 
 	glClear( GL_COLOR_BUFFER_BIT); 
 	glColor3f(0.0, 1.0, 0.0); 
 	glBegin(GL_POLYGON); 
  	glVertex3f(4.0f, 4.0f, 0.0); 
  	glVertex3f(4.0f, 8.0f, 0.0); 
  	glVertex3f(8.0f, 8.0f, 0.0); 
  	glVertex3f(8.0f, 4.0f, 0.0); 
 	glEnd(); 
 	glFlush(); 
}

int main(int argc, char **argv) 
{ 
 
 glutInit(&argc, argv); 
 glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

 glutInitWindowPosition(100,100); 
 glutInitWindowSize(300,300); 
 glutCreateWindow ("square");

 glClearColor(0.0, 0.0, 0.0, 0.0);          
 glMatrixMode(GL_PROJECTION);              
 glLoadIdentity();                           
 glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   
 
glutDisplayFunc(display);
 glutMainLoop();

 return 0; 
}
