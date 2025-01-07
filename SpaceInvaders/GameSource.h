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
	void DrawGame(int width, int height);
#pragma endregion

#pragma region Space Invaders Pub
	void InitSpaceInvaders();
	void SI_SetPlayerPos();
	void SI_SetAlienPos();
	void SI_SetBarrierPos();
	void SI_ProcessInput();
	void SI_UpdateGame();
	void SI_SetGamePositions(int width, int height);
	void SI_CheckCollision(int width, int height);
	void SI_CheckGameCondition();
#pragma endregion

#pragma region Frogger Pub
	void InitFrogger();
	void FG_SetPlayerPos();
	void FG_SetVehiclePos();
	void FG_SetLanes();
	void FG_ProcessInput();
	void FG_UpdateGame();
	void FG_SetGamePositions(int width, int height);
	void FG_CheckCollision(int width, int height);
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
		PONG,
		WIN,
		LOSS
	};
	gameState m_gamestate;

#pragma endregion

#pragma region Space Invaders Priv
	//Ground m_si_ground; obsolete
	Player* m_si_player;
	Missile m_si_missile;
	std::array<Barrier, SI_BARRIERS> m_si_barriers;
	std::array<Alien, SI_ALIENS> m_si_aliens;
#pragma endregion

#pragma region Frogger Priv
	Frog* m_fg_frog;
	Locale m_fg_locale;
	std::array<Log, FG_MAX_LOGS> m_fg_logs;
	std::array<Car, FG_MAX_CARS> m_fg_cars;
	std::array<LilyPad, FG_MAX_LILYPADS> m_fg_lilypads;
	std::array<Home, FG_HOMES> m_fg_homes;

	LaneLim m_start_lim;
	LaneLim m_road_lim;
	LaneLim m_pave_lim;
	LaneLim m_river_lim;
	LaneLim m_grass_lim;
#pragma endregion
};