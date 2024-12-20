#pragma once
#include "GameObject.h"
#include "Player.h"

class Missile : public GameObject
{
public:
	Missile(): m_state(false) {}
	void FireMissile(Player &p);
	void Update();
	void SetState(bool state) { this->m_state = state; }
	bool GetState() { return this->m_state; }
	uint8_t GetDamage() { return this->m_damage; }
		
private:
	bool m_state;
	uint8_t m_damage = 1;
};

