#include<GL/glut.h>
#include<iostream>


using namespace std;
int Xc, Yc, r;
int WIN_WIDTH = 800;
int WIN_HEIGHT = 600;

void Draw(int x, int y){

glBegin(GL_POINTS);
glVertex2i(x+Xc, y+Yc);
glVertex2i(x+Xc, -y+Yc);
glVertex2i(-x+Xc, y+Yc);
glVertex2i(-x+Xc, -y+Yc);
glVertex2i(y+Xc, x+Yc);
glVertex2i(y+Xc, -x+Yc);
glVertex2i(-y+Xc, x+Yc);
glVertex2i(-y+Xc, -x+Yc);
}
void DrawCircle(){

int p, x, y  ;

p = 1-r;
x = 0; y = r;



while(x<=y){
    x = x+1;
    if(p<0){
        p = p+2*x+1;
    }
    else{
        y = y-1;
        p = p+2*x-2*y + 1;
    }
   Draw(x,y);
}
glEnd();
glFlush();
}


void myInit() {
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("PRANAWA K.C!!");
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
cout<<"Enter the center for xc : ";
cin>>Xc;

cout<<"Enter the center for yc : ";
cin>>Yc;
cout<<"Enter the radius of a circle: ";
cin>>r;
    myInit();
    glutDisplayFunc(DrawCircle);
    glutMainLoop();
    return 0;
}
