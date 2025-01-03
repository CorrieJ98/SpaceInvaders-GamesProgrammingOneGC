#pragma once
#include "gameobject.h"

class Vehicle abstract : public GameObject {
public:
	void SetPos(int x, int y);
	void SetSpeed(int speed);

	void SetState(bool in) { m_state = in; };
	bool GetState() { return m_state; }

	void Draw() override;
	void Update() override;

	int GetXPos() { return this->m_xpos; };
	int GetYPos() { return this->m_ypos; };

	void Movement();
	void MoveX();
	void MoveY();
	void ResetPos();

private:
	bool m_state;
	int m_speed;
};