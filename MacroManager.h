#pragma once

#include <sc2api/sc2_api.h>

class ZergBot;

class MacroManager
{

	ZergBot & bot_;

public:

	MacroManager(ZergBot & bot) : bot_(bot) {};

	bool ManageDroneProduction();
	bool ManageOverlordProduction();
	bool ManageGeyserProduction();

	bool OrderDrones(int quantity);
	bool OrderOverlords(int quantity);

	void OnStep();

	sc2::Units GetLarvae();
};

