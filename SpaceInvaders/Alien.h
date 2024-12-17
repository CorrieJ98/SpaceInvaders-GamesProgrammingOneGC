#pragma once
#include "GameObject.h"

class Alien:GameObject //inheritance
{
public:
	Alien():m_state(true) {}; //no warning 
	~Alien() {};

	Alien(const Alien& other);//copy constructor & const (lecture) 

	void SetPos(int x, int y);
	void SetSpeed(int speed);
	void SetState(bool state);

	void Draw() override;
	void Update() override;

	int GetXPos() { return this->m_xpos; };
	int GetYPos() { return this->m_ypos; };

	void MoveLeft();
	void MoveRight();
	void MoveDown();

private:
	bool m_state;
	bool m_is_moving_right = true;
	static int m_group_speed;
	static const int m_kGroupWidth = 60;
	static int m_group_ywidth;
};

