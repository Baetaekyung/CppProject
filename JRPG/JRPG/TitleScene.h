#pragma once
#include "Console.h"
void TitleRenderer();
bool TitleScene();
void InfoRender();
enum class Menu {
	Start = 0,
	Help,
	Exit,
};
Menu MenuRender();
enum class KEY
{
	UP, DOWN, Enter, FAIL, Left, Right, ESC
};
KEY KeyController();
int EnterAnimation();
int StageRender();
void StageRenderText(int a);
