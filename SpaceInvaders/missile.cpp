#include "missile.h"

Missile::Missile()
{
}

void Missile::Draw()
{
	std::cout << '|';
}

void Missile::Move()
{
	this->ypos_ += speed_;
}

void Missile::HitTarget()
{
}

Missile::~Missile()
{
}
