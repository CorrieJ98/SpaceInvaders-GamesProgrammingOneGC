#include "Alien.h"

Alien::Alien(const Alien& other)
{
	std::cout << " A copy of alien has been made" << '\n';
}

void Alien::SetPos(int x, int y)
{
	m_xpos = x;
	m_ypos = y;
}

void Alien::SetState(bool state) 
{
	this->m_state = state;
}

void Alien::Draw()
{
	std::cout << "X";
}

void Alien::Update()
{
	if (m_state) {
		if (this->m_kGroupWidth + this->m_xpos >= 80) {
			MoveDown();
			m_is_moving_right = !m_is_moving_right;
		}

		if (this->m_xpos - this->m_kGroupWidth <= 1) {
			MoveDown();
			m_is_moving_right = !m_is_moving_right;
		}

		if (m_is_moving_right)
		{
			MoveRight();
		}
		else {
			m_is_moving_right == false;
			MoveLeft();
		}
	}
}

void Alien::MoveLeft()
{
	this->SetPos(--m_xpos, m_ypos);
}

void Alien::MoveRight()
{
	this->SetPos(++m_xpos, m_ypos);
}

void Alien::MoveDown()
{
	this->SetPos(m_xpos, ++m_ypos);
}

void Alien::SetSpeed(int speed)
{
	this->m_group_speed = speed;
}
