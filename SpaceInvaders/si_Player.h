#pragma once
#include "GameObject.h"

class Player: public GameObject
{
public:
	Player(): GameObject(10) {}; //member init from derived class

	void Update() override;
};

