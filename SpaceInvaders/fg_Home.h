#pragma once
#include "gameobject.h"

class Home : GameObject {
public:
	Home() : GameObject() {}
	Home(int x);

	Home GetHomeAtXPos(int x) { if (this->m_xpos == x) return *this; }
	bool GetFilledState();
	void FillHome() { m_char = &m_kFullHomeChar; };
	void EmptyHome() { m_char = &m_kEmptyHomeChar; }

	void SetPos(int x, int y) { this->m_xpos = x, this->m_ypos = y; };
	int GetXPos() { return this->m_xpos; };
	int GetYPos() { return this->m_ypos; };

	
	//char GetChar() { return *m_char; }	// I think this is correct notation
	char GetChar() {
		if (m_char == &m_kEmptyHomeChar){ return this->m_kEmptyHomeChar; }
		else { return this->m_kFullHomeChar; }
	}
	

protected:
	const char* m_char = &m_kEmptyHomeChar;
	static const char m_kEmptyHomeChar = 'O';
	static const char m_kFullHomeChar = '0';
	bool m_player_present;

private:
	bool m_state;
};