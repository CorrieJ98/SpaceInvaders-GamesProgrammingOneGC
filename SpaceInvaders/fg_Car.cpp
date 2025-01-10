#include "fg_Car.h"

Car::Car(int x)
{
	this->m_xpos = x;
	this->m_state = true;
	this->m_can_move = true;
}

void Car::Update()
{
	this->Movement();
}


