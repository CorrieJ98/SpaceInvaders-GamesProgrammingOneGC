#pragma once
#include "custom_macros.h"
#include "GameObject.h"

class Frog : public GameObject {
public:
	Frog() : GameObject(20) {} ;
	void Update() override;

	char GetChar() { return this->m_kFrogChar; }

private:
	int m_lives = 3;
	static const char m_kFrogChar = 'H';
};