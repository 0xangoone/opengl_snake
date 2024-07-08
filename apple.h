#include "graphics.h"
#include "object.h"

#define apple_width 0.05
#define apple_hight 0.05
class Apple: public Object{
public:
    void spawn();
    void draw();
};
