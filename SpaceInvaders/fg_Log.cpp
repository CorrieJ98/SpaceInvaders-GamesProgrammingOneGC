#include "fg_Log.h"

Log::Log(int x)
{
	this->m_xpos = x;
	this->m_state = true;
	this->m_can_move = true;
}

void Log::Update()
{
	this->Movement();
}
