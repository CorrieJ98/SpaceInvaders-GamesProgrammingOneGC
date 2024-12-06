#include "Barrier.h"
int Barrier::x_; // extra copy?

void Barrier::SetPosition(int x, int y)
{
	this->xpos_ = x;
	this->ypos_ = y;
}

int Barrier::GetXPos()
{
	return this->xpos_;
}

int Barrier::GetYPos()
{
	return this->ypos_;
}

void Barrier::TakeDamage(int damage)
{
	--health_;

	if (health_ < 1) {
		SetActive(false);
	}
}
