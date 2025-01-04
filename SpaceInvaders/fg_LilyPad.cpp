#include "fg_LilyPad.h"

void LilyPad::Lifecycle()
{
	Regrow();
	// Delay(time)
	Decay();
}

void LilyPad::Regrow()
{
	if (can_grow && !is_grown && !this->GetState()) {
		this->SetState(true);
	}
}

void LilyPad::Decay()
{
	if (!can_grow && is_grown && this->GetState()) {
		this->SetState(false);
	}
}
