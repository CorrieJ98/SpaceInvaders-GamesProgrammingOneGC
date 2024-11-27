#pragma once
#include "gameobject.h"

class Enemy : public GameObject
{
public:
	Enemy();

	void Shoot();
	void Die();

	void Update() override;
	void Draw() override;

	~Enemy();

private:
	int m_health = 1;
	int m_speed = 4;
};

