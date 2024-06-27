#pragma once

#include "Enemy.h"

class Spider : public Enemy
{
public:
	Spider(Stat enemyStat);
public:
	void SetVisual();
};

