#pragma once
#include "GameObject.h"

class Alien:GameObject //inheritance
{
public:
	Alien():m_isActive(true) {}; //no warning 
	~Alien() {};

	Alien(const Alien& other);//copy constructor & const (lecture) 

	void setPostion(int x, int y);
	void setSpeed(int x);

	void draw() override; //explain use of word and if needed
	void setActive(bool state);

	int getXP() { return this->xPos; };
	int getYP() { return this->yPos; };

	

private:
	bool m_isActive;
	static int m_speed;
};

