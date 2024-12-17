#pragma once
#include <iostream>
#include <string>
#include "Window.h"
#include "Ground.h"
#include "Player.h"
#include "Alien.h"
#include "Barrier.h"
#include "Menu.h"
#include "Missile.h"
#include "ScreenBuffer.h"
#include <array>
#include <vector>

#define GROUND 29
#define PLAYER 28
#define BARRIER_Y 22
#define BARRIERS 20
#define SPEED 20
#define ALIEN_Y 1
#define ALIEN 20

class GameSource
{
public:
	GameSource();
	~GameSource();

	void SetPlayerPos();
	void SetAlienPos();
	void SetBarrierPos();
	void CreateBuffers(int width, int height);
	void InitGame();
	void ProcessInput();
	void SwapBuffers();
	void UpdateGame();
	void SetGameState(int state);
	void SetGamePositions(int width, int height);
	void CheckCollision(int width, int height);
	void DrawGame(int width, int height);
	void GameLoop();

	

private:
	bool m_run_loop = true;
	Window m_game_window; // explain m_ convention
	Ground m_game_ground;

	std::unique_ptr<Menu> m_menu = std::make_unique<Menu>(); //smart pointers
	
	Player* m_player; // raw pointer lecture
	Missile m_missile;
	std::array<Barrier, BARRIERS> m_barriers;
	std::array<Alien, ALIEN> m_aliens;
	ScreenBuffer m_frontBuffer;
	ScreenBuffer m_backBuffer;
	ScreenBuffer m_resetBuffer;
	std::vector<Barrier> m_vbarriers;

	enum gameState 
	{
		STARTSCREEN,
		EXIT,
		SPACE_INVADERS,
		FROGGER
	};

	gameState m_gamestate;
};