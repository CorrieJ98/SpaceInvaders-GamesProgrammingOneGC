#pragma once
#include "fg_Vehicle.h"

class Car : public Vehicle {
public:
	Car() : m_state(true), m_lane_type(Locale::ROAD){}
	Car(int x);

	void Update() override;
	char GetChar() { return kCarChar; }
private:
	bool m_state = true;
	static const char kCarChar = 'X';
	Locale::LaneTypes m_lane_type;
};
