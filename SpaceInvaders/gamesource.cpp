#include "GameSource.h"

int Alien::speed_ = 2; // define static variable

extern int menuChoice; 

GameSource::GameSource(): player_(new Player()), vbarriers_(20) {} // heap allocatoin (explain new and pointer)

GameSource::~GameSource()
{
	delete player_;
}

void GameSource::SetPlayerPosition()
{
	player_->SetXPos(15);
	player_->SetYPos(PLAYER);
}

void GameSource::SetAlienPositions()
{
	for (int i = 0; i < 20; i++)
	{
		aliens_[i].SetPosition(i*3, 1);
	}
}

void GameSource::SetBarrierPositions()
{
	/*for (int i = 0; i < 20; i++)
	{	
		// relevant for std::vector<Barrier>
		barriers_.emplace_back(Barrier());
	}*/

	for (int i = 0; i < sizeof vbarriers_ / sizeof vbarriers_[0]; ++i) {
		
	}

	for (int i = 0; i < 5; i++)
	{
		vbarriers_[i].SetPosition(i+10, BARRIER);
	}
	for (int i = 5; i < 10; i++)
	{
		vbarriers_[i].SetPosition(i+25, BARRIER);
	}
	for (int i = 10; i < 15; i++)
	{
		vbarriers_[i].SetPosition(i+40, BARRIER);
	}
	for (int i = 15; i < 20; i++)
	{
		vbarriers_[i].SetPosition(i+55, BARRIER);
	}
}

void GameSource::CreateBuffers(int width, int height)
{
	// create the front buffer
	front_buffer_ = ScreenBuffer(width, height);
}


void GameSource::InitaliseGame()
{
	gamewindow_.SetWindow(40, 30);	
	CreateBuffers(80,30);
	SetPlayerPosition();
	SetAlienPositions();
	SetBarrierPositions();

	gs_ = kStartScreen; // set starting gameState
}

void GameSource::ProcessInput()
{
	player_->Update();
	missile_.FireMissile(*player_);
}

// TODO speed updates
void GameSource::UpdateGame()
{
	int x;

	x = aliens_[0].GetYPos() > SPEED ? 2 : 1; //Ternary Operator - Same as below
	
	for (int i = 0; i < sizeof(aliens_) / sizeof(aliens_[0]); i++)
	{
		//aliens_[i].SetSpeed(x); // why is this terrible? (fix for CW?)
		// because its a static value, any change to one instance affects all of them.
	}

	//if (m_aliens[0].getYP() > SPEED)
	//{
	//	m_aliens[0].setSpeed(2);
	//}
	//else
	//	m_aliens[0].setSpeed(1);
}

void GameSource::SetGameState(int x)
{
	gs_ = static_cast<GameState>(x); //casting lecture
}

void GameSource::SetGamePositions(int width, int height)  //potentially save and read from textfile?
{ //Break here to show copies (Dynamic vs Static array)
	for (int i = 0; i < height; i++)
	{	
		for (int j = 0; j < width; j++) // draw aliens
		{
			for (int aNo = 0; aNo < 20; aNo++) //3rd for loop, can this be improved? 2D array
			{
				if ((aliens_[aNo].GetYPos() == i) && (aliens_[aNo].GetXPos() == j))
				{
						front_buffer_.SetChar(aliens_[aNo].GetXPos(),aliens_[aNo].GetYPos(),'X');
				}
			}
		}

		if (i == (BARRIER)) //draw barriers (explain the macro (openGL))
		{
			for (int j = 0; j < width; j++)
			{
				for (unsigned int bNo = 0; bNo < vbarriers_.size(); bNo++) // unsigned explain
				{
					if (vbarriers_[bNo].GetXPos() == j)
					{
						if (vbarriers_[bNo].GetState())
						{
							front_buffer_.SetChar(vbarriers_[bNo].GetXPos(), BARRIER, '=');
						}
					}
				}
			}
		}

		if (i == (PLAYER)) //draw player
		{
			for (int j = 0; j < width; j++)
				if (player_->GetXPos() == j)
				{
					front_buffer_.SetChar(player_->GetXPos(), PLAYER, '^');
				}
		}


		else if (i == (GROUND))	//draw ground
		{
			for (int j = 0; j < width; j++)
				front_buffer_.SetChar(j, GROUND, '-');
		}
	}

	if (missile_.GetState())
	{
		
		front_buffer_.SetChar(missile_.GetXPos(), missile_.GetYPos(), missile_.missile_char_);
		missile_.Update();
	}
}

void GameSource::CheckCollision(int width, int height)
{
	// missile vs barrier collision
	for (int i = 0; i < sizeof vbarriers_ / sizeof vbarriers_[0]; i++) {
		if (vbarriers_[i].GetXPos() == missile_.GetXPos() 
		&& vbarriers_[i].GetYPos() == missile_.GetXPos()) {


			vbarriers_[i].SetActive(false);
			//barriers_[i].TakeDamage(1);
		}
	}

	// missile vs alien collision
	for (int i = 0; i < sizeof aliens_ / sizeof aliens_[0]; i++) {
		if (aliens_[i].GetXPos() == aliens_[i].GetXPos()
		&& aliens_[i].GetYPos() == missile_.GetXPos()) {
				
			aliens_[i].SetActive(false);

		}
	}
}

void GameSource::DrawGame(int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) 
		{
			gamewindow_.SetCursorPosition(j,i);
			std::cout << front_buffer_.GetChar(j,i);
		}
	}
}

void GameSource::GameLoop()
{
	while (gs_ != GameState::kExit)
	{
		switch (gs_)
		{
		case kStartScreen:
			menu_->Run();
			this->SetGameState(menuChoice);
			break;
		case kSpaceInvaders:
			this->ProcessInput();
			this->UpdateGame();
			this->SetGamePositions(gamewindow_.GetWidth(), gamewindow_.GetHeight());
			this->DrawGame(gamewindow_.GetWidth(), gamewindow_.GetHeight());
			break;
		}
	}
}
