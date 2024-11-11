#pragma once
#include <iostream>
#include "gameobject.h"

class missile : public gameobject
{
public:
	missile();

	void draw() override;
	void move();
	void hit_target();

	~missile();
	
private:
	int m_speed = 5;
};

