#include <GL/glut.h>


// Square properties
float squareSize = 0.2;
float squarePositionX = 0.0;
float squarePositionY = 0.0;
float squareVelocityX = 0.01;
float squareVelocityY = 0.01;

void drawSquare() {
    glClearColor(0.0, 0.0, 0.0, 1.0); // Background color (black)
    glClear(GL_COLOR_BUFFER_BIT);     // Clear the color buffer

    glColor3f(0.0, 1.0, 1.0);  // Square color (white)

    // Draw the square
    glBegin(GL_QUADS);
    glVertex2f(squarePositionX, squarePositionY);
    glVertex2f(squarePositionX + squareSize, squarePositionY);
    glVertex2f(squarePositionX + squareSize, squarePositionY + squareSize);
    glVertex2f(squarePositionX, squarePositionY + squareSize);
    glEnd();

    glutSwapBuffers();  // Swap the front and back buffers
}

void update(int value) {
    // Update square position
    squarePositionX += squareVelocityX;
    squarePositionY += squareVelocityY;

    // Check for collision with window edges
    if (squarePositionX > 1.0 - squareSize || squarePositionX < -1.0)
        squareVelocityX *= -1;

    if (squarePositionY > 1.0 - squareSize || squarePositionY < -1.0)
        squareVelocityY *= -1;

    glutPostRedisplay();  // Mark the current window as needing to be redisplayed
    glutTimerFunc(16, update, 0);  // Call the update function again after 16 milliseconds (about 60 frames per second)
}

int main(int argc, char *argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Bouncing Square");
    glutDisplayFunc(drawSquare);
    glutTimerFunc(0, update, 0);
    glutMainLoop();

    return 0;
}
