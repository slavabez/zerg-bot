#pragma once
#include <sc2api/sc2_unit.h>

class ZergBot;

class BuildingManager
{

	ZergBot & bot;

	bool timeToExpand = false;
	sc2::Point2D spawn;
	



public:
	BuildingManager(ZergBot & bot): bot(bot) {};

	void OnStart();
	bool OnStep();

	bool OrderExtractor();
	sc2::Unit GetADrone();

	sc2::Units GetTownHalls();
};

