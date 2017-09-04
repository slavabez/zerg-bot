#include "Base.h"
#include <sc2api/sc2_common.h>
#include <sc2api/sc2_agent.h>
#include "ZergBot.h"
#include "Utilities.h"

using namespace sc2;



Base::Base(ZergBot bot, bool findNew)
{
	if (findNew)
	{
		// Find a new base, set all the properties
	}
	else
	{
		// Use the first hatchery as the starting point
		const ObservationInterface* obs = bot.Observation();

		Point2D spawn = bot.GetBuildingManager().GetSpawn();
		HatcheryPosition = spawn;
	}

	// Find nearby mineral patches, set to the instance
	Units patches;
	std::vector<UNIT_TYPEID> mineralTypes;
	mineralTypes.push_back(UNIT_TYPEID::NEUTRAL_MINERALFIELD);
	mineralTypes.push_back(UNIT_TYPEID::NEUTRAL_MINERALFIELD750);
	mineralTypes.push_back(UNIT_TYPEID::NEUTRAL_LABMINERALFIELD);
	mineralTypes.push_back(UNIT_TYPEID::NEUTRAL_LABMINERALFIELD750);
	mineralTypes.push_back(UNIT_TYPEID::NEUTRAL_RICHMINERALFIELD);
	mineralTypes.push_back(UNIT_TYPEID::NEUTRAL_RICHMINERALFIELD750);

	Units allPatches = Util::GetNeutralUnitsOfType(bot, mineralTypes);

	for (Unit patch : allPatches)
	{
		if (Distance2D(patch.pos, HatcheryPosition) < 15.0)
		{
			patches.push_back(patch);
		}
	}

	mineralPatches = patches;

	if (mineralPatches[0].unit_type == UNIT_TYPEID::NEUTRAL_RICHMINERALFIELD || mineralPatches[0].unit_type == UNIT_TYPEID::NEUTRAL_RICHMINERALFIELD750)
	{
		isRichMinerals = true;
	} else
	{
		isRichMinerals = false;
	}

	// Repeat for geysers
	Units geysers;
	std::vector<UNIT_TYPEID> geyserTypes;
	geyserTypes.push_back(UNIT_TYPEID::NEUTRAL_VESPENEGEYSER);
	geyserTypes.push_back(UNIT_TYPEID::NEUTRAL_PROTOSSVESPENEGEYSER);
	geyserTypes.push_back(UNIT_TYPEID::NEUTRAL_SPACEPLATFORMGEYSER);

	Units allGeysers = Util::GetNeutralUnitsOfType(bot, geyserTypes);

	for (Unit geyser : allGeysers)
	{
		if (Distance2D(geyser.pos, HatcheryPosition) < 15.0)
		{
			geysers.push_back(geyser);
		}
	}

	if (geysers.size() < 1)
	{
		hasGeysers = false;
	} else if (geysers.size() == 1)
	{
		geyserOne = geysers[0];
	} else if (geysers.size() > 1)
	{
		geyserOne = geysers[0];
		geyserTwo = geysers[1];
	}

}

Point2D Base::GetHatcheryPosition()
{
	return HatcheryPosition;
}

bool Base::GetIsRichMineral()
{
	return isRichMinerals;
}

bool Base::GetHasGeysers()
{
	return hasGeysers;
}

void Base::OnStep()
{
}

