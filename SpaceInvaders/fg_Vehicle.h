#pragma once
#include <string>
#include "gameobject.h"

class Vehicle abstract : public GameObject {
public:
	void Draw() override;
	void Update() override;

	void SetStr(std::string s) { this->m_str = s; }
	std::string GetStr() { return this->m_str; }

	void SetPos(int x, int y) { this->m_xpos = x, this->m_ypos = y; };
	void SetSpeed(int speed) { this->m_speed = speed; };

	void SetState(bool state) { this->m_state = state; };
	bool GetState() { return this->m_state; }


	int GetXPos() { return this->m_xpos; };
	int GetYPos() { return this->m_ypos; };

	void Movement();
	void MoveX();
	void MoveY();
	void ResetPos();

private:
	std::string m_str;
	bool m_state;
	int m_speed;
};