#include "snake.h"
#include <memory>
bool Object::CheckCollisionWith(Object n1){
    bool collisionX = this->x + node_hight >= n1.x &&
        n1.x + node_hight >= this->x;

    bool collisionY = this->y + node_hight >= n1.y &&
        n1.y + node_hight >= this->y;

    return collisionX && collisionY;
}



SnakeNode::SnakeNode(float x,float y){
    this->x = x;
    this->y=y;
    this->next_node = nullptr;
}
SnakeNode::~SnakeNode(){
    std::cout<<"a snake node was destroy!\n";
    delete this->next_node;
}
void SnakeNode::push_to_tail(SnakeNode *n){
    SnakeNode* node = this;
    while(node->next_node != nullptr){
        node = node->next_node;
    }
    node->next_node = n;
    node->next_node->dir = node->dir;
}



Snake::~Snake(){
    delete this->head;
}
Snake::Snake(float x,float y) {
    this->head = new SnakeNode(x,y);
}
void Snake::change_dir(Direction dir){
    this->head->dir = dir;
    this->last_dir_x=this->head->x;
    this->last_dir_y=this->head->y;
}
void Snake::draw(){
    if (this->head == nullptr){
        return;
    }
    SnakeNode* node = this->head;
    Direction last_dir = node->dir;
    float cur_x = this->head->x;
    float cur_y = this->head->y;
    do{
        last_dir = node->dir;
        std::unique_ptr<Rgb> c (new Rgb(0,1,0));
        switch (last_dir){
            case Direction::up:
                draw_square(cur_x ,cur_y+node_hight,node_width,node_hight,*c);
                break;
            case Direction::down:
                draw_square(cur_x ,cur_y-node_hight,node_width,node_hight,*c);
                break;
            case Direction::left:
                draw_square(cur_x-node_width ,cur_y,node_width,node_hight,*c);
                break;
            case Direction::right:
                draw_square(cur_x+node_width ,cur_y,node_width,node_hight,*c);
                break;
            default:
                break;
        };
        cur_x=node->x;
        cur_y=node->y;
        if(node->next_node == nullptr){
            return;
        }
        node = node->next_node;
        //     -----(draw_square(float x,float y,float width, float hight,Rgb color))-----
    }while(node->next_node != nullptr);
}
void Snake::move(Direction d){
    if(d == this->head->dir){
        SnakeNode* node = this->head;
        do{
            node = node->next_node;
        }while(node->next_node != nullptr && node->dir == d);
        if (node->dir != d){
            node->dir = d;
        }
    }
    else{
        this->change_dir(d);
    }

}
