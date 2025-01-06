#include "fg_Frog.h"
// https://learn.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes

void Frog::Update()
{
#pragma region Keybindings
	// W or Up Arrow
	if (GetKeyState(VK_UP) & 0x8000 || GetKeyState(0x57) & 0x8000)
	{
		if (m_ypos > GAMEWINY - (GAMEWINY - 1))
			--m_ypos;
	}

	// S or Down Arrow
	if (GetKeyState(VK_DOWN) & 0x8000 || GetKeyState(0x53) & 0x8000)
	{
		if (m_ypos < GAMEWINY - 1)
			++m_ypos;
	}

	// A or Left Arrow
	if (GetKeyState(VK_LEFT) & 0x8000 || GetKeyState(0x41) & 0x8000)
	{
		if (m_xpos > GAMEWINX - (GAMEWINX - 1))
			--m_xpos;
	}

	// D or Right Arrow
	if (GetKeyState(VK_RIGHT) & 0x8000 || GetKeyState(0x44) & 0x8000)
	{
		if (m_xpos < GAMEWINX - 1)
			++m_xpos;
	}
#pragma endregion
}
