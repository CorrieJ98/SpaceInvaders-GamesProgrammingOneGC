#pragma once
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "screenbuffer.h"
#include "gamewindow.h"
#include "gameground.h"
#include "gameobject.h"
#include "player.h"
#include "enemy.h"
#include "barrier.h"
#include "missile.h"

class GameSource
{
public:
	GameSource(){};

	void InitialiseGame();
	void SetGameState(int state);

	void ProcessInput();
	void GameLoop();
	void UpdateGame();

	void CreateScreenBuffers(int width, int height);
	void DrawGame(int width, int height);

	void SetEnemyPositions();
	void UpdateEnemyPositions();

	void SetBarrierPositions();
	void UpdateBarrierPositions();

	void SetPlayerPosition();
	void UpdatePlayerPosition();

private:
	bool run_loop_ = true;
	GameWindow game_window_;

	ScreenBuffer front_buffer_;
	ScreenBuffer rear_buffer_;

	Player player_;
	Ground ground_;
	std::vector<Barrier> barriers_;
	Enemy aliens_[20];
	
	enum GameState {
		kStartScreen,
		kLevel1,
		kExit
	};

	GameState game_state_;
};