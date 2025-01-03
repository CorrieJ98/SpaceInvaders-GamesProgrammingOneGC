#pragma once
#include "gameobject.h"

class Home : GameObject {
public:
	void FillHome() { m_char = &m_full_home_char; };
	void EmptyHome() { m_char = &m_empty_home_char; }

protected:
	char* m_char = &m_empty_home_char;

private:
	bool m_player_touched;
	bool m_state;
	char m_empty_home_char = 'O';
	char m_full_home_char = '0';
};