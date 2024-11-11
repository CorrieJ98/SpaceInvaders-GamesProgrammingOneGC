#pragma once
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "gamewindow.h"
#include "gameground.h"
#include "gameobject.h"
#include "player.h"
#include "enemy.h"
#include "barrier.h"
#include "missile.h"

class gamesource
{
public:
	gamesource(){};

	void initaliseGame();

	void processInput();
	void gameLoop();
	void updateGame();
	void drawGame(int width, int height);

	void set_enemy_positions();
	void update_enemy_positions();

	void set_barrier_positions();
	void update_barrier_positions();

	void set_player_position();
	void update_player_position();

private:
	bool m_runLoop = true;
	gamewindow gameWindow;
	gameground gameGround;
	player player;
	vector<barrier> barriers;
	enemy aliens[20];
	
};