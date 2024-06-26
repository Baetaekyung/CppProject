#pragma once
#include "Enemy.h"

class Slime : public Enemy
{
public:
	Slime(Stat slimeStat);
	wstring visual[9]
	{
		L"         __  "
		L"       _|  |_",
		L"     _|      |_",
		L"    |  _    _  |",
		L"    | |_|  |_| |",
		L" _  |  _    _  |  _",
		L"|_|_|_| |__| |_|_|_|",
		L"  |_|_        _|_|",
		L"    |_|______|_|"
	};
};

