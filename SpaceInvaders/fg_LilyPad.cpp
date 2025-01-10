#include "fg_LilyPad.h"

LilyPad::LilyPad(int x)
{
	this->m_xpos = x;
	this->m_state = true;
	this->m_can_move = true;
}

void LilyPad::Update()
{
	this->Movement();
}

void LilyPad::Lifecycle()
{
	Regrow();
	// Delay(time)
	Decay();
}

void LilyPad::Regrow()
{
	if (m_can_grow && !m_is_grown && !this->GetState()) {
		this->SetState(true);
	}
}

void LilyPad::Decay()
{
	if (!m_can_grow && m_is_grown && this->GetState()) {
		this->SetState(false);
	}
}
