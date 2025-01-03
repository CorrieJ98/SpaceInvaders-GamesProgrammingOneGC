#include "fg_Frog.h"
// https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

void Frog::Update()
{
	// W
	if (GetKeyState(0x57) & 0x8000)
	{
		if (m_ypos > GAMEWINY - (GAMEWINY - 1))
			--m_ypos;
	}

	// S
	else if (GetKeyState(0x53) & 0x8000)
	{
		if (m_ypos < GAMEWINY - 1)
			++m_ypos;
	}

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
