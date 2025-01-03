#include "fg_Locale.h"

void Locale::PopulateLanesArray()
{
	LaneTypes t = STARTPAVE;

	for (int i = 0; i < sizeof m_lanes / sizeof m_lanes[0]; i++) {

        m_lanes[i] = t;

        switch (i) {
        case FG_START_LANES:
            t = ROAD;
            break;

        case kOffsetMidPave:
            t = MIDPAVE;
            break;

        case kOffsetRiver:
            t = RIVER;
            break;

        case kOffsetGrass:
            t = GRASS;
            break;

        default:
            break;
        }
}

