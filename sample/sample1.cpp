#include<GL/glut.h>
#include<stdio.h>
int flag=0;
int alpha=0;
int beta=0;
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if(flag){
        glOrtho(-500,500,-500,500,-500,500);
    }
    else{
        gluPerspective(100,1,0.1,1000);
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,300,0,0,0,0,1,0);
    glRotatef(alpha,0,1,0);
    glRotatef(beta,1,0,0);
    glColor3f(0.0,1.0,0.0);
    glutWireSphere(50,10,10);
    glBegin(GL_LINES);
    glColor3f(0.0,1.0,0.0);
    glVertex2i(0,0);
    glVertex2i(0,100);
    glEnd();
    glFlush();

}
void keyboard(unsigned char key,int x ,int y){
    if (key=='w')
        alpha++;
    else if (key=='s')
        alpha--;
    else if (key=='a')
        beta++;
    else if (key=='d')
        beta--;
    else if (key=='x')
        flag=1;
    glutPostRedisplay();
}
void timer(int v){
    alpha++;
    glutPostRedisplay();
    glutTimerFunc(1000,timer,v);
}
int main(int argc,char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
    glutInitWindowSize(1000,1000);
    glutInitWindowPosition(0,0);
    glClearColor(1.0,1.0,1.0,1.0);
    glEnable(GL_DEPTH_TEST);
    glutCreateWindow("Test");
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
}