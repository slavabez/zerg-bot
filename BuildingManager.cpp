#include "BuildingManager.h"
#include "ZergBot.h"
#include "Utilities.h"

using namespace sc2;

void BuildingManager::OnStart()
{
	// Starting logic, determine natural expansion position etc

	Units hatcheries = bot.Observation()->GetUnits(Unit::Self, IsUnit(UNIT_TYPEID::ZERG_HATCHERY));
	for (auto hatchery : hatcheries)
	{
		spawn = hatchery.pos;
		std::cout << "hatchery spawn point x: " << spawn.x << ", y: " << spawn.y << std::endl;
	}
}

bool BuildingManager::OnStep()
{
	// Logic for each frame
	return false;
}

bool BuildingManager::OrderExtractor()
{

	if (bot.Observation()->GetMinerals() < 75)
	{
		return false;
	}
	// Find extractor near the spawn
	float distance = FLT_MAX;
	sc2::Unit nearestGeyser;
	
	sc2::Units geysers = bot.Observation()->GetUnits(Unit::Neutral);
	for (auto geyser : geysers)
	{
		if (Util::IsGeyser(geyser))
		{
			float newDistance = sc2::Distance2D(spawn, geyser.pos);
			if (newDistance < distance)
			{
				nearestGeyser = geyser;
				distance = newDistance;
			}
		}
	}
	if (nearestGeyser)
	{
		UnitTag geyserTag = nearestGeyser.tag;
		Unit builder = GetADrone();

		bot.Actions()->UnitCommand(builder, ABILITY_ID::BUILD_EXTRACTOR, geyserTag);
	}
	


	return false;
}

sc2::Unit BuildingManager::GetADrone()
{
	sc2::Units drones = Util::GetSelfUnitsOfType(bot, UNIT_TYPEID::ZERG_DRONE);

	// Try to see an idle one
	if (bot.Observation()->GetIdleWorkerCount() > 1)
	{
		for (auto drone : drones)
		{
			if (drone.orders.size() < 1)
			{
				return drone;
			}
		}
	}

	// If not, get a random mineral mining one
	for (auto drone : drones)
	{
		for (auto order: drone.orders)
		{
			if (order.ability_id == ABILITY_ID::HARVEST_GATHER || order.ability_id == ABILITY_ID::HARVEST_GATHER_DRONE)
			{
				return drone;
			}
		}
	}


	
}

sc2::Units BuildingManager::GetTownHalls()
{
	
	std::vector<UNIT_TYPEID> types;
	types.push_back(UNIT_TYPEID::ZERG_HATCHERY);
	types.push_back(UNIT_TYPEID::ZERG_LAIR);
	types.push_back(UNIT_TYPEID::ZERG_HIVE);

	return bot.Observation()->GetUnits(Unit::Self, IsUnits(types));
}

