#include "fg_Vehicle.h"

void Vehicle::SetLaneLimits(int lower_lim, int lane_size, Locale::LaneTypes lane_type)
{
	this->m_lane_limits.bot = lower_lim;
	this->m_lane_limits.size = lane_size;
	this->m_lane_limits.type = lane_type;
}

void Vehicle::MoveX()
{
	if (m_state) {
		this->m_xpos + m_speed;
	}
}

void Vehicle::ResetPos()
{
	this->SetPos(0, 0);
	this->SetState(false);
	
	//this->SpawnVehicle();
}

void Vehicle::SpawnVehicle(int bot_limit, int lane_size)
{
	int lane_number = bot_limit + (rand() % lane_size);

	this->SetState(true);
	this->SetPos(10, 10);
	this->SetSpeed(1);
	this->MoveX();


	//// first half goes left-right
	//if (lane_number >= bot_limit && lane_number <= (lane_size * 0.5)) {
	//	this->SetState(true);
	//	this->SetPos(0, lane_number);
	//	this->SetSpeed(1); // original title takes 10s for vehicles to cross screen
	//	this->MoveX();
	//}
	//// second half goes right-left
	//else {
	//	this->SetState(true);
	//	this->SetPos(GAMEWINX, lane_number);
	//	this->SetSpeed(-1);
	//	this->MoveX();
	//}
}
