#include <iostream>
#include <raylib.h>
#include "Ball.h"
using namespace std;

int main(){
    cout << "Starting the game" << endl;

    const int screen_width = 1280;
    const int screen_height = 800;

    Ball ball;
    ball.setRadius(20);
    ball.setX(screen_width/2);
    ball.setY(screen_height/2);
    InitWindow(screen_width, screen_height, "My Pong Game");
    SetTargetFPS(60);
    while(WindowShouldClose() == false){
        BeginDrawing();
        

        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);
        ball.Draw();

        DrawRectangle(10, screen_height/2-60, 25, 120, WHITE);
        DrawRectangle(screen_width-35, screen_height/2-60, 25, 120, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}