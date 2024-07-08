#include <GL/glut.h>
#include <memory>
#include <iostream>
#include <thread>
#include <chrono>
#include "snake.h"
#include "apple.h"

std::shared_ptr<Snake> snake(new Snake(-0.5,-0.5));
Apple apple;
Direction cur_dir = Direction::up;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);


    snake->draw();
    apple.draw();
    snake->move(cur_dir);
    if(snake->head->CheckCollisionWith(apple) == true){
        snake->grow();
        apple.spawn();
    }

    glEnd();
    glFlush();
    std::this_thread::sleep_for (std::chrono::milliseconds(200));
    glutPostRedisplay();
}
void normal_key_handle(int key, int x, int y){
    switch(key){
        case GLUT_KEY_UP:
            cur_dir = Direction::up;
            snake->change_dir(Direction::up);
            break;
        case GLUT_KEY_DOWN:
            cur_dir = Direction::down;
            snake->change_dir(Direction::down);
            break;
        case GLUT_KEY_LEFT:
            cur_dir = Direction::left;
            snake->change_dir(Direction::left);
            break;
        case GLUT_KEY_RIGHT:
            cur_dir = Direction::right;
            snake->change_dir(Direction::right);
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
