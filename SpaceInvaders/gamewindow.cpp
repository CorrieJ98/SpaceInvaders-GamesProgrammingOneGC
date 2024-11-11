#include "gamewindow.h"

void gamewindow::set_window(int width, int height) {

	this->m_width = width;
	this->m_height = height;

	SMALL_RECT windowSize = { 10, 10, width, height };
	if (!SetConsoleWindowInfo(hConsole, TRUE, &windowSize))
	{
		cout << "SetConsoleWindowInfo failed with error " << GetLastError() << endl;
	}

	if (!SetConsoleTitle(L"Space Invaders"))
	{
		cout << "SetConsoleTitle failed with error " << GetLastError() << endl;
	}
}

