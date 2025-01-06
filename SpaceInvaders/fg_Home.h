#pragma once
#include "gameobject.h"

class Home : GameObject {
public:
	void FillHome() { m_char = &m_kFullHomeChar; };
	void EmptyHome() { m_char = &m_kEmptyHomeChar; }

protected:
	const char* m_char = &m_kEmptyHomeChar;

private:
	bool m_player_present;
	bool m_state;
	static const char m_kEmptyHomeChar = 'O';
	static const char m_kFullHomeChar = '0';
};