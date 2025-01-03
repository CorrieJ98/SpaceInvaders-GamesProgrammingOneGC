#pragma once
#include "fg_Vehicle.h"

class LilyPad : public Vehicle {
public:
	void Lifecycle();
	
	void Regrow();
	void Decay();


private:
	bool m_state;
};