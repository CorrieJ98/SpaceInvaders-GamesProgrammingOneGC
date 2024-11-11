#include "Player.h"


void player::shoot(){	

}

void player::move() {

}

void player::update() {

	// left arrow key
	if (GetKeyState(65) & 0x8000) {
		if (m_xpos < 1){
			m_xpos--;
		}
	}

	// right arrow key
	else if (GetKeyState(68) & 0x8000) {
		if (m_xpos < 79) {
			m_xpos++;
		}
	}
}

void player::draw() {
	std::cout << "A" << std::endl;
}
