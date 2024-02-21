#pragma once
#include <raylib.h>

class Paddle
{
public:
	float x, y;
	float width, height;
	int speed;

	void Draw() 
	{
		DrawRectangle(x, y, width, height, WHITE);
	}

	void Update()
	{
		if (IsKeyDown(KEY_UP))
		{
			y -= speed;
		}
		if (IsKeyDown(KEY_DOWN))
		{
			y += speed;
		}
		LimitRange();
	}
protected:
	void LimitRange()
	{
		if (y <= 0)
		{
			y = 0;
		}
		if (y + height >= GetScreenHeight())
		{
			y = GetScreenHeight() - height;
		}
	}
};