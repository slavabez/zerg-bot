#pragma once
#include <iostream>
#include <sc2api/sc2_api.h>

using namespace sc2;

class ZergBot :
	public Agent
{
public:

	virtual void OnStep() final;
	virtual void OnGameEnd() final;
	virtual void OnUnitIdle(const Unit &unit) final;


};

