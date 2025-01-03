#include "si_Player.h"


void Player::Update()
{
	// A
	if (GetKeyState(65) & 0x8000)
	{
		if (m_xpos > 1)
			--m_xpos;
	}
	// D
	else if (GetKeyState(68) & 0x8000)
	{
		if (m_xpos < 79)
			++m_xpos;
	}
}

