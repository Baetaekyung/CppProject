#pragma once
#include "Player.h"

class GameManager
{
public:
	static GameManager _gameManager;
	static Player _player;
private:
	GameManager();
};

