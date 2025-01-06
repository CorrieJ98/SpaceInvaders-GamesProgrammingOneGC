#include "GameSource.h"

int Alien::m_group_speed; // define static variable

extern int menuChoice; 

GameSource::GameSource() : m_si_player(new Player()), m_fg_frog(new Frog()) {}

GameSource::~GameSource()
{
	delete m_fg_frog;
	delete m_si_player;
}

void GameSource::SI_SetPlayerPos()
{
	m_si_player->SetXPos(15);
	m_si_player->SetYPos(SI_PLAYER_Y);
}

void GameSource::SI_SetAlienPos() 
{
	for (int i = 0; i < 20; i++)
	{
		m_si_aliens[i].SetPos(i*3, 1);
	}
}

// todo change from std::vector to array
void GameSource::SI_SetBarrierPos()
{
#pragma region Barrier Array

	for (int i = 0; i < SI_BARRIERS; i++)
	{
		m_si_barriers[i] = Barrier();
	}

	for (int i = 0; i < 5; i++)
	{
		m_si_barriers[i].SetPos(i + 10, SI_BARRIER_Y);
	}
	for (int i = 5; i < 10; i++)
	{
		m_si_barriers[i].SetPos(i + 25, SI_BARRIER_Y);
	}
	for (int i = 10; i < 15; i++)
	{
		m_si_barriers[i].SetPos(i + 40, SI_BARRIER_Y);
	}
	for (int i = 15; i < 20; i++)
	{
		m_si_barriers[i].SetPos(i + 55, SI_BARRIER_Y);
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
	m_game_window.SetWindow(GAMEWINX, GAMEWINY, 1.5f);
	
	CreateBuffers(GAMEWINX, GAMEWINY);
	m_gamestate = STARTSCREEN; // set starting gameState
}

void GameSource::InitSpaceInvaders()
{
	if (!m_game_initialised)
	{
		SI_SetPlayerPos();
		SI_SetAlienPos();
		SI_SetBarrierPos();

		m_game_initialised = true;
	}
}

void GameSource::InitFrogger()
{
	if (!m_game_initialised)
	{
		FG_SetPlayerPos();
		FG_SetVehiclePos();
		FG_SetLanes();
		m_game_initialised = true;
	}
}

void GameSource::FG_SetPlayerPos()
{
	m_fg_frog->SetXPos(40);
	m_fg_frog->SetYPos(FG_FROG_Y);
}

void GameSource::FG_SetVehiclePos()
{
	for (int i = 0; i < FG_MAX_CARS; i++)
	{
		m_fg_cars[i] = Car();
	}

	for (int i = 0; i < FG_MAX_LOGS; i++)
	{
		m_fg_logs[i] = Log();
	}

	for (int i = 0; i < FG_MAX_LILYPADS; i++)
	{
		m_fg_lilypads[i] = LilyPad();
	}
}

void GameSource::FG_SetLanes()
{
	this->m_start_lim.bot = GAMEWINY;
	this->m_start_lim.size = FG_START_LANES;
	this->m_start_lim.type = Locale::STARTPAVE;

	this->m_road_lim.bot = GAMEWINY - FG_START_LANES;
	this->m_road_lim.size = FG_ROAD_LANES;
	this->m_road_lim.type = Locale::ROAD;

	this->m_pave_lim.bot = m_road_lim.bot - m_road_lim.size;
	this->m_pave_lim.size = FG_MIDPAVE_LANES;
	this->m_pave_lim.type = Locale::MIDPAVE;

	this->m_river_lim.bot = m_pave_lim.bot - m_pave_lim.size;
	this->m_river_lim.size = FG_RIVER_LANES;
	this->m_river_lim.type = Locale::RIVER;

	this->m_grass_lim.bot = m_river_lim.bot - m_river_lim.size;
	this->m_grass_lim.size = FG_GRASS_LANES;
	this->m_grass_lim.type = Locale::GRASS;
}

void GameSource::FG_ProcessInput()
{
	m_fg_frog->Update();
}

void GameSource::FG_UpdateGame()
{
#pragma region Car Movement

#pragma endregion

#pragma region Log Movement

#pragma endregion

#pragma region Lilypad Movement

#pragma endregion
}

void GameSource::FG_SetGamePositions(int width, int height)
{

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) {

#pragma region Cars
			for (int k = 0; k < FG_MAX_CARS; k++) {
				if ((m_fg_cars[k].GetYPos() == i) && (m_fg_cars[k].GetXPos() == j)) {
					m_backBuffer.setChar(m_fg_cars[k].GetXPos(), m_fg_cars[k].GetYPos(), m_fg_cars[k].GetChar());
				}
			}
#pragma endregion

#pragma region Player
			if (i == (FG_FROG_Y)) //Draw player
			{
				for (int j = 0; j < width; j++)
					if (m_fg_frog->GetXPos() == j)
					{
						m_backBuffer.setChar(m_fg_frog->GetXPos(), m_fg_frog->GetYPos(), m_fg_frog->GetChar());
					}
			}
#pragma endregion

#pragma region Logs
			for (int k = 0; k < FG_MAX_LOGS; k++) {
				if ((m_fg_logs[k].GetYPos() == i) && (m_fg_logs[k].GetXPos() == j)) {
					m_backBuffer.setChar(m_fg_cars[k].GetXPos(), m_fg_logs[k].GetYPos(), m_fg_logs[k].GetChar());
				}
			}
#pragma endregion
#pragma region Lilypads
			for (int k = 0; k < FG_MAX_LILYPADS; k++) {
				if ((m_fg_lilypads[k].GetYPos() == i) && (m_fg_lilypads[k].GetXPos() == j)) {
					m_backBuffer.setChar(m_fg_cars[k].GetXPos(), m_fg_lilypads[k].GetYPos(), m_fg_lilypads[k].GetChar());
				}
			}
#pragma endregion

#pragma region Lane Borders
			// This whole section is terribly verbose, I am so sorry.
			// I start from the bottom of the screen and draw the relevant
			// lane borders from the bottom - upwards offsetting more
			// and more on each if statement.

			//Draw Start borders
			if (i == (FG_FROG_Y + 1))
			{
				for (int j = 0; j < width; j++)
					m_backBuffer.setChar(j, height - 1, '-');
			}

			if (i == (FG_FROG_Y - FG_START_LANES))
			{
				for (int j = 0; j < width; j++)
					m_backBuffer.setChar(j, FG_FROG_Y - 1, '-');
			}


			// Draw Road borders
			if (i == (height - FG_START_LANES))
			{
				for (int j = 0; j < width; j++)
					m_backBuffer.setChar(j, FG_FROG_Y - FG_ROAD_LANES, '-');
			}

			if (i == (height - m_road_lim.bot))
			{
				for (int j = 0; j < width; j++)
					m_backBuffer.setChar(j, FG_FROG_Y - FG_ROAD_LANES, '-');
			}

			// Draw mid pavement borders
			if (i == (height - m_pave_lim.bot))
			{
				for (int j = 0; j < width; j++)
					m_backBuffer.setChar(j, FG_FROG_Y - FG_ROAD_LANES, '-');
			}

			if (i == (height - m_river_lim.bot)) {
				for (int j = 0; j < width; j++)
					m_backBuffer.setChar(j, FG_FROG_Y - FG_ROAD_LANES, '-');
			}
		
#pragma endregion
		}
	}
}

void GameSource::FG_CheckCollision(int width, int height)
{
}

void GameSource::FG_CheckGameCondition()
{
}

void GameSource::SI_ProcessInput()
{
	m_si_player->Update();
	m_si_missile.FireMissile(*m_si_player);
}

void GameSource::SI_UpdateGame()
{
#pragma region Alien Movement

	// Unfortunately, this implementation causes the game to move at an unplayable
	// speed and as such, is not being used.

	int speed;
	speed = m_si_aliens[0].GetYPos() > SI_SPEED ? 2 : 1;

	for (int i = 0; i < sizeof m_si_aliens / sizeof m_si_aliens[0]; i++) {
		//m_si_aliens[i].SetSpeed(speed);
		m_si_aliens[i].Update();
	}

#pragma endregion
}

void GameSource::SetGameState(int state)
{
	m_gamestate = static_cast<gameState>(state); //casting lecture
}

void GameSource::SI_SetGamePositions(int width, int height)  //potentially save and read from textfile?
{ //Break here to show copies (Dynamic vs Static array)

#pragma region Aliens
	for (int i = 0; i < height; i++)
	{	
		for (int j = 0; j < width; j++) // Draw aliens
		{
			for (int k = 0; k < SI_ALIENS; k++)
			{
				if ((m_si_aliens[k].GetYPos() == i) && (m_si_aliens[k].GetXPos() == j))
				{
						m_backBuffer.setChar(m_si_aliens[k].GetXPos(),m_si_aliens[k].GetYPos(),m_si_aliens[k].GetChar());
				}
			}
		}
#pragma endregion

#pragma region Barriers Array
		if (i == (SI_BARRIER_Y))
		{
			for (int j = 0; j < width; j++)
			{
				for (int k = 0; k < sizeof m_si_barriers / sizeof m_si_barriers[k] ; k++)
				{
					if (m_si_barriers[k].GetXPos() == j)
					{
						if (m_si_barriers[k].GetState())
						{
							m_backBuffer.setChar(m_si_barriers[k].GetXPos(), SI_BARRIER_Y, m_si_barriers[k].GetBarrierChar());
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
		if (i == (SI_PLAYER_Y)) //Draw player
		{
			for (int j = 0; j < width; j++)
				if (m_si_player->GetXPos() == j)
				{
					m_backBuffer.setChar(m_si_player->GetXPos(), SI_PLAYER_Y, '^');
				}
		}
#pragma endregion
		  
#pragma region Ground
		else if (i == (SI_GROUND_Y))	//Draw ground
		{
			for (int j = 0; j < width; j++)
				m_backBuffer.setChar(j, SI_GROUND_Y, '-');
		}
	}
#pragma endregion

#pragma region Missile
	if (m_si_missile.GetState())
	{
		m_backBuffer.setChar(m_si_missile.GetXPos(), m_si_missile.GetYPos(), '!');
		m_si_missile.Update();
	}
#pragma endregion
}

void GameSource::SI_CheckCollision(int width, int height)
{
#pragma region Barrier
	for (Barrier& barrier : m_si_barriers)
	{
		if (barrier.GetState()) {
			if (barrier.GetXPos() == m_si_missile.GetXPos() && barrier.GetYPos() == m_si_missile.GetYPos())
			{
				//barrier.TakeDamage(m_missile.GetDamage());
				barrier.SetState(false);
				m_si_missile.SetState(false);
			}
		}
	}
#pragma endregion

#pragma region Alien
	for (Alien& alien : m_si_aliens)
	{
		if (alien.GetState()) {
			// check one block below for the missile as well as on the aliens coords
			// this gives the player a little bit of grace with aiming
			if (alien.GetXPos() == m_si_missile.GetXPos() && (alien.GetYPos() == m_si_missile.GetYPos() || alien.GetYPos() == m_si_missile.GetYPos() + 1))
			{
				alien.SetPos(-10, -10);	// send alien to purgatory
				m_si_missile.SetXPos(-10);	// send missile to purgatory
				alien.SetState(false);
				m_si_missile.SetState(false);
			}
		}
	}
#pragma endregion

SI_CheckGameCondition();

}

void GameSource::DrawGame(int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) 
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
			this->InitSpaceInvaders();
			this->SI_ProcessInput();
			this->SI_UpdateGame();
			this->SI_SetGamePositions(m_game_window.GetWidth(), m_game_window.GetHeight());
			this->SI_CheckCollision(m_game_window.GetWidth(), m_game_window.GetHeight());
			this->SwapBuffers();
			this->DrawGame(m_game_window.GetWidth(), m_game_window.GetHeight());
			break;
		case FROGGER:
			this->InitFrogger();
			this->FG_ProcessInput();
			this->FG_UpdateGame();
			this->FG_SetGamePositions(m_game_window.GetWidth(), m_game_window.GetHeight());
			this->FG_CheckCollision(m_game_window.GetWidth(), m_game_window.GetHeight());
			this->SwapBuffers();
			this->DrawGame(m_game_window.GetWidth(), m_game_window.GetHeight());
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

void GameSource::SI_CheckGameCondition()
{
	// loop through aliens, check m_ypos if its on the ground
	// if it is, and any aliens are alive (state == false) player loses
	// otherwise player has won

	for (int i = 0; i < sizeof m_si_aliens / sizeof m_si_aliens[0]; i++) {
		
		// if all enemy states are false, player wins
		
		if (m_si_aliens[i].GetYPos() >= SI_PLAYER_Y - 1) {
			m_gamestate = LOSS;
		}
		
	}
}