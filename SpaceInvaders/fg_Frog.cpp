#include "fg_Frog.h"

void Frog::Update()
{
	// W
	if (GetKeyState(92) & 0x8000)
	{
		if (m_ypos > 1)
			--m_xpos;
	}
	// S
	else if (GetKeyState(88) & 0x8000)
	{
		if (m_xpos < 79)
			++m_xpos;
	}

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
