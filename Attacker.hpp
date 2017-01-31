#pragma once
#include "skills.h"

namespace MyStrategy
{
	void attacker(BeliefState *state, int botID)
	{
		print("Attacker\n");
		Vec2D gpoint(HALF_FIELD_MAXX, 0);
		Vec2D apoint;
		state->computeBallLocation();
		if (Vec2D::distSq(state->homePos[botID], state->ballPos) <  BOT_BALL_THRESH)
		{
			if (state->ballPos.x > (-HALF_FIELD_MAXX + DBOX_HEIGHT))
			{
				apoint.x = state->ballPos.x;
				apoint.y = state->ballPos.y;
				
			}
			else
			{
				apoint.x = state->ballPos.x;
				apoint.y = state->ballPos.y;
				
			}
		}
		else
		{
			if (state->ballPos.x > (-HALF_FIELD_MAXX + (int)300))
			{
				apoint.x = state->ballPos.x;
				apoint.y = state->ballPos.y;
				

			}
			else
			{
				apoint.x = state->ballPos.x;
				apoint.y = state->ballPos.y;
			}
		}
		GoToPoint(botID, state, apoint, 0, true, false);
		if (state->ballPos.y > 0)
		{
			if (Vec2D::dist(state->homePos[2], state->ballPos) <= BOT_BALL_THRESH)
			{
				Spin(2, 50);
			}
		}
		else
		{
			if (Vec2D::dist(state->homePos[2], state->ballPos) <= BOT_BALL_THRESH)
			{
				Spin(2, -50);
			}
		}
		
	}
}




