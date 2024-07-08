#include "object.h"
bool Object::CheckCollisionWith(Object n1){
    bool collisionX = this->x + this->width >= n1.x &&
        n1.x + n1.width >= this->x;

    bool collisionY = this->y + this->hight >= n1.y &&
        n1.y + n1.hight >= this->y;

    return collisionX && collisionY;
}
