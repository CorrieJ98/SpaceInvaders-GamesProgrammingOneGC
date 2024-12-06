#include "Missile.h"

void Missile::FireMissile(Player& p)
{
	if (!active_)
	{
		if (GetKeyState(32) & 0x8000)
		{
			xpos_ = p.GetXPos();
			ypos_ = p.GetYPos() - 1;
			active_ = true;
		}
	}
}

void Missile::Update()
{
	if (active_)
	{
		if (this->ypos_ > 0)
		{
			--ypos_;
		}
		else
		{
			active_ = false;
		}
	}
}