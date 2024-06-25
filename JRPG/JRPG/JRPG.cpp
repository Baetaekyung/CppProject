#include<fcntl.h>
#include<io.h>
#include "Player.h"
#include "TitleScene.h"
#include "Console.h"
#include "Stage.h"

int main()
{
	Stage stage = Stage(StageType::One);
	FullScreen();
	SetCursorVisual(false, 1);
	if (!TitleScene())
		return 0;
	stage._currentStage = (StageType)EnterAnimation();
	while (true)
	{
		//system("cls");
		RenderBattleUI(stage);
	}

	//Player player = Player(Stat{ 1, 1, 1, 1, 1, 1});
	//while (true)
	//{
	//	player.Update();

	//	player.Render();

	//}
	return 0;
}