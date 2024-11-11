#include "missile.h"

missile::missile()
{
}

void missile::draw()
{
	std::cout << '|';
}

void missile::move()
{
	this->m_ypos += m_speed;
}

void missile::hit_target()
{
}

missile::~missile()
{
}
