#pragma once
#include "GameObject.h"

class Barrier : public GameObject
{
public:

	Barrier() : active_(true) {};
	
	Barrier(const Barrier& other) 
		: active_(other.active_){};
	
	~Barrier() {};

	void SetPosition(int x, int y);
	int GetXPos();
	int GetYPos();

	void SetState(bool state) { active_ = state; };
	bool GetState() { return active_; }
	void TakeDamage(int damage);
	

private:
	static int x_;
	int health_ = 2;
	bool active_;
};

