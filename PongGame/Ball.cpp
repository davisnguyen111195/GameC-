#include "Ball.hpp"
#include <raylib.h>

//Contructor
Ball::Ball(){

}

Ball::Ball(float x, float y, int radius) : m_x(x), m_y(y), m_radius(radius){

}

Ball::Ball(float x, float y, int speed_x, int speed_y, int radius) : m_x(x), 
                                                                     m_y(y), 
                                                                     m_speed_x(speed_x), 
                                                                     m_speed_y(speed_y), 
                                                                     m_radius(radius){

}

//Detructor
Ball::~Ball(){
    
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

void Ball::update(){
    m_x += m_speed_x;
    m_y += m_speed_y;

    if(m_x + m_radius >= GetScreenWidth() || m_x - m_radius <= 0){
        m_speed_x *= -1;
    }

    if(m_y + m_radius >= GetScreenHeight() || m_y - m_radius <= 0){
        m_speed_y *= -1;
    }
}

float Ball::getY(){
    return m_y;
}
float Ball::getX(){
    return m_x;
}

int Ball::getRadius(){
    return m_radius;
}

int Ball::getSpeedX(){
    return m_speed_x;
}

int Ball::getSpeedY(){
    return m_speed_y;
}

void Ball::setSpeedX(int x){
    m_speed_x = x;
}

void Ball::setSpeedY(int y){
    m_speed_y = y;
}