#include "Missile.h"

void Missile::FireMissile(Player& p)
{
	if (!m_state)
	{
		if (GetKeyState(32) & 0x8000)
		{
			m_xpos = p.GetXPos();
			m_ypos = p.GetYPos() - 1;
			m_state = true;
		}
	}
}

void Missile::Update()
{
	if (m_state)
	{
		if (this->m_ypos > 0)
		{
			m_ypos--;
		}
		else
		{
			m_state = false;
		}
	}
}