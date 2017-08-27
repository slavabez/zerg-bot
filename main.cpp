#include <sc2api/sc2_api.h>
#include <iostream>

#include "ZergBot.h"

using namespace sc2;


int main(int argc, char* argv[]) {
    Coordinator coordinator;
    coordinator.LoadSettings(argc, argv);

    ZergBot bot;
	coordinator.SetParticipants({
		CreateParticipant(Race::Zerg, &bot),
		CreateComputer(Race::Random, CheatInsane)
    });

    coordinator.LaunchStarcraft();
    coordinator.StartGame("Melee/Simple64.SC2Map");

    while (coordinator.Update()) {
    }

    return 0;
}