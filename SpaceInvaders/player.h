#pragma once
#include "gameobject.h"

class player : public gameobject
{
public:
	player() {};
	~player() {};

	void update() override;
	void draw() override;

	void shoot();
	void move();

};
