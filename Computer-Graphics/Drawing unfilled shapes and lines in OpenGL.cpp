#include <GL/glut.h>

void drawshapes()
{

    // For rendering the line
    glLineWidth(3);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 1, 1);
    glBegin(GL_LINES);
    glVertex2f(-0.5f, -0.5f);
    glVertex2f(0.5f, -0.5f);
    glEnd();

    // For rendering triangle
    glLineWidth(3);
    glColor3d(1, 0, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.25f, 0.25f);
    glVertex2f(0.25f, 0.25f);
    glVertex2f(0.0f, 0.75f);
    glEnd();

    // For rendering rectangle
    glLineWidth(3);
    glColor3d(0, 0, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-0.75f, -0.25f);
    glVertex2f(-0.75f, 0.25f);
    glVertex2f(-0.5f, 0.25f);
    glVertex2f(-0.5f, -0.25f);
    glEnd();

    // For rendering the hexagon
    glLineWidth(3);
    glColor3d(1, 1, 0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0.25f, -0.125f);
    glVertex2f(0.375f, -0.25f);
    glVertex2f(0.625f, -0.25f);
    glVertex2f(0.75f, -0.125f);
    glVertex2f(0.625f, 0.0f);
    glVertex2f(0.375f, 0.0f);
    glEnd();

    glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DRAWING SHPAES!");
    glutDisplayFunc(drawshapes);
    glutMainLoop();
    return 0;
}
