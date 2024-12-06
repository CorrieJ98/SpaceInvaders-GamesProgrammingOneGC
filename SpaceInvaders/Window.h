#pragma once
#include <iostream>
#include <windows.h>

class Window
{
public:	
	Window() {};

	void SetWindow(int width, int height);
	void SetCursorPosition(int x, int y);

	int GetWidth() { return this->width_; }

	int GetHeight() { return this->height_; }

private:
	int width_, height_;	
	HANDLE hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);
};