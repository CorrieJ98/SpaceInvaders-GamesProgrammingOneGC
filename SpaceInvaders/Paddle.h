#pragma once
#include "gameobject.h"

class Paddle : GameObject {
public:
	Paddle();
	~Paddle();

	void Update() override;
	void Draw() override;

private:
	static const int kSpeed_ = 10;
};