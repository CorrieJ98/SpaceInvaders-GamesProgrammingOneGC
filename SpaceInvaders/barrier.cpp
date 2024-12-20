#include "Barrier.h"
int Barrier::m_x; // extra copy?

void Barrier::SetPos(int m_x, int y)
{
	this->m_xpos = m_x;
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

void Barrier::TakeDamage(uint8_t dmg)
{
	this->m_health -= dmg;
	std::cout << m_health << '\n';

	if (this->m_health < 2) {
		this->SetBarrierChar('x');
	}

	if (this->m_health < 1) {
		this->SetState(false);
	}
}
