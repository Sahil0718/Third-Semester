
#include<GL/glut.h>
#include <iostream>
#include <cmath>
using namespace std;
int WIN_WIDTH = 800;
int WIN_HEIGHT = 600;

int Xn, X0, Yn, Y0, step, x, y, p;
int xinc = 1, yinc = 1;
int dx,dy;
int i =0;

void DrawLine(){

dx = abs(Xn-X0);
dy = abs(Yn-Y0);

if(X0>Xn){
    xinc = -1;
}

if(Y0>Yn){
    yinc = -1;
}

x =X0;
y = Y0;
glBegin(GL_POINTS);
glVertex2i(x,y);

if(dx>dy){
    step = dx;
     p = 2*dy - dx;
     while(i<step){
        x = x+xinc;

     if(p<0){
        p = p+2*dy;
     }
     else{
            y = y + yinc;
        p = p+2*dy-2*dx;
     }
     glVertex2f(x,y);
     i = i+1;
     }
}
else{
    step = dy;
     p = 2*dx - dy;
     while(i<step){
        y = y+yinc;

     if(p<0){
        p = p+2*dx;
     }
     else{
        x = x+xinc;
        p = p+2*dx-2*dy;

     }
     glVertex2f(x,y);
     i = i+1;
     }
}

  glEnd();
  glFlush();


}

void myInit() {
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("SAHIL BHATTARAI!!");
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0, 0, 0);
    glLineWidth(5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-WIN_WIDTH, WIN_WIDTH, -WIN_HEIGHT, WIN_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
cout<<"Enter the initial value for x0 and y0 : ";
cin>>X0>>Y0;

cout<<"Enter the final value for xn and yn : ";
cin>>Xn>>Yn;
    myInit();
    glutDisplayFunc(DrawLine);
    glutMainLoop();
    return 0;
}
