#include <GL/glut.h>

void init() {
    glEnable(GL_DEPTH_TEST); // Enable depth test
    glClearColor(1.0, 1.0, 1.0, 1.0); // White background
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 10.0); // Perspective view
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    // Red small quad (farther)
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0); // Z = -5
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.3, -0.3, 0.0);
        glVertex3f( 0.3, -0.3, 0.0);
        glVertex3f( 0.3,  0.3, 0.0);
        glVertex3f(-0.3,  0.3, 0.0);
    glEnd();

    // Green small quad (closer)
    glLoadIdentity();
    glTranslatef(-0.1, -0.1, -3.0); // Z = -3
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
        glVertex3f(-0.2, -0.2, 0.0);
        glVertex3f( 0.2, -0.2, 0.0);
        glVertex3f( 0.2,  0.2, 0.0);
        glVertex3f(-0.2,  0.2, 0.0);
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Depth Buffer ");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

