#pragma once
#include "fg_Vehicle.h"

class LilyPad : public Vehicle {
public:

	LilyPad() : m_state(true), m_lane_type(Locale::RIVER) {}
	LilyPad(const LilyPad& l) : m_state(l.m_state) {};

	void Update();

	void Lifecycle();
	
	void Regrow();
	void Decay();

	char GetChar() { return kLilypadChar; }

private:
	bool m_state, can_grow, is_grown;
	Locale::LaneTypes m_lane_type;
	static const char kLilypadChar = '@';
};