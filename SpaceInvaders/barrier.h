#pragma once
#include <iostream>
#include "gameobject.h"

class barrier : public gameobject
{
public:
	barrier();
	void init_barrier();
	void take_damage(const int& dmg);
	void draw() override;

	~barrier();

private:
	int m_health = 2;
};

