#pragma once
#include "GameObject.h"
#include "Player.h"

class Missile : public GameObject
{
public:
	Missile(): active_(false) {}
	void FireMissile(Player &p);
	void Update();
	void SetActive(bool state) { this->active_ = state; }
	bool GetState() { return this->active_; }


	// trying to dig through code to find this was
	// a nightmare so its here now
	static const char kMissileChar_ = '|';

private:
	bool active_;
};

