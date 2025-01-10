#pragma once
#include "custom_macros.h"
#include "GameObject.h"
#include "fg_Home.h"

class Frog : public GameObject {
public:
	Frog() : GameObject(20, 28) {} ;
	
	void Update() override;

	char GetChar() { return this->m_kFrogChar; }
	int GetLivesRemaining() { return m_lives; }
	void Reset() { this->m_xpos = 20; this->m_ypos = 28; }
	void SetSpeed(int speed) { m_speed = speed; }
	void SetSpeed(bool m_is_moving_right, int speed_to_add) { this->m_speed += speed_to_add; }

	void Die();
	void ReachedHome(int x);

private:
	int m_lives = 3;
	int m_speed = 1;
	static const char m_kFrogChar = 'H';
};