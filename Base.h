#pragma once
#include <sc2api/sc2_common.h>
#include <sc2api/sc2_unit.h>
#include "ZergBot.h";

using namespace sc2;

class Base
{
	ZergBot bot;

	Point2D HatcheryPosition;
	Units mineralPatches;
	Units geysers;
	bool isRichMinerals;
	bool hasGeysers;

	Unit geyserOne;
	Unit geyserTwo;

	size_t dronesOnMinerals;
	size_t dronesOnGeyserOne;
	size_t dronesOnGeyserTwo;

public:

	/**
	 * Constructor for the initial base
	 */
	Base(ZergBot bot, bool findNew);

	Point2D GetHatcheryPosition();

	bool GetIsRichMineral();
	bool GetHasGeysers();

	void OnStep();

	
};

