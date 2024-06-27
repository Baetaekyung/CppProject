#pragma once
#include "Enemy.h"

class Goblin : public Enemy
{
public:
	Goblin(Stat goblinStat);
public:
	void SetVisual();
};

