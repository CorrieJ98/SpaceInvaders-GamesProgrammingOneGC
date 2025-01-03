#include "GameSource.h"

int Alien::m_group_speed; // define static variable

extern int menuChoice; 

GameSource::GameSource(): m_player(new Player()) {} // heap allocatoin (explain new and pointer)

GameSource::~GameSource()
{
	delete m_player;
}; // ";" is not needed but is will not break the code

void GameSource::SetPlayerPos()
{
	m_player->SetXPos(15);
	m_player->SetYPos(PLAYER);
}

void GameSource::SetAlienPos() 
{
	for (int i = 0; i < 20; i++)
	{
		m_aliens[i].SetPos(i*3, 1);
	}
}

// todo change from std::vector to array
void GameSource::SetBarrierPos()
{
#pragma region Barrier Array

	for (int i = 0; i < BARRIERS; i++)
	{
		m_barriers[i] = Barrier();
	}

	for (int i = 0; i < 5; i++)
	{
		m_barriers[i].SetPos(i + 10, BARRIER_Y);
	}
	for (int i = 5; i < 10; i++)
	{
		m_barriers[i].SetPos(i + 25, BARRIER_Y);
	}
	for (int i = 10; i < 15; i++)
	{
		m_barriers[i].SetPos(i + 40, BARRIER_Y);
	}
	for (int i = 15; i < 20; i++)
	{
		m_barriers[i].SetPos(i + 55, BARRIER_Y);
	}
#pragma endregion
	
#pragma region Barrier vector obsolete
	//for (int i = 0; i < BARRIERS; i++)
	//{
	//	m_vbarriers.emplace_back(Barrier());
	//}

	//for (int i = 0; i < 5; i++)
	//{
	//	m_vbarriers[i].SetPos(i + 10, BARRIER_Y);
	//}
	//for (int i = 5; i < 10; i++)
	//{
	//	m_vbarriers[i].SetPos(i + 25, BARRIER_Y);
	//}
	//for (int i = 10; i < 15; i++)
	//{
	//	m_vbarriers[i].SetPos(i + 40, BARRIER_Y);
	//}
	//for (int i = 15; i < 20; i++)
	//{
	//	m_vbarriers[i].SetPos(i + 55, BARRIER_Y);
	//}
#pragma endregion
}

void GameSource::CreateBuffers(int m_width, int m_height)
{
	// create the front buffer
	m_frontBuffer = ScreenBuffer(m_width, m_height);
	// create the back buffer
	m_backBuffer = ScreenBuffer(m_width, m_height);
	// create the reset buffer
	m_resetBuffer = ScreenBuffer(m_width, m_height);

	for (int i = 0; i < m_width; i++)
		for (int j = 0; j < m_height; j++)
			m_resetBuffer.setChar(i,j,' ');

	m_frontBuffer = m_resetBuffer;
	m_backBuffer = m_resetBuffer;
}

void GameSource::SwapBuffers()
{
	std::swap(m_frontBuffer, m_backBuffer);  // Move assignment
	m_backBuffer = m_resetBuffer;   // Move assignment
}


void GameSource::InitGame()
{
	m_game_window.SetWindow(80, 30, 1.5f);
	SetPlayerPos();
	SetAlienPos();
	SetBarrierPos();
	CreateBuffers(80,30);
	m_gamestate = STARTSCREEN; // set starting gameState
}

void GameSource::ProcessInput(int menu_choice)
{
	m_player->Update();
	m_missile.FireMissile(*m_player);
}

void GameSource::UpdateGame(int menu_choice)
{
#pragma region Alien Movement
	int speed;
	speed = m_aliens[0].GetYPos() > SPEED ? 2 : 1;

	for (int i = 0; i < sizeof m_aliens / sizeof m_aliens[0]; i++) {
		m_aliens[i].SetSpeed(speed);
		m_aliens[i].Update();
	}

#pragma endregion
}

void GameSource::SetGameState(int state)
{
	m_gamestate = static_cast<gameState>(state); //casting lecture
}

void GameSource::SetGamePositions(int m_width, int m_height, int menu_choice)  //potentially save and read from textfile?
{ //Break here to show copies (Dynamic vs Static array)

#pragma region Aliens
	for (int i = 0; i < m_height; i++)
	{	
		for (int j = 0; j < m_width; j++) // Draw aliens
		{
			for (int aNo = 0; aNo < 20; aNo++) //3rd for loop, can this be improved? 2D array
			{
				if ((m_aliens[aNo].GetYPos() == i) && (m_aliens[aNo].GetXPos() == j))
				{
						m_backBuffer.setChar(m_aliens[aNo].GetXPos(),m_aliens[aNo].GetYPos(),'X');
				}
			}
		}
#pragma endregion

#pragma region Barriers Array
		if (i == (BARRIER_Y))
		{
			for (int j = 0; j < m_width; j++)
			{
				for (int k = 0; k < sizeof m_barriers / sizeof m_barriers[k] ; k++)
				{
					if (m_barriers[k].GetXPos() == j)
					{
						if (m_barriers[k].GetState())
						{
							m_backBuffer.setChar(m_barriers[k].GetXPos(), BARRIER_Y, m_barriers[k].GetBarrierChar());
						}
					}
				}
			}
		}
		
#pragma endregion

#pragma region Barriers Vector Obsolete


		/*	if (i == (BARRIER_Y))
		{
			for (int j = 0; j < m_width; j++)
			{
				for (unsigned int bNo = 0; bNo < m_vbarriers.size(); bNo++)
				{
					if (m_vbarriers[bNo].GetXPos() == j)
					{
						if (m_vbarriers[bNo].GetState())
						{
							m_backBuffer.setChar(m_vbarriers[bNo].GetXPos(), BARRIER_Y, m_vbarriers[bNo].GetBarrierChar());
						}
					}
				}
			}
		}*/
#pragma endregion

#pragma region Player
		if (i == (PLAYER)) //Draw player
		{
			for (int j = 0; j < m_width; j++)
				if (m_player->GetXPos() == j)
				{
					m_backBuffer.setChar(m_player->GetXPos(), PLAYER, '^');
				}
		}
#pragma endregion

#pragma region Ground
		else if (i == (GROUND))	//Draw ground
		{
			for (int j = 0; j < m_width; j++)
				m_backBuffer.setChar(j, GROUND, '-');
		}
	}
#pragma endregion

#pragma region Missile
	if (m_missile.GetState())
	{
		m_backBuffer.setChar(m_missile.GetXPos(), m_missile.GetYPos(), '!');
		m_missile.Update();
	}
#pragma endregion
}

void GameSource::CheckCollision(int m_width, int m_height, int menu_choice)
{
#pragma region Barrier
	for (Barrier& barrier : m_barriers)
	{
		if (barrier.GetState()) {
			if (barrier.GetXPos() == m_missile.GetXPos() && barrier.GetYPos() == m_missile.GetYPos())
			{
				//barrier.TakeDamage(m_missile.GetDamage());
				barrier.SetState(false);
				m_missile.SetState(false);
			}
		}
	}
#pragma endregion

#pragma region Alien
	for (Alien& alien : m_aliens)
	{
		if (alien.GetState()) {
			// check one block below for the missile as well as on the aliens coords
			// this gives the player a little bit of grace with aiming
			if (alien.GetXPos() == m_missile.GetXPos() && (alien.GetYPos() == m_missile.GetYPos() || alien.GetYPos() == m_missile.GetYPos() + 1))
			{
				alien.SetPos(-10, -10);	// send alien to purgatory
				m_missile.SetXPos(-10);	// send missile to purgatory
				alien.SetState(false);
				m_missile.SetState(false);
			}
		}
	}
#pragma endregion

CheckGameCondition();

}

void GameSource::DrawGame(int m_width, int m_height)
{
	for (int i = 0; i < m_height; i++)
	{
		for (int j = 0; j < m_width; j++) 
		{
			m_game_window.setCursorPosition(j,i);
			std::cout << m_frontBuffer.getChar(j,i);
		}
	}
}

void GameSource::GameLoop()
{
	while (m_gamestate != gameState::EXIT)
	{
		switch (m_gamestate)
		{
		case STARTSCREEN:
			m_menu->Run();
			this->SetGameState(menuChoice);
			break;
		case SPACE_INVADERS:
			this->ProcessInput(menuChoice);
			this->UpdateGame(menuChoice);
			this->SetGamePositions(m_game_window.GetWidth(), m_game_window.GetHeight(), menuChoice);
			this->CheckCollision(m_game_window.GetWidth(), m_game_window.GetHeight(), menuChoice);
			this->SwapBuffers();
			this->DrawGame(m_game_window.GetWidth(), m_game_window.GetHeight());
			break;
		case FROGGER:
			// TODO Add This
			break;
		case WIN:
			system("cls");
			std::cout << "YOU WIN" << '\n';
			break;
		case LOSS:
			system("cls");
			std::cout << "YOU LOSE" << '\n';
			break;
		}
	}
}

void GameSource::CheckGameCondition()
{
	// loop through aliens, check m_ypos if its on the ground
	// if it is, and any aliens are alive (state == false) player loses
	// otherwise player has won

	for (int i = 0; i < sizeof m_aliens / sizeof m_aliens[0]; i++) {
		
		// if all enemy states are false, player wins
		
		if (m_aliens[i].GetYPos() >= PLAYER - 1) {
			m_gamestate = LOSS;
		}
		
	}
}
