#pragma once
#include "fg_Vehicle.h"

class LilyPad : public Vehicle {
public:
	void Lifecycle();
	
	void Regrow();
	void Decay();

	char GetChar() { return kLilypadChar; }

private:
	bool m_state, can_grow, is_grown;
	static const char kLilypadChar = '@';
};