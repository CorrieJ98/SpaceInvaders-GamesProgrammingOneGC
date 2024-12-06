#include "Alien.h"

Alien::Alien(const Alien& other)
{
	std::cout << " A copy of alien has been made" << '\n';
}

void Alien::SetPosition(int x, int y)
{
	xpos_ = x;
	ypos_ = y;
}

void Alien::SetActive(bool state) 
{
	this->active_ = state;
}

void Alien::Draw()
{
	std::cout << "X";
}

void Alien::SetSpeed(int x)
{
	this->speed_ = x;
}
