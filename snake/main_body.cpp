#include "main_body.h"

void initGame()
{
    int winHeight = 720;
    int winWidth = 1280;

    InitWindow(winWidth, winHeight, "Snake");
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {

        BeginDrawing();

        ClearBackground(BLACK);

        DrawFPS(10, 10);
        EndDrawing();
    }
}
