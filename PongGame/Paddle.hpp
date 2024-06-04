#ifndef DEF_PADDLE
#define DEF_PADDLE

#include <iostream>

class Paddle{
protected:
    void LimitMovement();
public:
    Paddle();
    Paddle(float x, float y, float width, float height, int speedX);
    void update();
    void draw();
    void setX(float x);
    void setY(float y);
    float getX();
    float getY();
    float getWidth();
    float getHeight();
    float getSpeed();
    int getScore();
    void setScore(int x);
private:
    float m_x, m_y;
    float m_width, m_height;
    int m_speed;
    int m_score;
};

#endif