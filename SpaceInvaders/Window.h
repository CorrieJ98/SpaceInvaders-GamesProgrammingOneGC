#pragma once
#include <iostream>
#include <windows.h>

class Window
{
public:	
	Window() {};

	void SetWindow(int m_width, int m_height, float scale);
	void setCursorPosition(int m_x, int y);

	int GetWidth() { return this->m_width; }

	int GetHeight() { return this->m_height; }

private:
	int m_width, m_height;
	float m_scale;
	HANDLE m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
};