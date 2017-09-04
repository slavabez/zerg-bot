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

		// Find nearby mineral patches
		Units patches;
		std::vector<UNIT_TYPEID> mineralTypes;
		mineralTypes.push_back(UNIT_TYPEID::NEUTRAL_MINERALFIELD);
		mineralTypes.push_back(UNIT_TYPEID::NEUTRAL_MINERALFIELD750);
		Units allPatches = Util::GetNeutralUnitsOfType(bot, mineralTypes);

		for (Unit patch : allPatches)
		{
			if (Distance2D(patch.pos, HatcheryPosition) < 15.0)
			{
				patches.push_back(patch);
			}
		}

		mineralPatches = patches;
	}
}

Point2D Base::GetHatcheryPosition()
{
}

bool Base::GetIsRichMineral()
{
}

bool Base::GetHasGeysers()
{
}

void Base::OnStep()
{
}

