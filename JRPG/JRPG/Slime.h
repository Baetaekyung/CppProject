#pragma once
#include "Enemy.h"

class Slime : public Enemy
{
public:
	Slime(Stat slimeStat);
public:
	void SetVisual();
};

