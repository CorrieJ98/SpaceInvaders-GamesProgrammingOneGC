#pragma once
#include "GameObject.h"

class Barrier : public GameObject
{
public:

	Barrier() : m_state(true) {};
	Barrier(const Barrier& b) : m_state(b.m_state){};	// wtf is this for?
	~Barrier() {};

	void SetPos(int x, int y);
	int GetXPos();
	int GetYPos();
	void SetState(bool in) { m_state = in; };
	bool GetState() { return m_state; }
	char GetBarrierChar(){ return m_barrier_char; }
	void SetBarrierChar(char c) { this->m_barrier_char = c; }
	void TakeDamage(int dmg);


private:
	static int m_x;
	char m_barrier_char = '=';
	int m_health;
	bool m_state;
};

