#pragma once
#include <string>
#include "gameobject.h"
#include "fg_Locale.h"

class Vehicle abstract : public GameObject {
public:

	void SetPos(int x, int y) { this->m_xpos = x, this->m_ypos = y; };
	void SetSpeed(int speed) { this->m_speed = speed; };

	void SetState(bool state) { this->m_state = state; };
	bool GetState() { return this->m_state; }

	int GetXPos() { return this->m_xpos; };
	int GetYPos() { return this->m_ypos; };

	void SetLaneLimits(int lower_lim, int upper_lim, Locale::LaneTypes lane_type);

	void Movement();
	void MoveX();
	void MoveY();
	void ResetPos();
	

protected:
	LaneLim m_lane_limits;
	bool m_state;
	bool m_can_move;
	bool m_is_moving_right = true;
	int m_speed;
};