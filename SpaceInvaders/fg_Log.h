#pragma once
#include "fg_Vehicle.h"
#include "fg_locale.h"

class Log : public Vehicle {
public:
	Log() : m_state(true), m_lane_type(Locale::RIVER) {}
	Log(int x);

	void Update() override;
	char GetChar() { return kLogChar; }
private:
	bool m_is_moving, m_state;
	Locale::LaneTypes m_lane_type;
	static const char kLogChar = '=';
};