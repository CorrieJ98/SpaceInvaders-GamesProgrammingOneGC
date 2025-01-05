#include "fg_Car.h"

void Car::SpawnCar()
{
	if (!m_state) {
		/*
			adapt from Missile::FireMissile
			instead of player position, randomly select
			the lane and set direction based on that lane
			ie

			bottom road lane (lane 1) moves right to left
			uppermost lane moves left to right
		*/

		int r = 0 + (rand() % FG_ROAD_LANES);
		int dir = 0 + (rand() % 1);

		this->SetState(true); // this->m_xpos = lane[r].xpos; this->ypos = lane[r].ypos
		/*
			if(dir == 1) spawn left and move right
			if(dir == 0) spawn right and move left
		*/
	}
}

void Car::Update()
{
	if (m_state) {
		if (this->m_xpos < 0) {
			++m_xpos;

			if (this->m_xpos > GAMEWINX) {
				this->SetState(false);
			}
		}

		if (this->m_xpos > GAMEWINX) {
			--m_xpos;

			if (this->m_xpos < 0) {
				this->SetState(false);
			}
		}
	}
}
