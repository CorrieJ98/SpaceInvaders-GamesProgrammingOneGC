#pragma once
#include <string>
#include "gameobject.h"
#include "fg_Locale.h"

class Vehicle abstract : public GameObject {
public:

	int GetSpeed() { return this->m_speed; }
	void SetSpeed(int speed) { this->m_speed = speed; };

	void SetState(bool state) { this->m_state = state; };
	bool GetState() { return this->m_state; }

	void SetPos(int x, int y) { this->m_xpos = x, this->m_ypos = y; };
	int GetXPos() { return this->m_xpos; };
	int GetYPos() { return this->m_ypos; };

	void SetLaneLimits(int lower_lim, int upper_lim, Locale::LaneTypes lane_type);

	void Movement();
	void MoveY();
	void MoveX();
	void ResetPos();

	void SpawnVehicle(int bot_limit, int lane_size);
	

protected:
	LaneLim m_lane_limits;
	bool m_state, m_is_moving_right, m_can_move;
	int m_speed;
};