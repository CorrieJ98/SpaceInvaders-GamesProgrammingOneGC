#include "fg_Car.h"

void Car::Update()
{
	if (m_state) {
		if (this->m_xpos < 0) {
			++m_xpos;

			if (this->m_xpos > GAMEWINX) {
				this->SetState(false);
			}
		}

		if (this->m_xpos > GAMEWINX) {
			--m_xpos;

			if (this->m_xpos < 0) {
				this->SetState(false);
			}
		}
	}
}


