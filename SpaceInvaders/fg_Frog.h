#pragma once
#include "custom_macros.h"
#include "GameObject.h"

class Frog : public GameObject {
public:
	Frog() : GameObject(20, 28) {} ;
	
	void Update() override;

	char GetChar() { return this->m_kFrogChar; }
	int GetLivesRemaining() { return m_lives; }
	void Die();
	void Reset() { this->m_xpos = 20; this->m_ypos = 28; }

private:
	int m_lives = 3;
	static const char m_kFrogChar = 'H';
};