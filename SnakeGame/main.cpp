#include <iostream>
#include <raylib.h>

using namespace std;

const int screen_width = 750;
const int screen_height = 750;
Color green{173, 204, 96, 255};
Color darkGreen{43, 51, 24, 255};
int main(){
    cout << "Starting the game..." << endl;
    InitWindow(screen_width, screen_height, "Snake");
    SetTargetFPS(60);
    while(WindowShouldClose() == false){
        BeginDrawing();

        ClearBackground(green);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}