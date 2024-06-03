#include <iostream>
#include <raylib.h>
#include "Ball.hpp"
#include "Paddle.hpp"
#include "CPUPaddle.hpp"
#include "Score.hpp"

using namespace std;

int main(){
    Score score(0, 0);
    cout << "Starting the game" << endl;

    const int screen_width = 1280;
    const int screen_height = 800;

    Ball ball(screen_width/2, screen_height/2, 7, 7, 20);
    Paddle player(10, (screen_height/2-60), 25, 120, 15);
    CPUPaddle bot(screen_width-35, screen_height/2-60, 25, 120, 7);

    

    InitWindow(screen_width, screen_height, "My Pong Game");
    SetTargetFPS(60);
    while(WindowShouldClose() == false){
        BeginDrawing();
        ClearBackground(BLACK);
        //update
        ball.update();
        player.update();
        bot.update(ball.getY());


        //Check for collisions;
        if(CheckCollisionCircleRec(Vector2{ball.getX(), ball.getY()}, ball.getRadius(), 
                                   Rectangle{player.getX(), player.getY(), player.getWidth(), player.getHeight()})){
            ball.setSpeedX(-1*ball.getSpeedX());
            score.setCPuScore(score.getCPUScore() + 1);
        }
        if(CheckCollisionCircleRec(Vector2{ball.getX(), ball.getY()}, ball.getRadius(), 
                                   Rectangle{bot.getX(), bot.getY(), bot.getWidth(), bot.getHeight()})){
            ball.setSpeedX(-1*ball.getSpeedX());
            score.setPlayerScore(score.getPlayerScore() + 1);
            
        }
        //draw    
        player.draw();
        bot.draw();
        DrawLine(screen_width/2, 0, screen_width/2, screen_height, WHITE);
        DrawCircle(screen_width/2, screen_height/2, 100, GRAY);
        ball.Draw();
        
        //DrawRectangle(10, screen_height/2-60, 25, 120, WHITE);
        //DrawRectangle(screen_width-35, screen_height/2-60, 25, 120, WHITE);

        DrawText(TextFormat("%i", score.getPlayerScore()), screen_width/4-20, 20, 80, WHITE);
        DrawText(TextFormat("%i", score.getCPUScore()), 3*screen_width/4 - 20, 20, 80, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}