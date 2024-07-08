#include <GL/glut.h>
#include <memory>
#include <iostream>
#include "snake.h"

float px = -0.5;
float py = -0.5;
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    Snake *s = new Snake(-0.5,-0.5);

    s->draw();

    delete s;

    glEnd();
    glFlush();
}
void normal_key_handle(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
            py+=0.1;
            break;
        case GLUT_KEY_DOWN:
            py-=0.1;
            break;
        case GLUT_KEY_LEFT:
            px-=0.1;
            break;
        case GLUT_KEY_RIGHT:
            px+=0.1;
            break;
        default:
            break;
    }
    glutPostRedisplay();
}
void special_key_handle(unsigned char key,int x ,int y){
    switch(key){
        default:
            break;
    }
}
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("snake game");
    glutSpecialFunc(normal_key_handle );
    glutKeyboardFunc(special_key_handle);
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
