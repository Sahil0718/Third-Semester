#include <GL/glut.h>
#include <iostream>
using namespace std;

int xc, yc, a, b;
int WIN_WIDTH = 800;
int WIN_HEIGHT = 600;

void DrawEllipse(int x, int y) {
    glBegin(GL_POINTS);
    glPointSize(9);
    glVertex2i(xc + x, yc + y);
    glVertex2i(xc + x, yc - y);
    glVertex2i(xc - x, yc + y);
    glVertex2i(xc - x, yc - y);
    glEnd();
}

void Draw() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the buffer at the beginning of each frame

    glColor3b(0, 0, 0);
    int a_square = a * a;
    int b_square = b * b;
    int p = b_square - a_square * b + (a_square / 4); // Initial decision parameter

    int x = 0, y = b;

    DrawEllipse(x, y);

    // Region 1
    while (2 * b_square * x < 2 * a_square * y) {
        x++;
        if (p < 0)
            p += 2 * b_square * x + b_square;
        else {
            y--;
            p += 2 * b_square * x - 2 * a_square * y + b_square;
        }
        DrawEllipse(x, y);
    }

    // Region 2
    p = b_square * (x + 0.5) * (x + 0.5) + a_square * (y - 1) * (y - 1) - a_square * b_square;
    while (y > 0) {
        y--;
        if (p > 0)
            p += -2 * a_square * y + a_square;
        else {
            x++;
            p += 2 * b_square * x - 2 * a_square * y + a_square;
        }
        DrawEllipse(x, y);
    }

    glFlush(); // Ensure all drawing commands are processed
}

void myInit() {
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("SAHIL BHATTARAI!!");
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIN_WIDTH, 0, WIN_HEIGHT);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    cout << "Enter the a and b : ";
    cin >> a >> b;
    cout << "Enter the center for Xc and Yc : ";
    cin >> xc >> yc;
    myInit();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
