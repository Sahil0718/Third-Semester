
#include <GL/glut.h>
#include <iostream>
#include <cmath>

using namespace std;

int WIN_WIDTH = 800;
int WIN_HEIGHT = 600;


int X1,Y1,X2,Y2,dx,dy;
float m,x,y;
int step,inc;
void DMA(){
glClearColor(1,1,1,1);
glClear(GL_COLOR_BUFFER_BIT);


dy = Y2-Y1; dx=X2-X1;
m = dy/dx;
int c = Y1-m*X1;
x = X1; y = Y1;
int i = 0;
glBegin(GL_POINTS);
glLineWidth(5);
glVertex2f(round(x), round(y));
if(abs(dx)>abs(dy)){
    step  = abs(dx);
    int inc = dx/step;
    while(i<step){
        x = x+inc;
        y = m*x+c;
        glVertex2f(round(x), round(y));
        i++;
    }
}else{
step = abs(dy);
inc = dy/step;
while(i<step){
        y = y+inc;
        x = (y-c)/m;
          glVertex2f(round(x), round(y));
          i++;
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

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-WIN_WIDTH, WIN_WIDTH, -WIN_HEIGHT, WIN_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
cout<<"Enter the initial value for X1 and Y1 : "<<endl;
cin>>X1>>Y1;
cout<<"Enter the final value for X2 and Y2 : "<<endl;
cin>>X2>>Y2;

    myInit();
    glutDisplayFunc(DMA);
    glutMainLoop();
    return 0;
}
