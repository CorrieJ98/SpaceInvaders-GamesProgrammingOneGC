#pragma once
#include <iostream>
#include <windows.h>

using namespace std;

class gamewindow
{
public:	
	gamewindow() {};

	void set_window(int width, int height);

	int get_width() { return this->m_width; }

	int get_height() { return this->m_height; }

private:
	int m_width, m_height;	
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
};