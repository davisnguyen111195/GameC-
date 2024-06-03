#include "Ball.h"


Ball::Ball(){

}

Ball::~Ball(){
    
}

Ball::Ball(float x, float y) : m_x(x), m_y(y){

}

void Ball::Draw(){
    DrawCircle(m_x, m_y, m_radius, WHITE);
}

void Ball::setRadius(float radius){
    m_radius = radius;
}


void Ball::setX(float x){
    m_x = x;
}

void Ball::setY(float y){
    m_y = y;
}