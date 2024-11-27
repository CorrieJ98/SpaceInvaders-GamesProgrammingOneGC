#include "barrier.h"

Barrier::Barrier()
{
}

void Barrier::InitialiseBarrier()
{
}

void Barrier::TakeDamage(const int& dmg)
{
	this->health_ -= dmg;

	if (health_ <= 0) {
		this->~Barrier();
	}
}

void Barrier::Draw()
{
	// could also do {} [] for differing levels of HP on the barriers. This works for now.
	this->health_ <= 1 ? std::cout << 'x' : std::cout << 'X';
}

Barrier::~Barrier()
{	
}
