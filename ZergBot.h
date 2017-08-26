#pragma once
#include <iostream>
#include <sc2api/sc2_api.h>

using namespace sc2;

class ZergBot :
	public Agent
{
public:

	void OnStep() override final;
	void OnGameEnd() override final;
	void OnUnitIdle(const Unit &unit) override final;


};

