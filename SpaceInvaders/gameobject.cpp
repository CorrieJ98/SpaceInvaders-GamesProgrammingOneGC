#include "gameobject.h"

void gameobject::set_position(int x, int y)
{
	this->m_xpos = x;
	this->m_ypos = y;
}
void gameobject::set_xposition(int x)
{
	this->m_xpos = x;
}
void gameobject::set_yposition(int y)
{
	this->m_ypos = y;
}

int gameobject::get_xposition() {
	return this->m_xpos;
}

int gameobject::get_yposition()
{
	return this->m_ypos;
}

void gameobject::set_active(bool state)
{
	this->m_state = state;
}