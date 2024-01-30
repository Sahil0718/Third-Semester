#include <GL/glut.h>
#include<iostream>
#include<cmath>
using namespace std;
int rectwidth = 200 , rectheight = 50;
int oneX = 100, oneY=100;
int x_max = 800, y_max = 400;

int vertices[][4]={{oneX,oneX+rectwidth,oneX+rectwidth,oneX},{oneY,oneY,oneY+rectheight,oneY+rectheight},{1,1,1,1}};

void simpleRotation(){

glBegin(GL_LINE_LOOP);
for(int i=0;i<4;i++)
    glVertex2i(vertices[0][i],vertices[1][i]);
glEnd();
glRotated(30,0,0,1);
glBegin(GL_LINE_LOOP);
for(int i=0;i<4;i++)
    glVertex2i(vertices[0][i],vertices[1][i]);
glEnd();
glFlush();
}


void myInit() {
    glutInitWindowSize(x_max,y_max);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Rotation");
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0, 0, 0);
    glLineWidth(3);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,x_max,0,y_max);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    myInit();
    glutDisplayFunc(simpleRotation);
    glutMainLoop();
    return 0;
}

