#include "Player.h"


void Player::Update()
{
	if (GetKeyState(65) & 0x8000)
	{
		if (m_xpos > 1)
			m_xpos--;
	}
	else if (GetKeyState(68) & 0x8000)
	{
		if (m_xpos < 79)
			m_xpos++;
	}
}

