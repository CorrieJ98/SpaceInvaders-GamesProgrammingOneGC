#include "gamesource.h"

void GameSource::InitialiseGame()
{
	game_window_.SetWindow(160, 50);
	player_.GameObject::Draw();
	player_.Draw();
}
void GameSource::SetGameState(int state)
{
	// TODO fix this truly disgusting line of code...
	game_state_ = static_cast<GameState>(state);
}

void GameSource::SetBarrierPositions() 
{
	for (int i = 0; i < 20; i++) {
		barriers_.push_back(Barrier());
	}

	for (int i = 0; i < 5; i++) {
		barriers_[i].SetXPos(i + 10);
	}

	for (int i = 5; i < 10; i++) {
		barriers_[i].SetXPos(i + 25);
	}

	for (int i = 10; i < 15; i++) {
		barriers_[i].SetXPos(i + 40);
	}
	for (int i = 15; i < 20; i++) {
		barriers_[i].SetXPos(i + 55);
	}
}

void GameSource::UpdateBarrierPositions()
{
}

void GameSource::SetPlayerPosition()
{
}

void GameSource::UpdatePlayerPosition()
{
}

void GameSource::ProcessInput()
{
	player_.Update();	
};

void GameSource::UpdateGame()
{
};

void GameSource::CreateScreenBuffers(int width, int height)
{
	front_buffer_ = ScreenBuffer(width, height);
	rear_buffer_ = ScreenBuffer(width, height);
}

void GameSource::DrawGame(int width, int height)
{
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			std::cout << front_buffer_.GetChar(j, i);
		}
	}

#pragma region legacy code
	// obsolete
	/*system("cls");
	for (int i = 0; i < height; i++)
	{
		bool is_drawn = false;	// new line if nothing is drawn

		// draw aliens
		for (int j = 0; j < width; j++) {
			bool is_alien_drawn = false;
			for (int a = 0; a < 20; a++) {
				if ((aliens_[a].get_yposition() == i) && (aliens_[a].get_xposition() == j)) {
					aliens_->Draw();
					is_drawn = true;
					is_alien_drawn = true;
				}
			}

			if (!is_alien_drawn) {
				std::cout << " ";
			}
		}

		// draw barriers
		if (i == (height - 8)) {
			std::cout << '\n';
			for (int j = 0; j < width; j++) {
				bool is_barriers_drawn = false;
				for (int b = 0; b < barriers_.size(); b++) {
					if (barriers_[b].get_xposition() == j) {
						barriers_[b].Draw();
						is_drawn = true;
						is_barriers_drawn = true;
					}
				}

				if (!is_barriers_drawn) {
					std::cout << " ";
				}
			}
		}

		// draw player
		if (i == (height - 2)) {
			std::cout << '\n';
			for (int j = 0; j < width; j++) {
				if (player_.get_xposition() > j) {
					std::cout << " ";
				}
				else if (player_.get_xposition() == j) {
					player_.Draw();
					is_drawn = true;
				}
			}
		}

		// draw ground

		else if (i == (height - 1)) {
			std::cout << '\n';
			for (int j = 0; j < width; j++) {
				ground_.Draw();
				is_drawn = true;
			}
			if (!is_drawn) {
				std::cout << '\n';
			}
		}
	}*/
#pragma endregion
}
void GameSource::SetEnemyPositions()
{
	for (int i = 0; i < 20; i++) {
		aliens_[i].SetPosition(i * 3, 1);
	}
}
void GameSource::UpdateEnemyPositions()
{
}
;

void GameSource::GameLoop()
{
	while (true)
	{
		ProcessInput();
		UpdateGame();
		DrawGame(game_window_.GetWidth(), game_window_.GetHeight());
	}
}