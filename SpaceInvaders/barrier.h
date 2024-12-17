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

private:
	static int m_x;
	bool m_state;
};

