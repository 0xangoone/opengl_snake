#include "snake.h"
#include <memory>


#define node_width 0.05
#define node_hight 0.09
SnakeNode::SnakeNode(float x,float y){
    this->x = x;
    this->y=y;
    this->width = node_width;
    this->hight = node_hight;
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
    for (int i = 0;i<3;++i){
        SnakeNode* n = new SnakeNode(0,0);
        this->head->push_to_tail(n);
    }
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
                cur_y = cur_y+node_hight;
                break;
            case Direction::down:
                draw_square(cur_x ,cur_y-node_hight,node_width,node_hight,*c);
                cur_y = cur_y-node_hight;
                break;
            case Direction::left:
                draw_square(cur_x-node_width ,cur_y,node_width,node_hight,*c);
                cur_x=cur_x-node_width;
                break;
            case Direction::right:
                draw_square(cur_x+node_width ,cur_y,node_width,node_hight,*c);
                cur_x = cur_x+node_width;
                break;
            default:
                cur_x=node->x;
                cur_y=node->y;
                break;
        };
        if(node->next_node == nullptr){
            return;
        }
        node = node->next_node;
        //     -----(draw_square(float x,float y,float width, float hight,Rgb color))-----
    }while(node->next_node != nullptr);
}
void Snake::move(Direction d){
    if (this->head == nullptr){
        return;
    }
    if(d == this->head->dir){
        SnakeNode* node = this->head;
        while(node->next_node != nullptr && node->dir == d){
            node = node->next_node;
        }
        if (node->dir != d){
            node->dir = d;
        }
    }
    /*else{
        this->change_dir(d);
    }*/
    switch (d)
    {
        case Direction::up:
            this->head->y += node_hight;
            break;
        case Direction::down:
            this->head->y -= node_hight;
            break;
        case Direction::left:
            this->head->x -= node_width;
            break;
        case Direction::right:
            this->head->x += node_width;
            break;
        default:
            break;
    }
    std::cout <<"x: " << this->head->x<<std::endl;
    std::cout <<"y: " << this->head->y<<std::endl;
}  
void Snake::grow(){
    SnakeNode* n = new SnakeNode(0,0);
    this->head->push_to_tail(n);
}