#include <stdio.h> 
#include <GL/glut.h>

void display(void) 
{ 
	glClearColor(1.0f,1.0f,1.0f,1.0f); 
 	glClear( GL_COLOR_BUFFER_BIT); 
 	glColor3f(0.0, 1.0, 0.0); 
 	glBegin(GL_POLYGON); 
  	glVertex3f(3.0f, 3.0f, 0.0); 
  	glVertex3f(3.0f, 5.0f, 0.0); 
  	glVertex3f(5.0f, 5.0f, 0.0); 
  	glVertex3f(5.0f, 3.0f, 0.0); 
 	glEnd(); 
 	glFlush(); 
}

int main(int argc, char **argv) 
{ 
 //printf("hello world\n"); 
 glutInit(&argc, argv); 
 glutInitDisplayMode ( GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);

 glutInitWindowPosition(150,100); 
 glutInitWindowSize(00,300); 
 glutCreateWindow ("rotation of square by 30 degree");

 glClearColor(0.0, 0.0, 0.0, 0.0);          
 glMatrixMode(GL_PROJECTION);              
 glLoadIdentity();                           
 glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   
 glutDisplayFunc(display); 
	aaglRotatef(30.0f,0.3f,0.2f,0.7f);
glutDisplayFunc(display);
 glutMainLoop();

 return 0; 
}
