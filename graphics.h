#include <GL/glut.h>
class Rgb{
    public:
        Rgb(float red ,float green,float blue) ;
        float get_red() const;
        float get_green() const;
        float get_blue() const;
    private:
        float red;
        float green;
        float blue;
};
extern "C" void draw_square(float x,float y,float width, float hight,Rgb color);