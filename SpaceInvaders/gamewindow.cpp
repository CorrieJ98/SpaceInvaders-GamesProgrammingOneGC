#include "gamewindow.h"

void GameWindow::SetWindow(int width, int height) {

	this->width_ = width;
	this->height_ = height;

	SMALL_RECT windowSize = { 10, 10, width, height };
	if (!SetConsoleWindowInfo(hConsole_, TRUE, &windowSize))
	{
		std::cout << "SetConsoleWindowInfo failed with error " << GetLastError() << std::endl;
	}

	if (!SetConsoleTitle(L"Space Invaders"))
	{
		std::cout << "SetConsoleTitle failed with error " << GetLastError() << std::endl;
	}
}

