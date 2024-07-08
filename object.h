#ifndef OBJECT_H
#define OBJECT_H

enum Direction {
    up,
    down,
    right,
    left,
};
class Object{
public:
    float hight;
    float width;
    float x;
    float y;
    bool CheckCollisionWith(Object n2);
};

#endif
