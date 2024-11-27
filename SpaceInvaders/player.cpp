#include "Player.h"


void Player::Shoot(){	

}

void Player::Move() {

}

void Player::Update() {

	// left arrow key
	if (GetKeyState(65) & 0x8000) {
		if (xpos_ < 1){
			xpos_--;
		}
	}

	// right arrow key
	else if (GetKeyState(68) & 0x8000) {
		if (xpos_ < 79) {
			xpos_++;
		}
	}
}

void Player::Draw() {
	std::cout << "A" << std::endl;
}
