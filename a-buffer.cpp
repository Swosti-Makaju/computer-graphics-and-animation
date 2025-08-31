#include <GL/glut.h>

// Draw 3 overlapping rectangles with transparency
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // First rectangle - background layer (light gray)
    glColor3f(0.75, 0.75, 0.75);  // Light gray
    glBegin(GL_QUADS);
        glVertex2f(0.1f, 0.1f);
        glVertex2f(0.5f, 0.1f);
        glVertex2f(0.5f, 0.5f);
        glVertex2f(0.1f, 0.5f);
    glEnd();

    // Enable blending for semi-transparent layer
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Second rectangle - semi-transparent (green)
    glColor4f(0.0, 0.7, 0.0, 0.4);  // Green with 40% opacity
    glBegin(GL_QUADS);
        glVertex2f(0.3f, 0.3f);
        glVertex2f(0.7f, 0.3f);
        glVertex2f(0.7f, 0.7f);
        glVertex2f(0.3f, 0.7f);
    glEnd();

    glDisable(GL_BLEND); // Turn off blending after use

    // Third rectangle - front outline (dark blue)
    glColor3f(0.0, 0.0, 0.4);  // Dark blue outline
    glBegin(GL_LINE_LOOP);
        glVertex2f(0.25f, 0.25f);
        glVertex2f(0.65f, 0.25f);
        glVertex2f(0.65f, 0.65f);
        glVertex2f(0.25f, 0.65f);
    glEnd();

    glFlush(); // Render now
}

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);  // Set background to white
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 1, 0, 1); // 2D projection from 0 to 1 in both X and Y
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Transparency with A-Buffer Technique");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

