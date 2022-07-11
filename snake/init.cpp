#include "init.h"

void initGame()
{
    int winWidth = 1280;
    int winHeight = 720;

    float mapWidth = static_cast<float>(winWidth)-200;
    float mapHeight = static_cast<float>(winHeight)-100;
    float mapX = static_cast<float>(winWidth)/2-mapWidth/2;
    float mapY = static_cast<float>(winHeight)/2-mapHeight/2;

    InitWindow(winWidth, winHeight, "Snake");
    SetTargetFPS(60);

    int score = 0;
    std::string textScore;

    float snakeSize = 25.0f;

    bool canMove = false;
    bool add = false;

    float timePassed = 0.0f;
    float timeSpeed = 0.8f;

    Vector2 speed{-snakeSize, 0};
    direction dir = DIR_LEFT;

    map map(mapX, mapY, Vector2{mapWidth, mapHeight}, GRAY);
    Snake::snake snake(winWidth, winHeight, snakeSize);
    Food::food food(200, 200, snakeSize, YELLOW);

    while (!WindowShouldClose())
    {
        if (canMove)
            checkKeys(snakeSize, speed, canMove, dir);

        if (IsKeyPressed(KEY_A))
            snake.add(dir);

        timePassed += GetFrameTime();
        if (timePassed >= timeSpeed)
        {
            canMove = true;
            timePassed = 0.0f;
            snake.move(speed);

            if (snake.foodHeadCollision(food))
            {
                ++score;
                snake.add(dir);


                timeSpeed -= timeSpeed*0.1f;
            }
        }

        BeginDrawing();
        ClearBackground(BLACK);

        map.draw();
        snake.draw();
        food.draw();

        textScore = TextFormat("Score: %i", score);
        DrawText(textScore.c_str(), winWidth/2-MeasureText(textScore.c_str(), 20), 5, 20, LIGHTGRAY);

        DrawFPS(10, 10);
        EndDrawing();
    }
}

inline void drawMap(int w, int h, float line, Color color)
{
    Rectangle rec;
    rec.height = static_cast<float>(h)-100;
    rec.width = static_cast<float>(w)-200;
    rec.x = static_cast<float>(w)/2-rec.width/2;
    rec.y = static_cast<float>(h)/2-rec.height/2;

    DrawRectangleLinesEx(rec, line, color);
}

void checkKeys(float &size, Vector2 &speed, bool &canMove, direction &dir)
{

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
