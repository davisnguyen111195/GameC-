#ifndef DEF_BALL
#define DEF_BALL
#include <iostream>
#include <raylib.h>
#include "Score.hpp"
class Ball{


public:
    
    Ball();
    Ball(float x, float y, int m_radius);
    Ball(float x, float y, int speed_x, int speed_y, int radius);
    ~Ball();
    void Draw();
    void setRadius(float radius);
    int getRadius();
    void setX(float x);
    void setY(float y);
    float getY();
    float getX();
    void update();
    int getSpeedX();
    int getSpeedY();
    void setSpeedX(int speed_x);
    void setSpeedY(int speed_y);
    void resetBall();
    int getValueScoreCPU();
    int getValueScorePlayer();
private:
    float m_x, m_y;
    int m_speed_x, m_speed_y;
    int m_radius;
    Score m_score;
};

#endif