#include "fg_Locale.h"

void Locale::SetInitialLaneDepth()
{
	for (auto& row : m_lanes) {
		for (LaneTypes& types : row) {
			/*
				set row 0 to LaneType.STARTPAVE
				set rows 1-4 to LaneType.ROAD
				set row 5 to LaneType.MIDPAVE
				set row 6-10 to LaneType.RIVER
				set row 11 to LaneType.TOPGRASS
			*/


		}
	}
}
