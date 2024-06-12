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
	UP, DOWN, Enter, FAIL, Left, Right
};
KEY KeyController();
void EnterAnimation();
void StageRender();
void StageRenderText(int a);
