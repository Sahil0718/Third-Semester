#include <GL/glut.h> 
#include <cstdlib> 
#include <ctime> 
 
   int width = 800, height = 600 ; 
    void Point() { 
    glClearColor(0, 0, 0, 0); 
    glClear(GL_COLOR_BUFFER_BIT); 
    glPointSize(4); 
    glColor3d(1, 1, 1); 
    glBegin(GL_POINTS); 
    int x, y; 
    for (int i = 0; i < 50; i++) { 
        x = rand() % width; 
        y = rand() % height; 
        glVertex2i(x, y); 
    } 
    glEnd(); 
    glFlush(); 
    } 
 
    void myInit() { 
    glutInitWindowSize(width, height); 
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); 
    glutCreateWindow("PRANAWA"); 
    glutDisplayFunc(Point); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(0, width, 0, height); 
    glMatrixMode(GL_MODELVIEW); 
    } 
 
    int main(int argc, char **argv) { 
    glutInit(&argc, argv); 
    myInit(); 
    glutMainLoop(); 
    return 0; 
    }
