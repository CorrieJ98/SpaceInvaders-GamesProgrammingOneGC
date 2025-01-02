#pragma once
#include "GameObject.h"

class Alien:GameObject
{
public:
	Alien() : m_state(true) {};
	~Alien() {};

	Alien(const Alien& other);

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
	void MoveDown();
	void ResetPos();

private:
	bool m_state;
	bool m_is_moving_right = true;
	bool m_can_move = true;
	static int m_group_speed;
	static const int m_kGroupWidth = 60;
	static int m_group_height;
};

