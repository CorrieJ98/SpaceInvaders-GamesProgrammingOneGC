#include "fg_Vehicle.h"

void Vehicle::SetLaneLimits(int lower_lim, int lane_size, Locale::LaneTypes lane_type)
{
	this->m_lane_limits.bot = lower_lim;
	this->m_lane_limits.size = lane_size;
	this->m_lane_limits.type = lane_type;
}

void Vehicle::Movement() {
	if (m_state) {

		if (m_can_move) {

			MoveX();

			if (this->m_xpos > 79 || this->m_xpos < 1) {
				// MoveY();

				this->SetState(false);
			}
		}
	}
}

void Vehicle::MoveX()
{
	if (m_is_moving_right) {
		this->SetPos(++m_xpos, m_ypos);
	}
	else {
		this->SetPos(--m_xpos, m_ypos);
	}
}

void Vehicle::MoveY()
{
	this->SetPos(m_xpos, ++m_ypos);
	m_is_moving_right = !m_is_moving_right;
}

void Vehicle::ResetPos()
{
	this->SetPos(0, 0);
	this->SetState(false);
	
	//this->SpawnVehicle();
}

void Vehicle::SpawnVehicle(int bot_limit, int lane_size)
{
	int lane_number = bot_limit - (rand() % lane_size);
	bool called = false;

	if (!called)
	{
		this->SetPos(0, lane_number);
		called = true;
	}
}
