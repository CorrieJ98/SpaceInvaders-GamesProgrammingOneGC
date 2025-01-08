#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

class GameObject abstract
{
public:

	GameObject() {}; 
	GameObject(int x): m_xpos(x), m_ypos(0) {};
	GameObject(int x, int y) : m_xpos(x), m_ypos(y) {};
	~GameObject() {};

	virtual void Update() { std::cout << "called Update from base" << '\n'; };
	virtual void Draw() { std::cout << "called Draw from base" << '\n'; };

	int GetXPos() { return this->m_xpos; };
	int GetYPos() { return this->m_ypos; };

	void SetXPos(int x) { this->m_xpos = x; };
	void SetYPos(int y) { this->m_ypos = y; };

protected:
	int m_xpos;
	int m_ypos;
};