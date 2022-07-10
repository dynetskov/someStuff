#include "init.h"

void initGame()
{
    int winHeight = 720;
    int winWidth = 1280;

    InitWindow(winWidth, winHeight, "Snake");
    SetTargetFPS(60);

    float snakeSize = 25.0f;
    Vector2 speed{-snakeSize, 0};
    bool canMove = false;
    float timePassed = 0.0f;

    Snake::snake snake(winWidth, winHeight, snakeSize);

    while (!WindowShouldClose())
    {
        if (canMove)
            checkDir(snakeSize, speed, canMove);

        timePassed += GetFrameTime();
        if (timePassed >= 1.5f)
        {
            canMove = true;
            snake.move(speed);
            timePassed = 0.0f;
        }

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

void checkDir(float &size, Vector2 &speed, bool &canMove)
{
    static direction dir = DIR_LEFT;

    if ((dir != DIR_RIGHT) && (dir != DIR_LEFT))
    {
        if (IsKeyPressed(KEY_LEFT))
        {
            dir = DIR_LEFT;
            canMove = false;
        } else if (IsKeyPressed(KEY_RIGHT))
        {
            dir = DIR_RIGHT;
            canMove = false;
        }
    } else if ((dir != DIR_DOWN) && (dir != DIR_UP))
    {
        if (IsKeyPressed(KEY_UP))
        {
            dir = DIR_UP;
            canMove = false;
        } else if (IsKeyPressed(KEY_DOWN))
        {
            dir = DIR_DOWN;
            canMove = false;
        }
    }

    switch (dir)
    {
        case DIR_UP:
            speed.x = 0;
            speed.y = -size;
            break;
        case DIR_DOWN:
            speed.x = 0;
            speed.y = size;
            break;
        case DIR_LEFT:
            speed.x = -size;
            speed.y = 0;
            break;
        case DIR_RIGHT:
            speed.x = size;
            speed.y = 0;
            break;
    }
}
