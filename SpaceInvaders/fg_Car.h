#pragma once
#include "fg_Vehicle.h"

class Car : public Vehicle {
public:
	Car() : m_state(false), m_lane_type(Locale::ROAD){}

	void SpawnCar();
	void Update();
	char GetChar() { return kCarChar; }

private:
	bool is_moving;
	bool m_state;
	Locale::LaneTypes m_lane_type;

	static const char kCarChar = 'X';
	std::array<std::string, 4> m_car_strings = {
		"XX",
		"XXX",
		"XXXX",
		"XXXXX"
	};	// need to figure out how to pass this to the buffer
};
