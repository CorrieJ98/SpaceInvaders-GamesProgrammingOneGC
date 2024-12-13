#include "SI_GameSource.h"

int Alien::speed_ = 2; // define static variable

extern int menu_choice; 

SI_GameSource::SI_GameSource(): player_(new Player()), barriers_() {} // heap allocatoin (explain new and pointer)

SI_GameSource::~SI_GameSource()
{
	delete player_;
}

void SI_GameSource::SetPlayerPosition()
{
	player_->SetXPos(15);
	player_->SetYPos(PLAYER);
}

void SI_GameSource::SetAlienPositions()
{
	for (int i = 0; i < 20; i++)
	{
		aliens_[i].SetPosition(i*3, 1);
	}
}

void SI_GameSource::SetBarrierPositions()
{
	/*for (int i = 0; i < 20; i++)
	{	
		// relevant for std::vector<Barrier>
		barriers_.emplace_back(Barrier());
	}*/

	for (int i = 0; i < sizeof barriers_ / sizeof barriers_[0]; ++i) {
		barriers_[i] = Barrier();
	}

	for (int i = 0; i < 5; i++)
	{
		barriers_[i].SetPosition(i+10, BARRIER);
	}
	for (int i = 5; i < 10; i++)
	{
		barriers_[i].SetPosition(i+25, BARRIER);
	}
	for (int i = 10; i < 15; i++)
	{
		barriers_[i].SetPosition(i+40, BARRIER);
	}
	for (int i = 15; i < 20; i++)
	{
		barriers_[i].SetPosition(i+55, BARRIER);
	}
}

void SI_GameSource::CreateBuffers(int width, int height)
{
	// create the front buffer
	front_buffer_ = ScreenBuffer(width, height);
	// create the back buffer
	rear_buffer_ = ScreenBuffer(width, height);
	// create the reset buffer
	reset_buffer_ = ScreenBuffer(width, height);

	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			reset_buffer_.SetChar(i, j, ' ');

	front_buffer_ = reset_buffer_;
	rear_buffer_ = reset_buffer_;
}


void SI_GameSource::InitaliseGame()
{
	gamewindow_.SetWindow(40, 30);	
	CreateBuffers(80,30);
	SetPlayerPosition();
	SetAlienPositions();
	SetBarrierPositions();

	gs_ = kStartScreen; // set starting gameState
}

void SI_GameSource::ProcessInput()
{
	player_->Update();
	missile_.FireMissile(*player_);
}

/*
fatal exception thrown here. std::swap is the culprit. Check memory footprint of all buffers, ensure none of them overflow
*/
void SI_GameSource::SwapBuffers()
{
	std::swap(front_buffer_, rear_buffer_);  // Move assignment
	rear_buffer_ = reset_buffer_;   // Move assignment
}

// TODO speed updates
void SI_GameSource::UpdateGame()
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

void SI_GameSource::SetGameState(int x)
{
	gs_ = static_cast<GameState>(x); //casting lecture
}

void SI_GameSource::SetGamePositions(int width, int height)  //potentially save and read from textfile?
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
				for (unsigned int bNo = 0; bNo < (sizeof barriers_ / sizeof barriers_[0]); bNo++) // unsigned explain
				{
					if (barriers_[bNo].GetXPos() == j)
					{
						if (barriers_[bNo].GetState())
						{
							front_buffer_.SetChar(barriers_[bNo].GetXPos(), BARRIER, '=');
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
		front_buffer_.SetChar(missile_.GetXPos(), missile_.GetYPos(), missile_.kMissileChar_);
		missile_.Update();
	}
}

void SI_GameSource::CheckCollision(int width, int height)
{
	// missile vs barrier collision
	for (int i = 0; i < sizeof barriers_ / sizeof barriers_[0]; i++) {
		if (barriers_[i].GetXPos() == missile_.GetXPos() 
		&& barriers_[i].GetYPos() == missile_.GetXPos()) {


			//barriers_[i].SetActive(false);
			barriers_[i].TakeDamage(1);
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
void SI_GameSource::DrawGame(int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			gamewindow_.SetCursorPosition(j, i);
			std::cout << front_buffer_.GetChar(j, i);

			// fatal exception here, read access violation. Check GameSource line 94
		}
	}
}

void SI_GameSource::GameLoop()
{
	while (gs_ != GameState::kExit)
	{
		switch (gs_)
		{
		case kStartScreen:
			menu_->Run();
			this->SetGameState(menu_choice);
			break;
		case kSpaceInvaders:
			this->ProcessInput();
			this->UpdateGame();
			this->SetGamePositions(gamewindow_.GetWidth(), gamewindow_.GetHeight());
			//this->CheckCollision(gamewindow_.GetWidth(), gamewindow_.GetHeight());
			this->SwapBuffers();
			this->DrawGame(gamewindow_.GetWidth(), gamewindow_.GetHeight());
			break;
		}
	}
}
