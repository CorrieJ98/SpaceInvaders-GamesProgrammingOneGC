#include "GameSource.h"

int Alien::m_speed; // define static variable

extern int menuChoice; 

GameSource::GameSource(): m_player(new Player()), m_barriers(20) {} // heap allocatoin (explain new and pointer)

GameSource::~GameSource()
{
	delete m_player;
}; // ";" is not needed but is will not break the code

void GameSource::setPlayerPoisiton()
{
	m_player->setXPos(15);
	m_player->setYPos(PLAYER);
}

void GameSource::setAlienPositions()
{
	for (int i = 0; i < 20; i++)
	{
		m_aliens[i].setPostion(i*3, 1);
	}
}

void GameSource::setBarrierPositions()
{
	for (int i = 0; i < 20; i++)
	{
		m_barriers.emplace_back(Barrier());
	}

	for (int i = 0; i < 5; i++)
	{
		m_barriers[i].setPostion(i+10, BARRIER);
	}
	for (int i = 5; i < 10; i++)
	{
		m_barriers[i].setPostion(i+25, BARRIER);
	}
	for (int i = 10; i < 15; i++)
	{
		m_barriers[i].setPostion(i+40, BARRIER);
	}
	for (int i = 15; i < 20; i++)
	{
		m_barriers[i].setPostion(i+55, BARRIER);
	}
}

void GameSource::createBuffers(int width, int height)
{
	// create the front buffer
	m_frontBuffer = ScreenBuffer(width, height);
	// create the back buffer
	m_backBuffer = ScreenBuffer(width, height);
	// create the reset buffer
	m_resetBuffer = ScreenBuffer(width, height);

	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			m_resetBuffer.setChar(i,j,' ');

	m_frontBuffer = m_resetBuffer;
	m_backBuffer = m_resetBuffer;
}

void GameSource::swapBuffers()
{
	std::swap(m_frontBuffer, m_backBuffer);  // Move assignment
	m_backBuffer = m_resetBuffer;   // Move assignment
}


void GameSource::initaliseGame()
{
	m_gameWindow.setWindow(80, 30);
	setPlayerPoisiton();
	setAlienPositions();
	setBarrierPositions();
	createBuffers(80,30);
	gS = STARTSCREEN; // set starting gameState
}

void GameSource::processInput()
{
	m_player->update();
	m_missle.fireMissle(*m_player);
}

void GameSource::updateGame()
{
	int x;

	x = m_aliens[0].getYP() > SPEED ? 2 : 1; //Ternary Operator - Same as below
	
	for (int i = 0; i < sizeof(m_aliens) / sizeof(m_aliens[0]); i++) // explain sizeof
		m_aliens[i].setSpeed(x); // why is this terrible? (fix for CW?)

	//if (m_aliens[0].getYP() > SPEED)
	//{
	//	m_aliens[0].setSpeed(2);
	//}
	//else
	//	m_aliens[0].setSpeed(1);
}

void GameSource::setGameState(int x)
{
	gS = static_cast<gameState>(x); //casting lecture
}

void GameSource::setGamePositions(int width, int height)  //potentially save and read from textfile?
{ //Break here to show copies (Dynamic vs Static array)
	for (int i = 0; i < height; i++)
	{	
		for (int j = 0; j < width; j++) // draw aliens
		{
			for (int aNo = 0; aNo < 20; aNo++) //3rd for loop, can this be improved? 2D array
			{
				if ((m_aliens[aNo].getYP() == i) && (m_aliens[aNo].getXP() == j))
				{
						m_backBuffer.setChar(m_aliens[aNo].getXP(),m_aliens[aNo].getYP(),'X');
				}
			}
		}

		if (i == (BARRIER)) //draw barriers (explain the macro (openGL))
		{
			for (int j = 0; j < width; j++)
			{
				for (unsigned int bNo = 0; bNo < m_barriers.size(); bNo++) // unsigned explain
				{
					if (m_barriers[bNo].getXPostion() == j)
					{
						if (m_barriers[bNo].getState())
						{
							m_backBuffer.setChar(m_barriers[bNo].getXPostion(), BARRIER, '=');
						}
					}
				}
			}
		}

		if (i == (PLAYER)) //draw player
		{
			for (int j = 0; j < width; j++)
				if (m_player->getXPos() == j)
				{
					m_backBuffer.setChar(m_player->getXPos(), PLAYER, '^');
				}
		}


		else if (i == (GROUND))	//draw ground
		{
			for (int j = 0; j < width; j++)
				m_backBuffer.setChar(j, GROUND, '-');
		}
	}

	if (m_missle.getState())
	{
		m_backBuffer.setChar(m_missle.getXPos(), m_missle.getYPos(), '!');
		m_missle.update();
	}
}

void GameSource::checkCollision(int width, int height)
{
	for (Barrier& element : m_barriers)
	{
		if (element.getXPostion() == m_missle.getXPos() && element.getYPostion() == m_missle.getYPos())
		{
				element.setState(false); //this bad naming
				m_missle.setActive(false);
		}
	}
}

void GameSource::drawGame(int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) 
		{
			m_gameWindow.setCursorPosition(j,i);
			std::cout << m_frontBuffer.getChar(j,i);
		}
	}
}

void GameSource::gameLoop()
{
	while (gS != gameState::EXIT)
	{
		switch (gS)
		{
		case STARTSCREEN:
			m_menu->run();
			this->setGameState(menuChoice);
			break;
		case LEVEL1:
			this->processInput();
			this->updateGame();
			this->setGamePositions(m_gameWindow.getWidth(), m_gameWindow.getHeight());
			this->checkCollision(m_gameWindow.getWidth(), m_gameWindow.getHeight());
			this->swapBuffers();
			this->drawGame(m_gameWindow.getWidth(), m_gameWindow.getHeight());
			break;
		}
	}
}
