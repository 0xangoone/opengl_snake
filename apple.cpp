#include "apple.h"
#include <random>
#include <memory>
double generate_random_number() {
    std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);
    return dis(gen);
}

void Apple::spawn(){
    this->hight = apple_hight;
    this->width = apple_width;
    this->x = generate_random_number();
    this->y = generate_random_number();
}
void Apple::draw(){
    std::unique_ptr<Rgb> color(new Rgb(0.0,0.0,1.0));
    draw_square(this->x,this->y,apple_width,apple_hight,*color);
}