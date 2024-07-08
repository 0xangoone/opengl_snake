#include <iostream>
#include "graphics.h"
#include "object.h"

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
