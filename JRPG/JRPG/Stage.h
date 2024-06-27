#pragma once
#include "Player.h"
#include "Enemy.h"
enum class StageType {
	One = 1, Two, Three
};

enum class SelectType {
	Select, Attack, Skill, Item, Result
};

class Stage {
public:
	StageType _currentStage;
	Enemy _isHasEnemy = 
		Enemy(EnemyType::GOBLIN, Stat{0,0,0,0,0,0}, true);

	Stage(StageType stage, Enemy enemy);


	int operator <<(const StageType& _other) const
	{
		return (int)_other;
	}

private:
};

class KeyControl {
public:
	int _x = 0;
	int _y = 0;
	int _clamp = 0;
	int _downValueX = 0;
	int _downValueY = 0;

	KeyControl(int x, int y, int clamp, int downValueX,
		int downValueY);
};

void RenderBattleUI(Enemy enemy);
void RenderDetailUI(PlayerState state);
void RenderDetailUIText(PlayerState state, int x, int y);
void RenderOutLineUI(int x, int y);
void RenderInTextUI(int x, int y, wstring str);
void SelectPosDownController(KeyControl keyControl, int originY, 
	SelectType selectType, int* posY = nullptr);
void SelectPosRALController(KeyControl keyControl, int originY);
void RenderActionResultUI(wstring str);
