#include "init.h"

void initGame()
{
    int winHeight = 720;
    int winWidth = 1280;

    InitWindow(winWidth, winHeight, "Snake");
    SetTargetFPS(60);

    Snake::snake snake(winWidth, winHeight, 25.0f);

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);

        drawMap(winWidth, winHeight, 5.0f, GRAY);
        snake.draw();

        DrawFPS(10, 10);
        EndDrawing();
    }
}

void drawMap(int w, int h, float line, Color color)
{
    Rectangle rec;
    rec.height = static_cast<float>(h)-100;
    rec.width = static_cast<float>(w)-200;
    rec.x = static_cast<float>(w)/2-rec.width/2;
    rec.y = static_cast<float>(h)/2-rec.height/2;


    DrawRectangleLinesEx(rec, line, color);
}
