#include "Paddle.hpp"
#include <raylib.h>


Paddle::Paddle(){

}

Paddle::Paddle(float x, float y, float width, float height, int speed) : m_x(x),
                                                                       m_y(y),
                                                                       m_width(width),
                                                                       m_height(height),
                                                                       m_speed(speed){

}

void Paddle::update(){
    if(IsKeyDown(KEY_UP)){
        m_y -= m_speed;
    } 

    if(IsKeyDown(KEY_DOWN)){
        m_y += m_speed;
    }

    if(m_y + m_height >= GetScreenHeight()){
        m_y = GetScreenHeight() - m_height;
    } 
    
    if(m_y <= 0){
        m_y = 0;
    }
    LimitMovement();
}

void Paddle::draw(){
    DrawRectangle(m_x, m_y, m_width, m_height, WHITE);
}

void Paddle::setX(float x){
    m_x = x;
}

void Paddle::setY(float y){
    m_y = y;
}

float Paddle::getHeight(){
    return m_height;
}

float Paddle::getWidth(){
    return m_width;
}

float Paddle::getX(){
    return m_x;
}

float Paddle::getY(){
    return m_y;
}

float Paddle::getSpeed(){
    return m_speed;
}

void Paddle::LimitMovement(){
    if(m_y <= 0){
        m_y = 0;
    }

    if(m_y + m_height >= GetScreenHeight()){
        m_y = GetScreenHeight() - m_height;
    }
}