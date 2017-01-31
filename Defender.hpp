#pragma once
#include "skills.h"

namespace MyStrategy
{
	// Naive example for defender
	void defender(BeliefState *state, int botID)
	{
		print("Defender\n");
		//It follows the ball
		Vec2D dpoint;
		state->computeBallLocation();
		if (state->ballPos.x > 0)
		{
			if (state->pr_looseBall == true)
			{
				dpoint.x = state->ballPos.x;
				dpoint.y = state->ballPos.y;

			}
			dpoint.x = state->ballPos.x;
			dpoint.y = state->ballPos.y;

		}
		else
		{
			if (state->ballPos.x > (-HALF_FIELD_MAXX)*(3/4))
			{
				dpoint.x = (-HALF_FIELD_MAXX)*(3/4);
				dpoint.y = state->ballPos.y;

			}
			else
			{
				dpoint.x = state->ballPos.x;
				dpoint.y = state->ballPos.y;

			}

		}

		GoToPoint(botID, state, dpoint, PI / 2, true, false);
		if (state->ballPos.y > 0)
		{
			if (Vec2D::dist(state->homePos[1], state->ballPos) <= BOT_BALL_THRESH)
			{
				Spin(1, 50);
			}
		}
		else
		{
			if (Vec2D::dist(state->homePos[1], state->ballPos) <= BOT_BALL_THRESH)
			{
				Spin(1, -50);
			}
		}
	}
}
