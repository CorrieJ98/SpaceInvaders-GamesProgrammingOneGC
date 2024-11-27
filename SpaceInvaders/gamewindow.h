#pragma once
#include <iostream>
#include <windows.h>

class GameWindow
{
public:	
	GameWindow() {};

	void SetWindow(int width, int height);
	int GetWidth() { return this->width_; }
	int GetHeight() { return this->height_; }

private:
	int width_, height_;	
	HANDLE hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);
};