#pragma once
#include "ZergBot.h"

class MacroManager
{
public:
	MacroManager();
	~MacroManager();

	static void ManageDroneProduction(ZergBot & bot);
	static void ManageOverlordProduction(ZergBot & bot);

	static bool OrderDrones(ZergBot & bot, int quantity);

	static void OnStep(ZergBot & bot);

};

