#include "Window.h"

void Window::SetWindow(int width, int height, float scale) {

	this->m_width = width;
	this->m_height = height;

	SMALL_RECT windowSize = { 10, 10, width+20, height+20};
	if (!SetConsoleWindowInfo(m_hConsole, TRUE, &windowSize))
	{
		std::cout << "SetConsoleWindowInfo failed with error " << GetLastError() << '\n';
	}

	if (!SetConsoleTitle(L"Command Line Gaming")) // cover sting types (termination)
	{
		std::cout << "SetConsoleTitle failed with error " << GetLastError() << '\n';
	}
	
#pragma region hideCursor
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE); // this code hides the cursor
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = false; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
#pragma endregion

#pragma region changeFont
	CONSOLE_FONT_INFOEX cfi = { sizeof(cfi) };

	HANDLE hcsb = CreateFileA("CONOUT$", GENERIC_WRITE | GENERIC_READ,
		FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	// Populate cfi with the screen buffer's current font info
	GetCurrentConsoleFontEx(hcsb, FALSE, &cfi);

	// Modify the font size in cfi
	cfi.dwFontSize.X *= scale;
	cfi.dwFontSize.Y *= scale;

	// Use cfi to set the screen buffer's new font
	SetCurrentConsoleFontEx(hcsb, FALSE, &cfi);
#pragma endregion
}

void Window::setCursorPosition(int m_x, int y)
{
	static const HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	std::cout.flush();
	COORD coord = { (SHORT)m_x, (SHORT)y };
	SetConsoleCursorPosition(hOut, coord);
}

