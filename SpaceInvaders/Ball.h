#pragma once
#include "gameobject.h"

class Ball : GameObject {
public:
	// singleton as having several balls is neither pingable nor pongable
	Ball() {};

private:
	static const int kSpeed_ = 10;

};