#pragma once
#include <chrono>
#include <iostream>

struct Timer {
	std::chrono::steady_clock game_clock;
	bool running;
};