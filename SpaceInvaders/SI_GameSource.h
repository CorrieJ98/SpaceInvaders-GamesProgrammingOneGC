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
#define BARRIER 22
#define SPEED 20
#define ALIEN 20

class SI_GameSource
{
public:
	SI_GameSource();
	~SI_GameSource();

	void SetPlayerPosition();
	void SetAlienPositions();
	void SetBarrierPositions();
	void CreateBuffers(int width, int height);
	void InitaliseGame();
	void ProcessInput();
	void SwapBuffers();
	void UpdateGame();
	void SetGameState(int x);
	void SetGamePositions(int width, int height);
	void CheckCollision(int width, int height);
	void DrawGame(int width, int height);
	void GameLoop();

	

private:
	bool run_loop_ = true;
	Window gamewindow_;
	Ground ground_;

	std::unique_ptr<Menu> menu_ = std::make_unique<Menu>(); //smart pointers
	
	Player* player_;
	Missile missile_;

	//std::vector<Barrier> vbarriers_;
	Barrier barriers_[BARRIER];
	Alien aliens_[ALIEN];
	ScreenBuffer front_buffer_;
	ScreenBuffer rear_buffer_;

	enum GameState
	{
		kStartScreen,
		kExit,
		kSpaceInvaders,
		kPong
	};

	GameState gs_;
};