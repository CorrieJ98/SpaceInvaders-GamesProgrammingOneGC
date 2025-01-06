#include "fg_Vehicle.h"

void Vehicle::SetLaneLimits(int lower_lim, int lane_size, Locale::LaneTypes lane_type)
{
	this->m_lane_limits.bot = lower_lim;
	this->m_lane_limits.size = lane_size;
	this->m_lane_limits.type = lane_type;
}

void Vehicle::Movement()
{
}

void Vehicle::MoveX()
{
}

void Vehicle::MoveY()
{
}

void Vehicle::ResetPos()
{
}
