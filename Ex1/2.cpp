#include<GL/glut.h>

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	
	//bottom
	glColor3d(0.0,0.7,0.0);
	glBegin(GL_QUADS);
	glVertex2d(0,0);		
	glVertex2d(640,0);
	glVertex2d(640,100);
	glVertex2d(0,100);
	
	//left mid
	glColor3d(0.7,0.7,0.2);
	glVertex2d(50,100);
	glVertex2d(250,100);
	glVertex2d(250,300);
	glVertex2d(50,300);
	
	//right mid
	glColor3d(0.7,0.2,0.2);
	glVertex2d(250,100);
	glVertex2d(590,100);
	glVertex2d(590,300);
	glVertex2d(250,300);
	
	//right top
	glColor3d(0.6,0.3,0.1);
	glVertex2d(250,300);
	glVertex2d(590,300);
	glVertex2d(490,420);
	glVertex2d(150,420);
	
	//door
	glColor3d(0.6,0.6,0.6);
	glVertex2d(110,100);
	glVertex2d(190,100);
	glVertex2d(190,200);
	glVertex2d(110,200);
	
	//window
	glColor3d(0.6,0.6,0.6);
	glVertex2d(390,175);
	glVertex2d(490,175);
	glVertex2d(490,230);
	glVertex2d(390,230);
	
	glEnd();
	
	//left top
	glColor3d(0.7,0.1,0.8);
	glBegin(GL_TRIANGLES);
	
	glVertex2d(50,300);
	glVertex2d(250,300);
	glVertex2d(150,420);
	glEnd();
	
	//window cross and inner border
	glColor3d(0.0,0.0,0.0);
	glLineWidth(3.0);
	glBegin(GL_LINES);
	
	glVertex2d(390,202.5);
	glVertex2d(490,202.5);
	
	glVertex2d(440,175);
	glVertex2d(440,230);
	
	glVertex2d(50,300);
	glVertex2d(590,300);
	
	glVertex2d(250,300);
	glVertex2d(150,420);
	
	glVertex2d(250,100);
	glVertex2d(250,300);
	
	glEnd();
	
	//window border
	glBegin(GL_LINE_LOOP);
	
	glVertex2d(390,175);
	glVertex2d(490,175);
	glVertex2d(490,230);
	glVertex2d(390,230);
	
	glEnd();
	
	//door border
	glBegin(GL_LINE_STRIP);
	
	glVertex2d(190,100);
	glVertex2d(190,200);
	glVertex2d(110,200);
	glVertex2d(110,100);
	
	glEnd();
	
	//border
	glBegin(GL_LINE_STRIP);
	
	glVertex2d(50,100);
	glVertex2d(50,300);
	glVertex2d(150,420);
	glVertex2d(490,420);
	glVertex2d(590,300);
	glVertex2d(590,100);
	
	glEnd();
	
	//bottom border
	glBegin(GL_LINE_STRIP);
	glVertex2d(640,100);
	glVertex2d(0,100);
	glEnd();
	
	//door lock
	glPointSize(12.0);
	glBegin(GL_POINTS);
	glVertex2d(125,155);
	
	glEnd();
	
	glFlush();	
}	
	
void init()
{
	glClearColor(0.0,0.5,1.0,0.0);
}

void reshape(int w,int h)
{
	//viewport
	glViewport(0,0,w,h);	
	//projection
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluOrtho2D(0,640,0,480);
	
	glMatrixMode(GL_MODELVIEW);	
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	
	glutInitWindowPosition(300,100);
	glutInitWindowSize(640,480);
	
	glutCreateWindow("House");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	init();
	
	glutMainLoop();
	
	return 1;	
}
