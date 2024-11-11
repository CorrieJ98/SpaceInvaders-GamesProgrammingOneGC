#pragma once
#include "gameobject.h"

class enemy : public gameobject
{
public:
	enemy();

	void shoot();
	void die();

	void update() override;
	void draw() override;

	~enemy();

private:
	int m_health = 1;
	int m_speed = 4;
};

