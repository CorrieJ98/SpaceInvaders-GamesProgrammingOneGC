#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

class GameObject
{
public:

	GameObject() {};
	GameObject(int x, int y) : xpos_(x), ypos_(y) {};
	GameObject(int x, int y, bool state) : xpos_(x), ypos_(y), state_(state) {};
	~GameObject() {};

	virtual void Update() { std::cout << "called Update from base class" << '\n'; };
	virtual void Draw() { std::cout << "called Draw from base class" << '\n'; };

	virtual void SetActive(bool state);
	virtual void SetPosition(int x, int y);
	virtual void SetXPos(int x);
	virtual void SetYPos(int y);
	virtual int GetXPos();
	virtual int GetYPos();

protected:
	int xpos_ = 0, ypos_ = 0;
	bool state_ = false;
};