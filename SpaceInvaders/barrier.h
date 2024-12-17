#pragma once
#include "GameObject.h"

class Barrier : public GameObject
{
public:

	Barrier() : isActive(true) {};
	
	Barrier(const Barrier& other) 
		: isActive(other.isActive){};
	
	~Barrier() {};

	void setPostion(int x, int y);
	int getXPostion();
	int getYPostion();

	void setState(bool in) { isActive = in; };
	bool getState() { return isActive; }

private:
	static int x;
	bool isActive;
};

