#include <iostream>
#include <raylib.h>
#include "declare.h"
using namespace std;

Ball ball;
Paddle player;
CpuPaddle cpuPaddle;

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 860;

int player_score = 0;
int cpu_score = 0;

bool running = false;

void DrawObjects()
{
    ball.Draw();
    player.Draw();
    cpuPaddle.Draw();
}

void DrawTextGame()
{
    DrawText(TextFormat("%i", player_score), (SCREEN_WIDTH / 4) - 20, 20, 80, WHITE);
    DrawText(TextFormat("%i",cpu_score), 3*(SCREEN_WIDTH / 4) - 20, 20, 80, WHITE);
}

void DrawBackground()
{
    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, BLACK);
    DrawLine(SCREEN_WIDTH / 2, 0, SCREEN_WIDTH / 2, SCREEN_HEIGHT, WHITE);
}

void UpdateGame()
{
    ball.Update();
    player.Update();
    cpuPaddle.Update(ball.y);
}

void InitObjects()
{
    // init ball
    ball.radius = 20;
    ball.x = SCREEN_WIDTH / 2;
    ball.y = SCREEN_HEIGHT / 2;
    ball.speed_x = 8;
    ball.speed_y = 8;

    // init rectangle
    player.x = 10;
    player.y = (SCREEN_HEIGHT / 2) - 60;
    player.width = 25;
    player.height = 120;
    player.speed = 6;

    // init cpu
    cpuPaddle.x = SCREEN_WIDTH - 35;
    cpuPaddle.y = (SCREEN_HEIGHT / 2) - 60;
    cpuPaddle.width = 25;
    cpuPaddle.height = 120;
    cpuPaddle.speed = 6;

}

void CheckCollision()
{
    if (CheckCollisionCircleRec(Vector2{ ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.width, player.height}) || CheckCollisionCircleRec(Vector2{ ball.x, ball.y }, ball.radius, Rectangle{ cpuPaddle.x, cpuPaddle.y, cpuPaddle.width, cpuPaddle.height }))
    {
        ball.speed_x *= -1;
    }
}

void UpdateScore()
{
    if (ball.x + ball.radius > GetScreenWidth())
    {
        cpu_score++;
        ball.ResetBall();
    }
    if (ball.x - ball.radius <= 0)
    {
        player_score++;
        ball.ResetBall();
    }
}


int main()
{
    cout << "starting..." << endl;

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ponger");  // open window
    SetTargetFPS(60);   // run at 60 fps

    InitObjects();

    while(!WindowShouldClose()) 
    {
        BeginDrawing(); // draw game once

        ClearBackground(BLACK);
        DrawBackground();

        if (running)
        {
            ClearBackground(BLACK);
            DrawBackground();
            UpdateGame();
            CheckCollision();
            UpdateScore();
        }
        else
        {
            DrawText("Press space to start...", SCREEN_WIDTH / 3, 3*(SCREEN_HEIGHT/4), 40, WHITE);
            if (IsKeyPressed(KEY_SPACE))
            {
                running = true;
            }
        }

        DrawObjects();
        DrawTextGame();

        EndDrawing();   // finish drawing game once 
    }

    CloseWindow(); // close window
}