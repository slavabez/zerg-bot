#include "ZergBot.h"


void ZergBot::OnStep()
{
	// TODO: Put commands here that execute on each step
}

void ZergBot::OnGameEnd()
{
	std::cout << "Game ended, saving replay..." << std::endl;
	const char *replay_filename = "tutorial_" __DATE__  "-" __TIME__ ".SC2Replay";
	Control()->SaveReplay(replay_filename);
	std::cout << "Saved the replay to " << replay_filename;
}

void ZergBot::OnUnitIdle(const Unit &unit)
{
	switch (unit.unit_type.ToType()) {
	case UNIT_TYPEID::ZERG_HATCHERY: {
		if (Observation()->GetMinerals() > 50) {
			Actions()->UnitCommand(unit, ABILITY_ID::TRAIN_DRONE);
		}
		break;
	}
	default:
		break;
	}
}

