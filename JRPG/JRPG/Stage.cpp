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
void RenderBattleUI(Stage stage, Enemy enemy)
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 6;
	int y = Resolution.Y / 1.54;
	int originy = y;
	int posY = 0;
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

			SelectPosDownController(keyControl, originy, &posY);
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
	KeyControl attackSet = KeyControl(x, 0 , 0 , y , 0);
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

		while (true) {
			SelectPosDownController(attackSet, y, SelectType::Attack);
		}
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

void SelectPosDownController(KeyControl keyControl, int originY, SelectType selectType, int* posY = nullptr) {
	while (true) {
		Gotoxy(keyControl._x - keyControl._downValueX, keyControl._y);
		cout << ">";

		KEY eKey = KeyController();
		switch (eKey)
		{
		case KEY::UP:
			if (originY < keyControl._y)
			{
				posY++;
				Gotoxy(keyControl._x - keyControl._downValueX, keyControl._y);
				cout << " ";
				Gotoxy(keyControl._x - keyControl._downValueX, keyControl._y -= keyControl._downValueY);
				cout << ">";
				Sleep(100);
			}
			break;
		case KEY::DOWN:
			if (originY + keyControl._clamp > keyControl._y)
			{
				posY--;
				Gotoxy(keyControl._x - keyControl._downValueX, keyControl._y);
				cout << " ";
				Gotoxy(keyControl._x - keyControl._downValueX, keyControl._y += keyControl._downValueY);
				cout << ">";
				Sleep(100);
			}
			break;
		case KEY::Enter:
		{
			system("cls");
			switch (selectType)
			{
			case SelectType::Select:
				RenderDetailUI(_currentState);
				break;
			case SelectType::Attack:
				GameManager::player.Attack();
				RenderActionResultUI();
				break;
			case SelectType::Skill:
				GameManager::player.UseSkill();
				RenderActionResultUI();
				break;
			case SelectType::Item:
				GameManager::player.UseItem();
				RenderActionResultUI();
				break;
			default:
				break;
			}
		}
		break;
		}
	}
}

void SelectPosRALController(KeyControl keyControl, int originY) {

}

void RenderActionResultUI(wstring str)
{

}
