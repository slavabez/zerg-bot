#pragma once

class ZergBot;

class BuildingManager
{

	ZergBot & bot;
public:
	BuildingManager(ZergBot & bot): bot(bot) {};

	void OnStart();
	bool OnStep();
};

