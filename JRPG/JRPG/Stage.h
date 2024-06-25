#pragma once
#include "Player.h"
#include "Enemy.h"
enum class StageType {
	One = 1, Two, Three
};

class Stage {
public:
	StageType _currentStage;
	Enemy _isHasEnemy = 
		Enemy(EnemyType::GOBLIN, 0, 0, 0, 0, 0, 0, true);

	Stage(StageType stage, Enemy enemy)
	{
		_currentStage = stage;
		_isHasEnemy = enemy;
	}


	int operator <<(const StageType& _other) const
	{
		return (int)_other;
	}

private:
};

void RenderBattleUI(Stage stage, Enemy enemy);
void RenderUI(PlayerState state, Enemy enemy);
void RenderUIText(PlayerState state, int x, int y, Enemy enemy);

