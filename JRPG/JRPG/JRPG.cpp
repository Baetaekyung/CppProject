#include<fcntl.h>
#include<io.h>
#include "Player.h"
#include "TitleScene.h"
#include "Console.h"
#include "Stage.h"
#include "GameManager.h"

int main()
{
	Enemy enemy = Enemy(EnemyType::GOBLIN, 0, 0, 0, 0, 0, 0, true);
	Stage stage = Stage(StageType::One, enemy);
	Player player = Player(Stat{ 10, 1000, 10, 50, 200, 100 });
	GameManager::player = player;

	FullScreen();
	SetCursorVisual(false, 1);
	if (!TitleScene())
		return 0;
	stage._currentStage = (StageType)EnterAnimation();
	while (true)
	{
		//system("cls");
		RenderBattleUI(stage, stage._isHasEnemy);
	}

	//Player player = Player(Stat{ 1, 1, 1, 1, 1, 1});
	//while (true)
	//{
	//	player.Update();

	//	player.Render();

	//}
	return 0;
}