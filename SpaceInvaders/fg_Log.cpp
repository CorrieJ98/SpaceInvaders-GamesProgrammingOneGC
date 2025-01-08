#include "fg_Log.h"

void Log::Update()
{
	if (m_state) {
		if (this->m_xpos <= 0) {
			++m_xpos;

			if (this->m_xpos > GAMEWINX) {
				this->SetState(false);
			}
		}

		if (this->m_xpos > GAMEWINX - 1) {
			--m_xpos;

			if (this->m_xpos < 1) {
				this->SetState(false);
			}
		}
	}
}
