#pragma once
#include <array>
#include "custom_macros.h"

static const int kOffsetStart = FG_START_LANES;
static const int kOffsetRoad = kOffsetStart + FG_ROAD_LANES;
static const int kOffsetMidPave = kOffsetRoad + FG_MIDPAVE_LANES;
static const int kOffsetRiver = kOffsetMidPave + FG_RIVER_LANES;
static const int kOffsetGrass = kOffsetRiver + FG_GRASS_LANES;

class Locale {
public:

	Locale() { PopulateLanesArray(); };
	void PopulateLanesArray();

	const enum LaneTypes {
		STARTPAVE,
		ROAD,
		MIDPAVE,
		RIVER,
		GRASS
	};

private:
	std::array<LaneTypes, (FG_GRASS_LANES + FG_RIVER_LANES + FG_MIDPAVE_LANES + FG_ROAD_LANES + FG_START_LANES)> m_lanes;
};