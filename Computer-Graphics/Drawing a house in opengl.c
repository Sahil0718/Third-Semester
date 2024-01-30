#include <GL/glut.h>

void draw(){
glClearColor(1,1,1,1);    //color of background
glClear(GL_COLOR_BUFFER_BIT); //background buffer
glLineWidth(3);   //line width

glBegin(GL_TRIANGLES);  //define the shape
glColor3f(1.0,0.0,0.0);  //color of the shape
glVertex2f(0.5,0.5);
glVertex2f(-0.5,0.5);
glVertex2f(0,0.9);
glEnd();   //shape function ends

glBegin(GL_QUADS); //main
glColor3f(0.0,1.1,0.0);
glVertex2f(0.5,-0.4);
glVertex2f(-0.5,-0.4);
glVertex2f(-0.5,0.5);
glVertex2f(0.5,0.5);
glEnd();

glBegin(GL_QUADS);
glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
glVertex2f(-0.1,0.1);
glVertex2f(-0.4,0.1);
glVertex2f(-0.4,0.4);
glVertex2f(-0.1,0.4);
glEnd();


glBegin(GL_QUADS);
glColor4f(0.0f, 1.0f, 1.0f, 1.0f);
glVertex2f(0.4,0.1);
glVertex2f(0.1,0.1);
glVertex2f(0.1,0.4);
glVertex2f(0.4,0.4);
glEnd();

glBegin(GL_QUADS);
glColor3f(0.1f, 0.0f, 0.0f);
glVertex2f(-0.1,-0.38);
glVertex2f(-0.1,0);
glVertex2f(0.1,0);
glVertex2f(0.1,-0.38);
glEnd();

glFlush();
}
int main(int argc, char *argv[]){  //driver code
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB);  //colorful
glutInitWindowPosition(100,100); //position of the window
glutInitWindowSize(800,600);
glutCreateWindow("LABWORK 3");
glutDisplayFunc(draw);
glutMainLoop();

}
