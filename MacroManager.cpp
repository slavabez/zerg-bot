#include "MacroManager.h"
#include "Utilities.h"

using namespace sc2;





bool MacroManager::ManageDroneProduction()
{
	if (bot_.Observation()->GetMinerals() < 50)
	{
		return false;
	}

	// Start off by simply making drones until there's 24
	size_t numOfDrones = Util::CountSelfUnitsOfType(bot_, UNIT_TYPEID::ZERG_DRONE);

	if (numOfDrones < 1)
	{
		return false;
	}

	size_t numOfHatcheries = Util::CountTownHallTypeBuildings(bot_);

	// If every hatchery has less than 24 drones (and 2 more for building etc), make more
	if ((numOfHatcheries * 24 + 2) >= numOfDrones)
	{
		OrderDrones(1);
		// std::cout << "Ordered a drone, hatcheries: " << numOfHatcheries << ", drones atm: " << numOfDrones << std::endl;
	} 
	else
	{
		// std::cout << "Didn't order a drone, hatcheries: " << numOfHatcheries << ", drones atm: " << numOfDrones << std::endl;
	}

	return true;
}

bool MacroManager::ManageOverlordProduction()
{
	const ObservationInterface *obs = bot_.Observation();

	// Initial stages, early game, wait till 14 drones
	if (obs->GetMinerals() > 100 && obs->GetFoodUsed() == 14 && obs->GetFoodCap() == 14)
	{
		OrderOverlords(1);
		return true;
	}

	size_t currentOv = Util::CountOverlordsAndOverseers(bot_);

	// Lae mid game, build an overlord when 4 away, build two if more than 500 minerals
	if (currentOv > 5)
	{
		if (obs->GetFoodCap() - obs->GetFoodUsed() <= 5)
		{
			OrderOverlords(1);
			return true;
		}
	}

	// Mid game, build an overlord when close to limit (3 away)
	if (obs->GetMinerals() > 100 && currentOv >= 2)
	{
		if (obs->GetFoodCap() - obs->GetFoodUsed() <= 3)
		{
			OrderOverlords(1);
			return true;
		}
	}

	return false;

}

bool MacroManager::ManageGeyserProduction()
{
	// TODO
	return false;
}

bool MacroManager::OrderDrones(int quantity)
{
	// Order the drones, select larva and build

	Units larvae = GetLarvae();
	if (larvae.size() < 1 || bot_.Observation()->GetMinerals() < 50 || bot_.Observation()->GetFoodCap() == bot_.Observation()->GetFoodUsed())
	{
		return false;
	}

	for (auto larva : larvae)
	{
		bot_.Actions()->UnitCommand(larva, ABILITY_ID::TRAIN_DRONE);
		std::cout << "Ordered a drone(s)" << std::endl;
		return true;
	}

	return false;
}

Units MacroManager::GetLarvae() 
{
	return bot_.Observation()->GetUnits(Unit::Self, IsUnit(UNIT_TYPEID::ZERG_LARVA));
}



bool MacroManager::OrderOverlords(int quantity)
{
	// Before ordering, check how many are in simultanious production, use quantity as limit.
	// If it's already being built, ignore, unless it's less than what the limit is
	if (Util::CountNumberOfCurrentAbilitiesInProgress(bot_, ABILITY_ID::TRAIN_OVERLORD) >= quantity)
	{
		return false;
	}

	Units larvae = GetLarvae();

	// Skip if no larvae
	if (larvae.size() < 1)
	{
		return false;
	}

	// Skip if not enough minerals
	if (bot_.Observation()->GetMinerals() < 100)
	{
		return false;
	}

	for (auto larva : larvae)
	{
		bot_.Actions()->UnitCommand(larva, ABILITY_ID::TRAIN_OVERLORD);
		std::cout << "Ordered an Overlord" << std::endl;
		return true;
	}

	return false;
}

void MacroManager::OnStep()
{
	ManageDroneProduction();
	ManageOverlordProduction();

}
