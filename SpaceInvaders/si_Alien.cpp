#include "si_Alien.h"

Alien::Alien(const Alien& other)
{
	std::cout << " A copy of alien has been made" << '\n';
}

void Alien::SetPos(int x, int y)
{
	this->m_xpos = x;
	this->m_ypos = y;
}

void Alien::Draw()
{
	std::cout << "X";
}

void Alien::Update()
{	
	Movement();
}

void Alien::Movement() {
	if (m_state) {

		if (m_can_move) {

			MoveX();

			if (this->m_xpos > 79 || this->m_xpos < 1) {
				MoveDown();
			}
		}
	}
}

void Alien::MoveX()
{
	if (m_is_moving_right) {
		this->SetPos(++m_xpos, m_ypos);
	}
	else {
		this->SetPos(--m_xpos, m_ypos);
	}
}

void Alien::MoveDown()
{
	this->SetPos(m_xpos, ++m_ypos);
	m_is_moving_right = !m_is_moving_right;
}

void Alien::ResetPos()
{
	// TODO This
	this->SetPos(1, 1);
}


void Alien::SetSpeed(int speed)
{
	this->m_group_speed = speed;
}
