#include "CPUPaddle.hpp"
#include <raylib.h>
CPUPaddle::CPUPaddle(float x, float y, float w, float h, int speed) : Paddle(x, y, w, h, speed){

}

void CPUPaddle::update(float ball_y){
    float y = CPUPaddle::getY();
    float height = CPUPaddle::getHeight();
    int speed = CPUPaddle::getSpeed();
    if(y + height/2 > ball_y){
        CPUPaddle::setY(y - speed);
    }
    if(y + height/2 <= ball_y){
        CPUPaddle::setY(y + speed);
    }

    CPUPaddle::LimitMovement();
}