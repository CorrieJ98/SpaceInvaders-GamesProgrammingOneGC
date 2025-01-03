#pragma once
#include <iostream>
#include <string>
#include <array>
#include "custom_macros.h"
#include "Window.h"
#include "Menu.h"
#include "ScreenBuffer.h"

#include "si_Ground.h"
#include "si_Player.h"
#include "si_Alien.h"
#include "si_Barrier.h"
#include "si_Missile.h"

#include "fg_Frog.h"
#include "fg_Car.h"
#include "fg_Home.h"
#include "fg_LilyPad.h"
#include "fg_Log.h"
#include "fg_Locale.h"

class GameSource
{
public:
	GameSource();
	~GameSource();

#pragma region Universal Pub
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

#pragma region Space Invaders Pub
	/*
	All declarations relevant to Space Invaders are prefixed with
	SI if called or otherwise accessed from outwith the scope
	of Space Invaders (ie from main menu). Declarations which are
	found localised entirely to Space Invaders may not have this
	prefix.
	*/

	void InitSpaceInvaders();
	void SI_SetPlayerPos();
	void SI_SetAlienPos();
	void SI_SetBarrierPos();
	void SI_CheckGameCondition();
#pragma endregion

#pragma region Frogger Pub
	/*
	All declarations relevant to Frogger are prefixed with
	FG unless called or otherwise accessed from outwith 
	the scope of Frogger (ie from main menu)
	*/

	void InitFrogger();
	void FG_SetPlayerPos();
	void FG_SetVehiclePos();
	void FG_SetLanes();
	void FG_CheckGameCondition();
#pragma endregion


private:
#pragma region Universal Priv
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

#pragma region Space Invaders Priv
	Ground m_si_ground;
	Player* m_si_player; // raw pointer lecture
	Missile m_si_missile;
	std::array<Barrier, SI_BARRIERS> m_si_barriers;
	std::array<Alien, SI_ALIENS> m_si_aliens;
#pragma endregion

#pragma region Frogger Priv
	
#pragma endregion
};