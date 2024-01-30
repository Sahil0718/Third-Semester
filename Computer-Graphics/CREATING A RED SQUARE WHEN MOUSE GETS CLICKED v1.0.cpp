#include <GL/glut.h>

void draw(int button , int state, int x, int y){
int width = 100;
int height = 50;

glLineWidth(3);
glBegin(GL_QUADS);
glColor3d(1,0,0);
glVertex2i(x,y);
glVertex2i(x+width, y);
glVertex2i(x+width , y+height);
glVertex2i(x, y+height);

glEnd();
glFlush();

}
void Display(){
glClearColor(1,1,1,1); //background color set to white
glClear(GL_COLOR_BUFFER_BIT);
glFlush();
}


void myInit(){
    glutInitWindowSize(800,600);
    glutInitWindowPosition(50,50);
    glutInitDisplayMode(GLUT_RGB);
    glutCreateWindow("CREATING A BOX ON MOUSE CLICK!");
    glutDisplayFunc(Display);
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,0,400);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc , char *argv[]){
    glutInit(&argc, argv);
    myInit();
    glutMouseFunc(draw);
    glutMainLoop();

}

