#pragma once
#include "Enemy.h"

class Lizard : public Enemy
{
public:
	Lizard(Stat lizardStat);
public:
	void SetVisual();
};

