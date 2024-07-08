#include <iostream>
#include "graphics.h"
enum Direction {
    up,
    down,
    right,
    left,
};
class Object{
public:
    float x;
    float y;
    bool CheckCollisionWith(Object n2);
};
#define node_width 0.2
#define node_hight 0.2
class SnakeNode : public Object{
public:
    SnakeNode(float x,float y);
    ~SnakeNode();
    void push_to_tail(SnakeNode *n);
    Direction dir;
    SnakeNode* next_node;
};

class Snake{
public:
    SnakeNode* head;
    void grow();
    void draw();
    void move(Direction d);
    void change_dir(Direction dir);
    Snake(float x,float y);
    ~Snake();
private:
    int last_dir_x;
    int last_dir_y;
};
