#pragma once
#include <string>
#include "gameobject.h"
#include "fg_Locale.h"

class Vehicle abstract : public GameObject {
public:

	void SetStr(std::string s) { this->m_str = s; }
	std::string GetStr() { return this->m_str; }

	void SetPos(int x, int y) { this->m_xpos = x, this->m_ypos = y; };
	void SetSpeed(int speed) { this->m_speed = speed; };

	void SetState(bool state) { this->m_state = state; };
	bool GetState() { return this->m_state; }

	Locale::LaneTypes GetLaneType(){ return this->m_lane_type; }
	void SetLaneType(Locale::LaneTypes lt) { this->m_lane_type = lt; }

	int GetXPos() { return this->m_xpos; };
	int GetYPos() { return this->m_ypos; };

	void Movement();
	void MoveX();
	void MoveY();
	void ResetPos();
	

protected:
	std::string m_str;
	Locale::LaneTypes m_lane_type;
	bool m_state;
	bool m_can_move;
	bool m_is_moving_right = true;
	int m_speed;
};