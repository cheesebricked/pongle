#pragma once
#include <raylib.h>


class Ball
{
public:
	float x, y;
	int speed_x, speed_y;
	int radius;

	void Draw()
	{
		DrawCircle(x, y, radius, WHITE);
	}

	void ResetBall()
	{
		x = GetScreenWidth() / 2;
		y = GetScreenHeight() / 2;

		int init_speeds[2]{ -1, 1 };
		speed_x *= init_speeds[GetRandomValue(0, 1)];
		speed_y *= init_speeds[GetRandomValue(0, 1)];
	}

	void Update()
	{
		x += speed_x;
		y += speed_y;

		// check collision
		if (y + radius >= GetScreenHeight() || y - radius <= 0)
		{
			speed_y *= -1;
		}
	}
};