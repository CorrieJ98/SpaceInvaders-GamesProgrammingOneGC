#include "barrier.h"

barrier::barrier()
{
}

void barrier::init_barrier()
{
}

void barrier::take_damage(const int& dmg)
{
	this->m_health -= dmg;

	if (m_health <= 0) {
		this->~barrier();
	}
}

void barrier::draw()
{
	// could also do {} [] for differing levels of HP on the barriers. This works for now.
	this->m_health <= 1 ? std::cout << 'x' : std::cout << 'X';
}

barrier::~barrier()
{	
}
