#include "si_Barrier.h"
int Barrier::m_x; // extra copy?

void Barrier::SetPos(int x, int y)
{
	this->m_xpos = x;
	this->m_ypos = y;
}

int Barrier::GetXPos()
{
	return this->m_xpos;
}

int Barrier::GetYPos()
{
	return this->m_ypos;
}

void Barrier::TakeDamage(int dmg)
{
	this->m_health -= dmg;

	if (this->m_health < 1) {
		this->SetState(false);
	}
}
