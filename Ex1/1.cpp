#include<GL/glut.h> 
void display()
{
/* clear window */
glClear(GL_COLOR_BUFFER_BIT);
/*point*/
glBegin(GL_POINTS);
glVertex2d(10,100);
glEnd();
/*line*/
glBegin(GL_LINES);
glVertex2d(20,100);
glVertex2d(50,100);
glEnd();
/*line strip*/
glColor3f(1.0, 1.0, 0.0);
glBegin(GL_LINE_STRIP);
glVertex2d(60,100);
glVertex2d(100,100);
glVertex2d(100,120);
glEnd();
/*line loop*/
glColor3f(1.0, 1.0, 0.5);
glBegin(GL_LINE_LOOP);
glVertex2d(120,100);
glVertex2d(170,100);
glVertex2d(170,180);
glVertex2d(190,80);
glEnd();
/*Triangle*/
glColor3f(1.0, 0.0, 1.0);
glBegin(GL_TRIANGLES);
glVertex2d(200,100);
glVertex2d(250,100);
glVertex2d(250,150);
glEnd();
/*Triangle Strip*/
glColor3f(0.0, 1.0, 1.0);
glBegin(GL_TRIANGLE_STRIP);
glVertex2d(300,100);
glVertex2d(350,100);
glVertex2d(350,150);
glVertex2d(400,100);
glVertex2d(450,150);
glEnd();
/*Triangle Fan*/
glColor3f(1.0, 0.5, 1.0);
glBegin(GL_TRIANGLE_FAN);
glVertex2d(500,100);
glVertex2d(550,220);
glVertex2d(600,340);
glVertex2d(650,220);
glVertex2d(700,320);
glEnd();
/*Quads*/
glBegin(GL_QUADS);
glVertex2d(60, 330);
glVertex2d(75, 320);
glVertex2d(75, 280);
glVertex2d(60, 270);
glEnd();
/*Quad Strip*/
glBegin(GL_QUAD_STRIP);
glVertex2d(100, 330);
glVertex2d(115, 320);
glVertex2d(115, 280);
glVertex2d(100, 270);
glEnd();
/*polygon */
glBegin(GL_POLYGON);
glVertex2d(150,450);
glVertex2d(170,450);
glVertex2d(190,350);
glVertex2d(170,250);
glVertex2d(150,250);
glVertex2d(130,350);

glEnd();
/* flush GL buffers */
glFlush();
}
void init() // initialize colors
{
/* set clear color to black */
glClearColor(0.0, 0.0, 0.0, 0.0);
/* set fill color to white */
glColor3f(1.0, 1.0, 1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glPointSize(5);
gluOrtho2D(0.0, 1000.0, 0.0, 500.0);
}
int main(int argc, char** argv)
{
/* Initialize mode and open a window in upper left corner of/* screen */
/* Window title is name of program (arg[0]) */
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(1000, 500); // Set window Size
glutInitWindowPosition(0, 0); //Set Window Position
glutCreateWindow("simple"); //Create Window and Set title
glutDisplayFunc(display); //Call the Displaying function
init(); //Initialize Drawing Colors
glutMainLoop(); //Keep displaying until program is closed.
return 1;
}