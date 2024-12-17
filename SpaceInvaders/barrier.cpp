#include "Barrier.h"
int Barrier::x; // extra copy?

void Barrier::setPostion(int x, int y)
{
	this->xPos = x;
	this->yPos = y;
}

int Barrier::getXPostion()
{
	return this->xPos;
}

int Barrier::getYPostion()
{
	return this->yPos;
}
