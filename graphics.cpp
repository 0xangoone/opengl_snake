#include "graphics.h"
Rgb::Rgb(float red,float green,float blue){
    this->red = red;
    this->blue = blue;
    this->green = green;
}
float Rgb::get_blue() const {return this->blue;}
float Rgb::get_red() const {return this->red;}
float Rgb::get_green() const {return this->green;}
extern "C" void draw_square(float x,float y,float width, float hight,Rgb color){
    glBegin(GL_POLYGON);

    glColor3f(color.get_red(),color.get_green(),color.get_blue());
    glVertex2f(x,y);
    glVertex2f(x+width,y);
    glVertex2f(x+width,y - hight);
    glVertex2f(x,y-hight);


    glEnd();
    glFlush();
}