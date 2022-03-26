#include "GL/freeglut.h"
#include <stdio.h>
#include <stdlib.h>
#include "GL/glut.h"
#include <glm/glm.hpp>

using namespace glm;

void Display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.9f, 0.5f, 0.5f, 0.0f);
    glutSwapBuffers();

}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 01");
    glutDisplayFunc(Display); 
    
    glutMainLoop();
}

