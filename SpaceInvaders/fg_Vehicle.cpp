#include "fg_Vehicle.h"

void Vehicle::SetLaneLimits(int lower_lim, int lane_size, Locale::LaneTypes lane_type)
{
	this->m_lane_limits.bot = lower_lim;
	this->m_lane_limits.size = lane_size;
	this->m_lane_limits.type = lane_type;
}

void Vehicle::Movement() {
	MoveX();

	if (this->m_xpos > 79 || this->m_xpos < 1) {
		this->SetState(true);
		this->ResetPos(this->m_is_moving_right);
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

void Vehicle::ResetPos(bool is_moving_right)
{
	if (is_moving_right) {
		this->SetPos(1, m_ypos);	
	}
	else {
		this->SetPos(GAMEWINX - 1, m_ypos);
	}
}
