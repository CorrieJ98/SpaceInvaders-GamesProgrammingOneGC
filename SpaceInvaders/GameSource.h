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

#define SI_GROUND 29
#define SI_PLAYER 28
#define SI_BARRIER_Y 25
#define SI_BARRIERS 20
#define SI_ALIEN_Y 1
#define SI_ALIENS 20
#define SI_SPEED 20

class GameSource
{
public:
	GameSource();
	~GameSource();

#pragma region Universal Methods
	void CreateBuffers(int width, int height);
	void SwapBuffers();
	void GameLoop();
	void InitGame();
	void SetGameState(int state);
	void ProcessInput(int menu_choice);
	void UpdateGame(int menu_choice);
	void SetGamePositions(int width, int height, int menu_choice);
	void CheckCollision(int width, int height, int menu_choice);
	void DrawGame(int width, int height);
#pragma endregion

#pragma region Space Invaders
	/*
	All declarations relevant to Space Invaders are prefixed with
	SI_ unless called or otherwise accessed from outwith the scope
	of Space Invaders (ie from main menu)
	*/

	void InitSpaceInvaders();
	void SI_SetPlayerPos();
	void SI_SetAlienPos();
	void SI_SetBarrierPos();
	void SI_CheckGameCondition();
#pragma endregion

#pragma region Frogger
	/*
	All declarations relevant to Frogger are prefixed with
	FG_ unless called or otherwise accessed from outwith 
	the scope of Frogger (ie from main menu)
	*/
	void InitFrogger();
	void FG_SetPlayerPos();
	void FG_SetVehiclePos();
	void FG_SetRoads();
	void FG_CheckGameCondition();
#pragma endregion


private:
#pragma region Universal Declarations
	bool m_run_loop = true;
	bool m_game_initialised = false;
	std::unique_ptr<Menu> m_menu = std::make_unique<Menu>(); //smart pointers
	Window m_game_window;
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

#pragma endregion


#pragma region Space Invaders
	Ground m_game_ground;
	Player* m_player; // raw pointer lecture
	Missile m_missile;
	std::array<Barrier, SI_BARRIERS> m_barriers;
	std::array<Alien, SI_ALIENS> m_aliens;
#pragma endregion


	
};