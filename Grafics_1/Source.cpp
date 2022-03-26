#include "GL/glew.h"
#include "GL/freeglut.h"
#include <stdio.h>
#include <stdlib.h>
#include "GL/glut.h"
#include <glm/glm.hpp>
#include "glm/vec2.hpp"

using namespace glm;

GLuint VBO;

void Display(void)
{
  //  glClear(GL_COLOR_BUFFER_BIT);
  //  glClearColor(0.9f, 0.5f, 0.5f, 0.0f);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glDisableVertexAttribArray(0);
    glutSwapBuffers();

}




int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 01");
    glutDisplayFunc(Display); 
    
    //glutDisplayFunc();

    GLenum res = glewInit();
    if (res != GLEW_OK)
    {
        fprintf(stderr, "Error: '%s'\n", glewGetErrorString(res));
        return 1;
    }
    vec3 Vertices[3];
    Vertices[0] = vec3(1.0f, 1.0f, 0.0f);
    Vertices[1] = vec3(-1.0f, 0.0f, 0.0f);
    Vertices[2] = vec3(1.0f, -1.0f, 0.0f);
    glGenBuffers(1, &VBO); //функций для генерации
    glBindBuffer(GL_ARRAY_BUFFER, VBO); 
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertices), Vertices, GL_STATIC_DRAW);
  
    glutMainLoop();
}

