#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

double X1, Y1, X2, Y2;
double arrx1[10],arry1[10],arrx2[10],arry2[10];

float round_value(float v)
{
  return floor(v + 0.5);
}

void LineDDA(void)
{
  glClear(GL_COLOR_BUFFER_BIT);
  int j =0;
  while(j<8)
  {
  	  X1 = arrx1[j];
  	  Y1 = arry1[j];
  	  X2 = arrx2[j];
  	  Y2 = arry2[j];
  	  
	  double dx=(X2-X1);
	  double dy=(Y2-Y1);
	  double steps;
	  float xInc,yInc,x=X1,y=Y1;
	  /* Find out whether to increment x or y */
	  steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
	  //float m = dy/dx;
	  xInc=dx/(float)steps;
	  yInc=dy/(float)steps;
	
	  /* Plot the points */
	  glBegin(GL_POINTS);
	  /* Plot the first point */
	  glPointSize(4.0);
	  glColor3f(1.0,0.0,0.0);
	  glVertex2d(x,y);
	  int k;
	  /* For every step, find an intermediate vertex */
	  for(k=0;k<steps;k++)
	  {
	    x+=xInc;
	    y+=yInc;
	    /* printf("%0.6lf %0.6lf\n",floor(x), floor(y)); */
	    glColor3f(1.0,0.0,0.0);
	    glVertex2d(round_value(x), round_value(y));
	  }
	  glEnd();
	  j++;
	  glFlush();
	}
}


int main(int argc, char **argv)
{

int i = 0;

while(i<8)
{

  printf("Enter two end points of the line to be drawn:\n");
  printf("\nCase %d:",i+1);
  printf("\nEnter Point1( X1 , Y1):\n");
  scanf("%lf,%lf",&X1,&Y1);
  arrx1[i] = X1;
  arry1[i] = Y1;
  printf("\n");
  printf("\nCase %d:",i+1);
  printf("\nEnter Point2( X2 , Y2):\n");
  scanf("%lf,%lf",&X2,&Y2);
  arrx2[i] = X2;
  arry2[i] = Y2;
  i++;
  
}
  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(1000,1000);
  glutCreateWindow("DDA_Line");
  glClearColor(1.0,1.0,1.0,0);
  glColor3f(0.0,0.0,1.0);
  gluOrtho2D(-500 , 500 , -500 , 500);
  glutDisplayFunc(LineDDA);
  glutMainLoop();
  return 0;
}
