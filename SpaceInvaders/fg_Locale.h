#pragma once
#include <array>
#include "custom_macros.h"

class Locale {
public:
	Locale() {};

	void SetInitialLaneDepth();


private:
	inline enum LaneTypes {
		STARTPAVE,
		ROAD,
		MIDPAVE,
		RIVER,
		TOPGRASS
	};

	LaneTypes m_lanetypes;

	// array with 5 
	std::array<std::array<LaneTypes, 5>, FG_HOMES + FG_RIVER_LANES + FG_ROAD_LANES + 3> m_lanes;
};

/*

	I reckon this is the entirely wrong way to go about this. Check Locale.cpp
	for where I think I should be going, as well as l144 in GameSource.cpp

	good luck! <3
*/