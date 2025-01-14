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
		FG_PopulateVehicleArrays();
		FG_SetLanes();
		FG_SetCarPos();
		FG_SetLogPos();
		FG_SetLilypadPos();

		m_game_initialised = true;


		// TODO get characters moving across screen w/ collision
	}
}

void GameSource::FG_SetPlayerPos()
{
	m_fg_frog->SetXPos(40);
	m_fg_frog->SetYPos(FG_FROG_Y);
}

void GameSource::FG_PopulateVehicleArrays()
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

void GameSource::FG_SetCarPos()
{
	for (int i = 0; i < sizeof m_fg_cars / sizeof m_fg_cars[0]; i++)
	{
		m_fg_cars[i].SetPos(i * 3, m_road_lim.bot - (rand() % m_road_lim.size));
	}
}

void GameSource::FG_SetLogPos()
{
	for (int i = 0; i < sizeof m_fg_logs / sizeof m_fg_logs[0]; i++)
	{
		m_fg_logs[i].SetPos(i * 3, m_river_lim.bot - (rand() % m_river_lim.size));
	}
}

void GameSource::FG_SetLilypadPos()
{
	for (int i = 0; i < sizeof m_fg_lilypads / sizeof m_fg_lilypads[0]; i++)
	{
		m_fg_lilypads[i].SetPos(i * 3, m_river_lim.bot - (rand() % m_river_lim.size));
	}
}

void GameSource::FG_SetHomePos()
{
	// 8 . 16 . 16 . 16 . 8 //
	for (int i = 0; i < sizeof m_fg_homes / sizeof m_fg_homes[0]; i++) {
		m_fg_homes[i].SetPos((GAMEWINX / FG_HOMES) + (GAMEWINX / (2 * FG_HOMES)),m_river_lim.bot - 1);
	}
}

void GameSource::FG_SetLanes()
{
	this->m_start_lim.bot = GAMEWINY - 1;
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
	for (Car& car : m_fg_cars) {
		//car.SpawnVehicle(m_road_lim.bot, m_road_lim.size);
		car.Update();
	}

#pragma endregion

#pragma region Log Movement
	for (Log& log : m_fg_logs) {
		//log.SpawnVehicle(m_river_lim.bot, m_river_lim.size);
		log.Update();
	}

#pragma endregion

#pragma region Lilypad Movement
	for (LilyPad& lilypad : m_fg_lilypads) {
		//lilypad.SpawnVehicle(m_river_lim.bot, m_river_lim.size);
		lilypad.Update();
	}

#pragma endregion
}

void GameSource::FG_SetGamePositions(int width, int height)
{
	for (int i = 0; i < height; i++)		// screen height
	{
		for (int j = 0; j < width; j++) {	// screen width

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

#pragma region Cars
			/*for (int k = 0; k < FG_MAX_CARS; k++) {
				if ((m_fg_cars[k].GetYPos() == i) && (m_fg_cars[k].GetXPos() == j)) {
					m_backBuffer.setChar(m_fg_cars[k].GetXPos(), m_fg_cars[k].GetYPos(), m_fg_cars[k].GetChar());
				}
			}*/

			for (Car& car : m_fg_cars) {
				if ((car.GetYPos() == i) && (car.GetXPos() == j)) {
					m_backBuffer.setChar(car.GetXPos(), car.GetYPos(), car.GetChar());
				}
			}
#pragma endregion

#pragma region Logs
			/*for (int k = 0; k < FG_MAX_LOGS; k++) {
				if ((m_fg_logs[k].GetYPos() == i) && (m_fg_logs[k].GetXPos() == j)) {
					m_backBuffer.setChar(m_fg_cars[k].GetXPos(), m_fg_logs[k].GetYPos(), m_fg_logs[k].GetChar());
				}
			}*/

			for (Log& log : m_fg_logs) {
				if ((log.GetYPos() == i) && (log.GetXPos() == j)) {
					m_backBuffer.setChar(log.GetXPos(), log.GetYPos(), log.GetChar());
				}
			}
#pragma endregion
#pragma region Lilypads
			/*for (int k = 0; k < FG_MAX_LILYPADS; k++) {
				if ((m_fg_lilypads[k].GetYPos() == i) && (m_fg_lilypads[k].GetXPos() == j)) {
					m_backBuffer.setChar(m_fg_cars[k].GetXPos(), m_fg_lilypads[k].GetYPos(), m_fg_lilypads[k].GetChar());
				}
			}*/

			for (LilyPad& lilypad : m_fg_lilypads) {
				if ((lilypad.GetYPos() == i) && (lilypad.GetXPos() == j)) {
					m_backBuffer.setChar(lilypad.GetXPos(), lilypad.GetYPos(), lilypad.GetChar());
				}
			}
#pragma endregion

#pragma region Homes
			for (Home& home : m_fg_homes) {
				if ((home.GetYPos() == i) && (home.GetXPos() == j)) {
					m_backBuffer.setChar(home.GetXPos(), home.GetYPos(), home.GetChar());
				}
			}

#pragma region Lane Borders
			
			if (i == (m_start_lim.bot))
			{
				for (int j = 0; j < width; j++)
					m_backBuffer.setChar(j, m_start_lim.bot, '-');
			}

			if (i == (m_road_lim.bot))
			{
				for (int j = 0; j < width; j++)
					m_backBuffer.setChar(j, m_road_lim.bot, '-');
			}

			if (i == (m_road_lim.bot - m_road_lim.size))
			{
				for (int j = 0; j < width; j++)
					m_backBuffer.setChar(j, m_road_lim.bot - m_road_lim.size, '-');
			}

			if (i == (m_pave_lim.bot - m_pave_lim.size))
			{
				for (int j = 0; j < width; j++)
					m_backBuffer.setChar(j, m_pave_lim.bot - m_pave_lim.size, '-');
			}

			if (i == (m_river_lim.bot - m_river_lim.size))
			{
				for (int j = 0; j < width; j++)
					m_backBuffer.setChar(j, m_river_lim.bot - m_river_lim.size, '-');
			}

			if (i == (m_grass_lim.bot - m_grass_lim.size)) {
				for (int j = 0; j < width; j++)
					m_backBuffer.setChar(j, m_grass_lim.bot - m_grass_lim.size, '-');
			}
		
#pragma endregion
		}
	}
}

void GameSource::FG_CheckCollision(int width, int height)
{
	for (Log& log : m_fg_logs)
	{
		if (log.GetState()) {
			if (log.GetXPos() == m_fg_frog->GetXPos() && log.GetYPos() == m_fg_frog->GetYPos())
			{
				// if the frog stands on a log, match its speed
				m_fg_frog->SetSpeed(log.GetIsMovingRight(), log.GetSpeed());
				if (log.GetIsMovingRight()) {
					m_fg_frog->SetXPos(m_fg_frog->GetXPos() + 1);
				}else if(!log.GetIsMovingRight()){
					m_fg_frog->SetXPos(m_fg_frog->GetXPos() - 1);
				}
			}

			// reset its speed when it gets off the log
			m_fg_frog->SetSpeed(1);
		}
	}

	for (Car& car : m_fg_cars)
	{
		if (car.GetState()) {
			if (car.GetXPos() == m_fg_frog->GetXPos() && car.GetYPos() == m_fg_frog->GetYPos())
			{
				m_fg_frog->Die();
				FG_CheckGameCondition();
			}
		}
	}
}

void GameSource::FG_CheckGameCondition()
{
	if (m_fg_frog->GetLivesRemaining() <= 0) {
		m_gamestate = LOSS;
	}
}

void GameSource::SI_ProcessInput()
{
	m_si_player->Update();
	m_si_missile.FireMissile(*m_si_player);
}

void GameSource::SI_UpdateGame()
{
#pragma region Alien Movement

	// Unfortunately, this implementation causes the game to move
	// at an unplayable speed and as such, is not currently in use
	// nor is there an implementation in the Alien::Movement() method.

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
			this->SI_SetGamePositions(m_game_window.GetWidth(), m_game_window.GetHeight());
			this->SI_UpdateGame();
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
		case PONG:
			// personal project?? ;)
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