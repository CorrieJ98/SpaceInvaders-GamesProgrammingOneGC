#pragma once
#include <array>
#include "custom_macros.h"

const int kOffsetStart = FG_START_LANES;
const int kOffsetRoad = kOffsetStart + FG_ROAD_LANES;
const int kOffsetMidPave = kOffsetRoad + FG_MIDPAVE_LANES;
const int kOffsetRiver = kOffsetMidPave + FG_RIVER_LANES;
const int kOffsetGrass = kOffsetRiver + FG_GRASS_LANES;

class Locale {
public:
	Locale() {};

	void PopulateLanesArray();

private:
	inline enum LaneTypes {
		STARTPAVE,
		ROAD,
		MIDPAVE,
		RIVER,
		GRASS
	};

	std::array<LaneTypes, (FG_GRASS_LANES + FG_RIVER_LANES + FG_MIDPAVE_LANES + FG_ROAD_LANES + FG_START_LANES)> m_lanes;
};

/*
	I reckon this is the entirely wrong way to go about this. Check Locale.cpp
	for where I think I should be going, as well as line 144 in GameSource.cpp

	good luck! <3
*/