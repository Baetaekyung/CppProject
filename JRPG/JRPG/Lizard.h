#pragma once
#include "Enemy.h"

class Lizard : public Enemy
{
public:
	Lizard(Stat lizardStat);
	wstring visual[7]
	{
		L"                       )/_",
		L"             _.--..---\" - ,--c_",
		L"        \\L..'           ._O__)_",
		L",-.     _.+  _  \\..--( /         ",
		L"  `\\.-''__.-' \\ (     \\_      ",
		L"    `'''       `\\__   /\\",
		L"                ')"
	};
};

