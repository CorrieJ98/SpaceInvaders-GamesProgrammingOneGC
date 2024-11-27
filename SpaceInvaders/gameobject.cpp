#include "gameobject.h"

void GameObject::SetPosition(int x, int y)
{
	this->xpos_ = x;
	this->ypos_ = y;
}
void GameObject::SetXPos(int x)
{
	this->xpos_ = x;
}
void GameObject::SetYPos(int y)
{
	this->ypos_ = y;
}

int GameObject::GetXPos() {
	return this->xpos_;
}

int GameObject::GetYPos()
{
	return this->ypos_;
}

void GameObject::SetActive(bool state)
{
	this->state_ = state;
}