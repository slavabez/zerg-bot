#include "MacroManager.h"
#include "Utilities.h"

using namespace sc2;



MacroManager::MacroManager()
{
}


MacroManager::~MacroManager()
{
}

void MacroManager::ManageDroneProduction(ZergBot& bot)
{
	// Start off by simply making drones until there's 24
	size_t numOfDrones = Util::CountSelfUnitsOfType(bot, UNIT_TYPEID::ZERG_DRONE);
	size_t numOfHatcheries = Util::CountTownHallTypeBuildings(bot);

	// If every hatchery has less than 24 drones (and 2 more for building etc), make more
	if ((numOfHatcheries * 24 + 2) <= numOfDrones)
	{
		OrderDrones(bot, 1);
	}
}

void MacroManager::ManageOverlordProduction(ZergBot& bot)
{
}

bool MacroManager::OrderDrones(ZergBot& bot, int quantity)
{
	// Order the drones, select larva and build
	Units larvae = bot.Observation()->GetUnits(Unit::Self, IsUnit(UNIT_TYPEID::ZERG_LARVA));
	int counter = 0;
	for (auto larva : larvae)
	{
		bot.Actions()->UnitCommand(larva, ABILITY_ID::TRAIN_DRONE);
		counter++;
		break;
	}
	std::cout << "Ordered " << counter << " drone(s)" << std::endl;

	return true;
}

void MacroManager::OnStep(ZergBot& bot)
{
	ManageDroneProduction(bot);
}
