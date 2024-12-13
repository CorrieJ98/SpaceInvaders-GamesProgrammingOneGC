#pragma once
#include "GameObject.h"

class Alien : GameObject
{
public:
	Alien():active_(true) {};
	~Alien() {};

	Alien(const Alien& other);

	void SetPosition(int x, int y);
	void SetSpeed(int x);

	void Draw() override;
	void SetActive(bool state);

	int GetXPos() { return this->xpos_; };
	int GetYPos() { return this->ypos_; };


private:
	bool active_;
	static int speed_;
};

