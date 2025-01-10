#include "fg_Home.h"

Home::Home(int x)
{
	this->m_xpos = x;
	this->m_state = true;
	this->m_player_present = false;
}

bool Home::GetFilledState()
{
	if (m_player_present && GetChar() == m_kFullHomeChar) {
		return true;
	}

	return false;
}
