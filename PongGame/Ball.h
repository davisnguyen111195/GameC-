#ifndef DEF_BALL
#define DEF_BALL
#include <iostream>
#include <raylib.h>

class Ball{
public:
    Ball();
    Ball(float x, float y);
    ~Ball();
    void Draw();
    void setRadius(float radius);
    void setX(float x);
    void setY(float y);
private:
    float m_x, m_y;
    int m_speed_x, m_speed_y;
    int m_radius;

};
#endif