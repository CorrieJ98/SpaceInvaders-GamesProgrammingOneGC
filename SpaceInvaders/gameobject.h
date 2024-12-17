#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

class GameObject
{
public:

	GameObject() {}; // explain warning and how to fix it (something they should do for CW)
	GameObject(int m_x): m_xpos(m_x), m_ypos(0) {}; // overloading to initalise from the derived class
	~GameObject() {}; //destuctor

	virtual void Update() {};
	virtual void Draw() { std::cout << "called from based" << '\n'; };

	int GetXPos() { return this->m_xpos; };
	int GetYPos() { return this->m_ypos; };

	void SetXPos(int m_x) { this->m_xpos = m_x; };
	void SetYPos(int y) { this->m_ypos = y; };

protected:
	int m_xpos, m_ypos;
};