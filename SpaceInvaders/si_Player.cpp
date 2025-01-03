#include "si_Player.h"

// https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

void Player::Update()
{
	// A
	if (GetKeyState(0x41) & 0x8000)
	{
		if (m_xpos > GAMEWINX - (GAMEWINX - 1))
			--m_xpos;
	}
	// D
	else if (GetKeyState(0x44) & 0x8000)
	{
		if (m_xpos < GAMEWINX - 1)
			++m_xpos;
	}
}

