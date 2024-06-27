#include<fcntl.h>
#include<io.h>
#include "Console.h"
#include "Stage.h"
#include "TitleScene.h"
#include "GameManager.h"


Stage::Stage(StageType stage, Enemy enemy) {
	_currentStage = stage;
	_isHasEnemy = enemy;
}

KeyControl::KeyControl(int x, int y, int clamp, int downValueX, int downValueY) {
	_x = x;
	_y = y;
	_clamp = clamp;
	_downValueX = downValueX;
	_downValueY = downValueY;
}

PlayerState _currentState = PlayerState::None;
Enemy _enemy;
int posY = 0;
void RenderBattleUI(Enemy enemy)
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 6;
	int y = Resolution.Y / 1.54;
	int originy = y;
	bool fristRender = true;
	KeyControl keyControl = KeyControl(x, y, 9, 2, 3);
	_enemy = enemy;

	system("cls");
	while (true)
	{
		if (fristRender) {
			RenderDetailUI(_currentState);
			fristRender = false;
		}

		while (true)
		{
			switch (posY)
			{
			case 0:
				_currentState = PlayerState::Attack;
				break;
			case 1:
				_currentState = PlayerState::Skill;
				break;
			case 2:
				_currentState = PlayerState::Item;
				break;
			case 3:
				_currentState = PlayerState::Defence;
				break;
			}

			SelectPosDownController(keyControl, originy, SelectType::Select, &posY);
		}
	}
}

void RenderDetailUI(PlayerState state) {
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	COORD Resolution = GetConsoleResolution();
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	int x = Resolution.X / 9;
	int y = Resolution.Y / 1.8;
	RenderDetailUIText(state, x, y);
	_setmode(_fileno(stdout), prevmode);
}

void RenderDetailUIText(PlayerState state, int x, int y)
{
	KeyControl attackSet = KeyControl((x + 24 + (105 / 2) - _enemy.nameOfEnemy.length()) - 1, y + 9 , 0 , 0 , 0);
	Gotoxy(x, y);
	switch (state)
	{
	case PlayerState::None:
		RenderOutLineUI(x, y);
		break;
	case PlayerState::Attack:
		RenderOutLineUI(x, y);
		RenderInTextUI(x, y + 5, L"공격할 적을 선택하세요!");
		RenderInTextUI(x, y + 9, _enemy.nameOfEnemy);

		SelectPosDownController(attackSet, y, SelectType::Attack, 0);
		break;
	case PlayerState::Skill:
		RenderOutLineUI(x, y);
		break;
	case PlayerState::Item:
		RenderOutLineUI(x, y);
		break;
	case PlayerState::Defence:
		// 즉시실행
		break;
	}

}

void RenderOutLineUI(int x, int y) {
	wcout << L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████";

	for (int i = 1; i <= 18; ++i) {
		Gotoxy(x, y + i);
		wcout << L"██";
		Gotoxy(x + 22, y + i);
		wcout << L"██";
		Gotoxy(x + 128, y + i);
		wcout << L"██";

	}
	Gotoxy(x, y + 19);
	wcout << L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████";

	wstring arr[4] = { L"attack", L"skill", L"item", L"Defence" };

	for (int i = 0; i < 4; ++i) {
		Gotoxy(x + 9, y + (5 + i * 3));
		wcout << arr[i];
	}
}

void RenderInTextUI(int x, int y, wstring str) {
	Gotoxy(x + 24 + (105 / 2) - str.length(), y);
	wcout << str;
}

void SelectPosDownController(KeyControl keyControl, int originY, SelectType selectType, int* posY) {
	bool wasPressedEnter = false;
	Gotoxy(keyControl._x - keyControl._downValueX, keyControl._y);
	wcout << L">";

	while (true) {
		Sleep(100);

		KEY eKey = KeyController();
		switch (eKey)
		{
		case KEY::UP:
			if (originY < keyControl._y)
			{
				posY++;
				Gotoxy(keyControl._x - keyControl._downValueX, keyControl._y);
				wcout << L" ";
				Gotoxy(keyControl._x - keyControl._downValueX, keyControl._y -= keyControl._downValueY);
				wcout << L">";
				Sleep(100);
			}
			break;
		case KEY::DOWN:
			if (originY + keyControl._clamp > keyControl._y)
			{
				posY--;
				Gotoxy(keyControl._x - keyControl._downValueX, keyControl._y);
				wcout << L" ";
				Gotoxy(keyControl._x - keyControl._downValueX, keyControl._y += keyControl._downValueY);
				wcout << L">";
				Sleep(100);
			}
			break;
		case KEY::Enter:
		{
			wasPressedEnter = true;
		}
		break;
		}

		if (wasPressedEnter) {
			system("cls");
			break;
		}
	}

	COORD Resolution = GetConsoleResolution();

	if (selectType == SelectType::Select) {
		RenderDetailUI(_currentState);
	}
	else if (selectType == SelectType::Attack) {
		int x = Resolution.X / 9;
		int y = Resolution.Y / 1.8;

		wstring str = L"공격으로 피해를 입혔습니다!";
		KeyControl resultControl = KeyControl(x + 24 + (105 / 2) - str.length() - 0.5f, y + 9, 0, 0, 0);
		GameManager::_player.Attack();
		RenderOutLineUI(x, y);
		RenderActionResultUI(str);
		SelectPosDownController(resultControl, y, SelectType::Result, 0);
	}
	else if (selectType == SelectType::Skill) {
		GameManager::_player.UseSkill();
		/*RenderActionResultUI();*/
	}
	else if (selectType == SelectType::Item) {
		GameManager::_player.UseItem();
	}
	else if (selectType == SelectType::Result) {
		int x = Resolution.X / 6;
		int y = Resolution.Y / 1.54;

		system("cls");
		KeyControl selectControl = KeyControl(x, y, 9, 2, 3);
		RenderOutLineUI(x, y);
		SelectPosDownController(selectControl, y, SelectType::Select, posY);
	}
}

void SelectPosRALController(KeyControl keyControl, int originY) {

}

void RenderActionResultUI(wstring str)
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 9;
	int y = Resolution.Y / 1.8;
	Gotoxy(x + 24 + (105 / 2) - str.length(), y + 9);
	wcout << str;
}
