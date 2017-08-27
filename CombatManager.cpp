#include <iostream>
#include "CombatManager.h"
#include "ZergBot.h"

void CombatManager::OnStart()
{
	// Determine and save the point of enemy spawn
	EnemySpawnPoint = bot.Observation()->GetGameInfo().enemy_start_locations.front();
	std::cout << "Enemy Spawn is at X: " << EnemySpawnPoint.x << ", Y: " << EnemySpawnPoint.y << std::endl;
}

bool CombatManager::OnStep()
{
	// TODO: scouitng and battle logic here
}
