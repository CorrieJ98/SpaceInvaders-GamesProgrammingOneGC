#pragma once
#include "gameobject.h"

class Player : public GameObject
{
public:
	Player() {};
	~Player() {};

	void Update() override;
	void Draw() override;

	void Shoot();
	void Move();

};
