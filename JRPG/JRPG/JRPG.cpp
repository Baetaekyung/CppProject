#include "Player.h"
#include "TitleScene.h"
#include "Console.h"


int main()
{
	FullScreen();
	SetCursorVisual(false, 1);
	if (!TitleScene())
		return 0;

	//Player player = Player(Stat{ 1, 1, 1, 1, 1, 1});
	//while (true)
	//{
	//	player.Update();

	//	player.Render();

	//}
}