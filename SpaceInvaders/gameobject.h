#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

class GameObject
{
public:

	GameObject() {}; 
	GameObject(int x): m_xpos(x), m_ypos(0) {};
	~GameObject() {};

	virtual void Update() { std::cout << "called Update from base" << '\n'; };
	virtual void Draw() { std::cout << "called Draw from base" << '\n'; };

	int GetXPos() { return this->m_xpos; };
	int GetYPos() { return this->m_ypos; };

	void SetXPos(int m_x) { this->m_xpos = m_x; };
	void SetYPos(int y) { this->m_ypos = y; };

protected:
	int m_xpos, m_ypos;
};