#pragma once
#include "paddle.h"

class CpuPaddle : public Paddle
{
public:
	void Update(int ball_y)
	{
		if (y + height + 20 / 2 > ball_y)
		{
			y -= speed;
		}

		if (y + height + 20 / 2 < ball_y)
		{
			y += speed;
		}
		LimitRange();
	}
};
