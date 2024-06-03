#ifndef DEF_CPUPADDLE
#define DEF_CPUPADDLE
#include "Paddle.hpp"
class Paddle;
class CPUPaddle : public Paddle{
public:
    CPUPaddle(float x, float y, float w, float h, int speed);
    void update(float ball_y);
};


#endif