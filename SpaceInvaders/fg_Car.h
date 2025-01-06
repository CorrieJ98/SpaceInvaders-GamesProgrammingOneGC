#pragma once
#include "fg_Vehicle.h"

class Car : public Vehicle {
public:
	Car() : m_state(true), m_lane_type(Locale::ROAD){}

	void Update();
	char GetChar() { return kCarChar; }

	void SpawnVehicle();
private:
	bool m_state;
	static const char kCarChar = 'X';
	Locale::LaneTypes m_lane_type;
};
