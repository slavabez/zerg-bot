#include "ZergBot.h"
#include "MacroManager.h"
#include <sc2utils/sc2_manage_process.h>
#include <ctime>


ZergBot::ZergBot():
mac_man(*this),
build_man(*this)
{}


void ZergBot::OnStep()
{
	// TODO: Put commands here that execute on each step
	// std::cout << "Game step: " << Observation()->GetGameLoop() << std::endl;
	//MacroManager::OnStep(*this);
	//sc2::SleepFor(15);

	mac_man.OnStep();
}

void ZergBot::OnGameStart()
{
	
}


void ZergBot::OnGameEnd()
{
	std::cout << "Game ended, saving replay..." << std::endl;

	const char *replay_filename = "C:/Blizzard/StarCraft II/Replays/zerg_bot.SC2Replay";
	Control()->SaveReplay(replay_filename);
	Control()->SaveReplay("zerg_bot_local.SC2Replay");
	std::cout << "Saved the replay to " << replay_filename;


}

void ZergBot::OnUnitIdle(const Unit &unit)
{
	
}

