#include <stdio.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <GL/glut.h>

using namespace std;

int pntX1, pntY1, choice = 0, vertices;

vector<int> pntX;
vector<int> pntY;

vector<int> lpntX;
vector<int> lpntY;


int transX, transY;
double scaleX, scaleY;
double angle, angleRad;

int ltransX, ltransY;
double lscaleX, lscaleY;
double langle, langleRad;


double round(double d)
{
	return floor(d + 0.5);
}

void drawLine()
{
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < 2; i++)
	{
		glVertex2i(lpntX[i], lpntY[i]);
	}
	glEnd();
}


void drawLineTrans(int x, int y)
{
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < 2; i++)
	{
		glVertex2i(lpntX[i] + x, lpntY[i] + y);
	}
	glEnd();
}

void drawLineScale(double x, double y)
{
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	for (int i = 0; i < 2; i++)
	{
		int m = round((lpntX[i] * x) + (lpntX[0]*(1-x)));
		int n = round((lpntY[i] * y) + (lpntY[0]*(1-y)));
		glVertex2i(m,n);
	}
	glEnd();
}

void drawLineRotation(double langleRad)
{
	glBegin(GL_LINES);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < 2; i++)
	{
		int x =lpntX[0]+round(((lpntX[i]-lpntX[0]) * cos(langleRad)) - ((lpntY[i]-lpntY[0]) * sin(langleRad)));
		int y =lpntY[0]+round(((lpntX[i]-lpntX[0]) * sin(langleRad)) + ((lpntY[i]-lpntY[0]) * cos(langleRad)));
		glVertex2i(x,y);
	}
	glEnd();
}


void drawPolygon()
{
	glBegin(GL_QUADS);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = 0; i < vertices; i++)
	{
		glVertex2i(pntX[i], pntY[i]);
	}
	glEnd();
}

void drawPolygonTrans(int x, int y)
{
	glBegin(GL_QUADS);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = 0; i < vertices; i++)
	{
		glVertex2i(pntX[i] + x, pntY[i] + y);
	}
	glEnd();
}

void drawPolygonScale(double x, double y)
{
	glBegin(GL_QUADS);
	glColor3f(1.0, 1.0, 0.0);
	for (int i = 0; i < vertices; i++)
	{
		int m = round((pntX[i] * x) + (pntX[0]*(1-x)));
		int n = round((pntY[i] * y) + (pntY[0]*(1-y)));
		glVertex2i(m,n);
	}
	glEnd();
}

void drawPolygonRotation(double angleRad)
{
	glBegin(GL_QUADS);
	glColor3f(0.0, 0.0, 1.0);
	for (int i = 0; i < vertices; i++)
	{
		int x =pntX[0]+round(((pntX[i]-pntX[0]) * cos(angleRad)) - ((pntY[i]-pntY[0]) * sin(angleRad)));
		int y =pntY[0]+round(((pntX[i]-pntX[0]) * sin(angleRad)) + ((pntY[i]-pntY[0]) * cos(angleRad)));
		glVertex2i(x,y);	
		
	}
	glEnd();
}


void myInit(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glColor3f(2.0f, 0.0f, 1.0f);
	glPointSize(4.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-500,500,-500,500);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

}


void myDisplay(void)
{
	
		drawPolygonScale(scaleX, scaleY);	
		drawPolygonTrans(transX, transY);
		drawPolygonRotation(angleRad);
		drawPolygon();
		
		if(scaleX<1 || scaleY<1)
			drawPolygonScale(scaleX, scaleY);

		drawLineScale(lscaleX, lscaleY);
		drawLineTrans(ltransX,ltransY);	
		drawLineRotation(langleRad);
		drawLine();
		
		if(lscaleX<1 || lscaleY<1)
			drawLineScale(lscaleX, lscaleY);
	
	glFlush();
}

int main(int argc, char** argv)
{
	cout << "\nPOLYGON\nEnter no of vertices: "; 
	cin >> vertices;

	for (int i = 0; i < vertices; i++)
	{
		cout << "Enter co-ordinates for vertex " << i + 1 << " : "; cin >> pntX1 >> pntY1;
		pntX.push_back(pntX1);
		pntY.push_back(pntY1);
	}
	
	cout << "\nLINE\nEnter the vertices\n";
	
	for (int i = 0; i < 2; i++)
	{
		cout << "Enter co-ordinates for vertex " << i + 1 << " : "; cin >> pntX1 >> pntY1;
		lpntX.push_back(pntX1);
		lpntY.push_back(pntY1);
	}
	
	cout <<  "POLYGON" << endl;
	cout << "1. Translation for Polygon" << endl;
	cout << "2. Scaling for Polygon" << endl;
	cout << "3. Rotation for Polygon" << endl;
	cout <<  "LINE" << endl;
	cout << "4. Translation for Line "<<endl;
	cout << "5. Scaling for Line" << endl;
	cout << "6. Rotation for Line" << endl;
	cout << "0. Exit\nEnter Choice:";
	
	cin >> choice;
	
	while(choice>0)
	{
	switch(choice)
	{
		case 1 : cout << "Enter the translation factor (tx,ty) for polygon: "; cin >> transX >> transY; break;
		case 2 : cout << "Enter the scaling factor (sx,sy) (First vertex is the fixed point) for polygon: "; cin >> scaleX >> scaleY;drawPolygonScale(scaleX, scaleY); break;
		case 3 : cout << "Enter the angle for rotation for polygon: "; cin >> angle;angleRad = angle * 3.1416 / 180;break;
		case 4 : cout << "Enter the translation factor (tx,ty) for line: "; cin >> ltransX >> ltransY;break;
		case 5 : cout << "Enter the scaling factor (sx,sy) (First vertex is the fixed point) for line: "; cin >> lscaleX >> lscaleY;break;
		case 6 : cout << "Enter the angle for rotation for line: "; cin >> langle;langleRad = langle * 3.1416 / 180;break;
		default : break;
	}
	cout << "\nEnter Choice:";
	cin >> choice;
	}
	
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000,1000);
	glutInitWindowPosition(0,500);
	glutCreateWindow("2D Transformations");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
	return 0;
}
