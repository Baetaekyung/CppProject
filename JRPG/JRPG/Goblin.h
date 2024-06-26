#pragma once
#include "Enemy.h"

class Goblin : public Enemy
{
public:
	Goblin(Stat goblinStat);
	wstring visual[7] =
	{
		 L"  |\\_/|",
		 L"=( o O )=",
		 L" /\\ \" / \\",
		 L"| |\_/| |",
		 L"\_>---<_/",
		 L"(___|___)",
	};
};

