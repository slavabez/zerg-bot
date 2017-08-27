#pragma once
#include <iostream>
#include <sc2api/sc2_api.h>

#include "MacroManager.h"
#include "BuildingManager.h"
#include "CombatManager.h"

using namespace sc2;


class ZergBot : public Agent
{

	MacroManager mac_man;
	BuildingManager build_man;
	CombatManager combat_man;

public:

	ZergBot();

	void OnStep() override final;
	void OnGameStart() override final;
	void OnGameEnd() override final;
	void OnUnitIdle(const Unit &unit) override final;




};

