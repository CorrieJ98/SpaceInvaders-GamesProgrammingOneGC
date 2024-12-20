#include "Alien.h"

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
#pragma region Alien Movement
	if (m_state) {

		//MoveStutter((float)m_kMoveStutter);

		if(m_can_move){
			MoveX();
			if (this->m_xpos > 79 || this->m_xpos < 1) {
				MoveDown();
			}
		}
	}
#pragma endregion
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

void Alien::MoveStutter(float delay)
{
	m_can_move = false;

	// delays the movement, but massively costly on a single thread. 
	// this slows the game to a crawl...find another way to do this.

	for (int i = 0; i < 1000; ++i) {
		for(int j = 0; j < 1000; j++){
			m_can_move = true;
		}
	}
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
