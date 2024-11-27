#pragma once
#include <iostream>
#include "gameobject.h"

class Barrier : public GameObject
{
public:
	Barrier();
	void InitialiseBarrier();
	void TakeDamage(const int& dmg);
	void Draw() override;

	~Barrier();

private:
	int health_ = 2;
};

