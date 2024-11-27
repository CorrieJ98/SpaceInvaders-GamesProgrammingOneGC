#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

class GameObject
{
public:
	
	virtual void Update() { std::cout << "called update() from gameobject class" << '\n'; };
	virtual void Draw() { std::cout << "called draw() from gameobject class" << '\n'; };

	virtual void SetActive(bool state);
	virtual void SetPosition(int x, int y);
	virtual void SetXPos(int x);
	virtual void SetYPos(int y);
	virtual int GetXPos();
	virtual int GetYPos();


protected:
	int xpos_, ypos_;
	bool state_ = false;
};

