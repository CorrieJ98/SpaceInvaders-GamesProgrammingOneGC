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
#define BARRIER_Y 25
#define BARRIERS 20
#define SPEED 20
#define ALIEN_Y 1
#define ALIENS 20

class GameSource
{
public:
	GameSource();
	~GameSource();

	
	void CreateBuffers(int width, int height);
	void SwapBuffers();
	void GameLoop();
	void InitGame();
	void InitSpaceInvaders();
	void InitFrogger();

	void ProcessInput(int menu_choice);
	void UpdateGame(int menu_choice);
	void SetGameState(int state);
	void SetGamePositions(int width, int height, int menu_choice);
	void CheckCollision(int width, int height, int menu_choice);
	void CheckGameCondition();
	void DrawGame(int width, int height);
	
	void SetPlayerPos();
	void SetAlienPos();
	void SetBarrierPos();
	
private:
	bool m_run_loop = true;
	Window m_game_window;
	Ground m_game_ground;

	std::unique_ptr<Menu> m_menu = std::make_unique<Menu>(); //smart pointers
	
	Player* m_player; // raw pointer lecture
	Missile m_missile;
	//std::vector<Barrier> m_vbarriers;
	std::array<Barrier, BARRIERS> m_barriers;
	std::array<Alien, ALIENS> m_aliens;
	ScreenBuffer m_frontBuffer;
	ScreenBuffer m_backBuffer;
	ScreenBuffer m_resetBuffer;

	enum gameState 
	{
		STARTSCREEN,
		EXIT,
		SPACE_INVADERS,
		FROGGER,
		WIN,
		LOSS
	};

	gameState m_gamestate;
};