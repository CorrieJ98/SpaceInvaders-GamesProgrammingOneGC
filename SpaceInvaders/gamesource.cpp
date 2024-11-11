#include "gamesource.h"

void gamesource::initaliseGame()
{
	gameWindow.set_window(160, 50);
	player.gameobject::draw();
	player.draw();
};

void gamesource::set_barrier_positions() 
{
	for (int i = 0; i < 20; i++) {
		barriers.push_back(barrier());
	}

	for (int i = 0; i < 5; i++) {
		barriers[i].set_xposition(i + 10);
	}

	for (int i = 5; i < 10; i++) {
		barriers[i].set_xposition(i + 25);
	}

	for (int i = 10; i < 15; i++) {
		barriers[i].set_xposition(i + 40);
	}
	for (int i = 15; i < 20; i++) {
		barriers[i].set_xposition(i + 55);
	}
}

void gamesource::update_barrier_positions()
{
}

void gamesource::set_player_position()
{
}

void gamesource::update_player_position()
{
}

void gamesource::processInput()
{
	player.update();
};

void gamesource::updateGame()
{
};

void gamesource::drawGame(int width, int height)
{
	system("cls");
	for (int i = 0; i < height; i++)
	{
		bool is_drawn = false;	// new line if nothing is drawn

		// draw aliens
		for (int j = 0; j < width; j++) {
			bool is_alien_drawn = false;
			for (int a = 0; a < 20; a++) {
				if ((aliens[a].get_yposition() == i) && (aliens[a].get_xposition() == j)) {
					aliens->draw();
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
				for (int b = 0; b < barriers.size(); b++) {
					if (barriers[b].get_xposition() == j) {
						barriers[b].draw();
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
				if (player.get_xposition() > j) {
					std::cout << " ";
				}
				else if (player.get_xposition() == j) {
					player.draw();
					is_drawn = true;
				}
			}
		}

		// draw ground

		else if (i == (height - 1)) {
			std::cout << '\n';
			for (int j = 0; j < width; j++) {
				gameGround.draw();
				is_drawn = true;
			}
			if (!is_drawn) {
				std::cout << '\n';
			}
		}
	}

}
void gamesource::set_enemy_positions()
{
	for (int i = 0; i < 20; i++) {
		aliens[i].set_position(i * 3, 1);
	}
}
void gamesource::update_enemy_positions()
{
}
;

void gamesource::gameLoop()
{
	while (true)
	{
		processInput();
		updateGame();
		drawGame(gameWindow.get_width(), gameWindow.get_height());
	}
}