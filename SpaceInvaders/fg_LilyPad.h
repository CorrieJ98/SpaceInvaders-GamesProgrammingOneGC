#pragma once
#include "fg_Vehicle.h"

class LilyPad : public Vehicle {
public:

	LilyPad() : m_state(true), m_can_grow(false), m_is_grown(true), m_lane_type(Locale::RIVER) {}
	LilyPad(int x);

	void Update();

	void Lifecycle();
	void Regrow();
	void Decay();

	char GetChar() { return kLilypadChar; }

private:
	bool m_state, m_can_grow, m_is_grown;
	Locale::LaneTypes m_lane_type;
	static const char kLilypadChar = '@';
};