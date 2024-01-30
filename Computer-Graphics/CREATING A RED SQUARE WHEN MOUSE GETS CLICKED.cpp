#include <GL/glut.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int mouseX = 0;
int mouseY = 0;
bool isMouseClicked = false;

void mouseClick(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        mouseX = x;
        mouseY = WINDOW_HEIGHT - y;
        isMouseClicked = true;
    }
}

void drawBox()
{
    glClear(GL_COLOR_BUFFER_BIT);

    if (isMouseClicked)
    {
        glColor3f(1.0f, 0.0f, 0.0f);
        int boxLeft = mouseX - 50;
        int boxRight = mouseX + 50;
        int boxBottom = mouseY - 50;
        int boxTop = mouseY + 50;

        glBegin(GL_QUADS);
        glVertex2i(boxLeft, boxBottom);
        glVertex2i(boxRight, boxBottom);
        glVertex2i(boxRight, boxTop);
        glVertex2i(boxLeft, boxTop);
        glEnd();
    }

    glFlush();
}

void reshape(int width, int height)
{
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, width, 0, height, -1, 1);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutCreateWindow("OpenGL Box Creation");
    glutDisplayFunc(drawBox);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseClick);
    glutMainLoop();

    return 0;
}
