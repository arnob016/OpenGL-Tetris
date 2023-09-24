#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <GL/gl.h>

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-150.0, 150.0, -150.0, 150.0);
}

void DrawBlock(float x, float y, float r, float g, float b)
{
    glPushMatrix();
    glTranslatef(x, y, 0.0);

    float topShade = 0.25;
    float rightShade = 0.1;
    float bottomShade = 0.3;
    float leftShade = 0.17;

    glColor3f(r - topShade, g - topShade, b - topShade);
    glBegin(GL_TRIANGLES);
    glVertex2f(5.0, -5.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(5.0, 5.0);
    glEnd();

    glColor3f(r - rightShade, g - rightShade, b - rightShade);
    glBegin(GL_TRIANGLES);
    glVertex2f(-5.0, -5.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(5.0, -5.0);
    glEnd();

    glColor3f(r - bottomShade, g - bottomShade, b - bottomShade);
    glBegin(GL_TRIANGLES);
    glVertex2f(-5.0, 5.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(5.0, 5.0);
    glEnd();

    glColor3f(r - leftShade, g - leftShade, b - leftShade);
    glBegin(GL_TRIANGLES);
    glVertex2f(-5.0, 5.0);
    glVertex2f(0.0, 0.0);
    glVertex2f(-5.0, -5.0);
    glEnd();

    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(-2.5, -2.5);
    glVertex2f(-2.5, 2.5);
    glVertex2f(2.5, 2.5);
    glVertex2f(2.5, -2.5);
    glEnd();

    glPopMatrix();
}

void DrawShapeLL(float x, float y, float r, float g, float b)
{
    DrawBlock(x, y, r, g, b);
    DrawBlock(x, y - 10.0, r, g, b);
    DrawBlock(x, y - 20.0, r, g, b);
    DrawBlock(x + 10.0, y - 20.0, r, g, b);
}

void DrawShapeLJ(float x, float y, float r, float g, float b)
{
    DrawBlock(x, y, r, g, b);
    DrawBlock(x, y - 10.0, r, g, b);
    DrawBlock(x, y - 20.0, r, g, b);
    DrawBlock(x - 10.0, y - 20.0, r, g, b);
}

void DrawShapeTU(float x, float y, float r, float g, float b)
{
    DrawBlock(x, y, r, g, b);
    DrawBlock(x - 10.0, y, r, g, b);
    DrawBlock(x + 10.0, y, r, g, b);
    DrawBlock(x, y + 20.0, r, g, b);
    DrawBlock(x, y + 10.0, r, g, b);
}

void DrawShapeTD(float x, float y, float r, float g, float b)
{
    DrawBlock(x, y, r, g, b);
    DrawBlock(x - 10.0, y, r, g, b);
    DrawBlock(x + 10.0, y, r, g, b);
    DrawBlock(x, y - 20.0, r, g, b);
    DrawBlock(x, y - 10.0, r, g, b);
}

void DrawShapeII(float x, float y, float r, float g, float b)
{
    DrawBlock(x, y + 10.0, r, g, b);
    DrawBlock(x, y, r, g, b);
    DrawBlock(x, y - 10.0, r, g, b);
    DrawBlock(x, y - 20.0, r, g, b);
}

void DrawShapeSQ(float x, float y, float r, float g, float b)
{
    DrawBlock(x, y, r, g, b);
    DrawBlock(x, y - 10.0, r, g, b);
    DrawBlock(x - 10.0, y - 10.0, r, g, b);
    DrawBlock(x - 10.0, y, r, g, b);
}

void DrawShapeZZ(float x, float y, float r, float g, float b)
{
    DrawBlock(x - 10.0, y, r, g, b);
    DrawBlock(x, y, r, g, b);
    DrawBlock(x, y - 10.0, r, g, b);
    DrawBlock(x + 10.0, y - 10.0, r, g, b);
}

void DrawShapeZR(float x, float y, float r, float g, float b)
{
    DrawBlock(x + 10.0, y, r, g, b);
    DrawBlock(x, y, r, g, b);
    DrawBlock(x, y - 10, r, g, b);
    DrawBlock(x - 10, y - 10, r, g, b);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    DrawShapeLL(0.0, 0.0, 1.0, 0.0, 0.0);
    DrawShapeLJ(-100.0, 60.0, 0.8, 0.6, 0.4);
    DrawShapeZZ(-100.0, -30.0, 1.0, 0.5, 0.5);
    DrawShapeZR(70.0, -80.0, 0.0, 0.8, 0.0);
    DrawShapeTU(50.0, 50.0, 0.0, 1.0, 1.0);
    DrawShapeTD(40.0, 10.0, 1.0, 0.5, 0.0);
    DrawShapeSQ(-50.0, 50.0, 1.0, 1.0, 0.0);
    DrawShapeII(100.0, 10.0, 1.0, 0.0, 1.0);
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Tetris testing");
    init();
    glutDisplayFunc(Draw);
    glutMainLoop();
    return 0;
}
