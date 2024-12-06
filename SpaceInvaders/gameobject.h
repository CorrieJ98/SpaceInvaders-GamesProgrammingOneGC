#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

class GameObject
{
public:

	GameObject() {}; // explain warning and how to fix it (something they should do for CW)
	GameObject(int x): xpos_(x), ypos_(0) {}; // overloading to initalise from the derived class
	~GameObject() {}; //destuctor

	virtual void Update() { std::cout << "called update() from gameobject class" << '\n'; };
	virtual void Draw() { std::cout << "called draw() from gameobject class" << '\n'; };

	virtual void SetActive(bool state);
	virtual void SetPosition(int x, int y);
	virtual void SetXPos(int x);
	virtual void SetYPos(int y);
	virtual int GetXPos();
	virtual int GetYPos();

#pragma region obsolete
	/*virtual void Update() {std::cout << "called update() from gameobject class" };
	virtual void Draw() { std::cout << "called draw() from gameobject class" << '\n'; };

	int GetXPos() { return this->xpos_; };
	int GetYPos() { return this->ypos_; };

	void SetXPos(int x) { this->xpos_ = x; };
	void SetYPos(int y) { this->ypos_ = y; };*/
#pragma endregion

protected:
	int xpos_, ypos_;
	bool state_;
};