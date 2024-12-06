#include "Player.h"


void Player::Update()
{
	if (GetKeyState(65) & 0x8000)
	{
		if (xpos_ > 1)
			--xpos_;
	}
	else if (GetKeyState(68) & 0x8000)
	{
		if (xpos_ < 79)
			++xpos_;
	}
}

