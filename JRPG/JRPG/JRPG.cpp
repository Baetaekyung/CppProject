#include<fcntl.h>
#include<io.h>
#include "Player.h"
#include "TitleScene.h"
#include "Console.h"
#include "Stage.h"
#include "GameManager.h"
#include "Enemy.h"
#include "Goblin.h"
#include "Information.h"

int main()
{
	srand((unsigned int)time(NULL));
	Goblin enemy = Goblin(Stat{10,10,10,10,10,10});
	Stage stage = Stage(StageType::One, enemy);
	Player player = Player(Stat{ 10, 1000, 10, 50, 200, 100 });
	GameManager::_player = player;

	FullScreen();
	SetCursorVisual(false, 1);
	if (!TitleScene())
		return 0;
	stage._currentStage = (StageType)EnterAnimation();
	while (true)
	{
		RenderEnemyInfo(enemy);
		enemy.Render();
		RenderBattleUI(stage._isHasEnemy);
	}

	//Player player = Player(Stat{ 1, 1, 1, 1, 1, 1});
	//while (true)
	//{
	//	player.Update();

	//	player.Render();

	//}
	return 0;
}