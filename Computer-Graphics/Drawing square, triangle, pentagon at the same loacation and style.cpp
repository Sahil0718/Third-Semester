#include <GL/glut.h>

void drawPolygons()
{
    glClearColor(0,0,0,0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
     glColor3d(1, 0, 0); // Red color
    glVertex2f(-0.5,0.1);
    glVertex2f(-0.5,0.5);
    glVertex2f(0.1,0.5);
    glVertex2f(0.1,0.1);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3d(0, 0, 1); // Blue color
    glVertex2f(-0.21,-0.1);

    glVertex2f(0.1,0.3);
    glVertex2f(0.55,-0.1);
    glEnd();

    glFlush();


   glBegin(GL_POLYGON);//green color
    glColor3d(0,1,0);

   glVertex2f(0.4,-0.4);
    glVertex2f(0.18,-0.18);
    glVertex2f(0.35,0.1);
    glVertex2f(0.68,0.1);
    glVertex2f(0.85,-0.18);
    glVertex2f(0.7,-0.4);

    glEnd();

    glFlush();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lab 2");

    glutDisplayFunc(drawPolygons);
    glutMainLoop();

    return 0;
}
