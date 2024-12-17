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
