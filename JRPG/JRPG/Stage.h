#pragma once
#include "Player.h"
#include "Enemy.h"
enum class StageType {
	One = 1, Two, Three
};

class Stage {
public:
	StageType _currentStage;

	Stage(StageType stage) {
		_currentStage = stage;
	}


	int operator <<(const StageType& _other) const
	{
		return (int)_other;
	}

private:
};

void RenderBattleUI(Stage stage);
void RenderUI(PlayerState state);
void RenderUIText(PlayerState state, int x, int y, Enemy enemy);

