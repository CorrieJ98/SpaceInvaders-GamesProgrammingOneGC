#pragma once
#include <iostream>
#include "gameobject.h"

class Missile : public GameObject
{
public:
	Missile();

	void Draw() override;
	void Move();
	void HitTarget();

	~Missile();
	
private:
	int speed_ = 5;
};

