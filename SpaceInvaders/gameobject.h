#pragma once
#include <iostream>
#include <string>
#include <Windows.h>

class gameobject
{
public:
	
	virtual void update() { std::cout << "called update() from gameobject class" << '\n'; };
	virtual void draw() { std::cout << "called draw() from gameobject class" << '\n'; };

	virtual void set_active(bool state);
	virtual void set_position(int x, int y);
	virtual void set_xposition(int x);
	virtual void set_yposition(int y);
	virtual int get_xposition();
	virtual int get_yposition();


protected:
	int m_xpos, m_ypos;
	bool m_state = false;
};

