#include<fcntl.h>
#include<io.h>
#include "Player.h"
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

PlayerState _currentState = PlayerState:: None;
Enemy _enemy;
void RenderBattleUI(Enemy enemy)
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 6;
	int y = Resolution.Y / 1.54;
	bool fristRender = true;
	int originy = y;
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
			SelectPosDownController(keyControl, originy, SelectType::Select);
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
	KeyControl skillSet = KeyControl((x + 24 + (105 / 2) - _enemy.nameOfEnemy.length()) - 1, y + 9 , 4, 2 , 4);
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

		SelectPosDownController(attackSet, y, SelectType::Attack);
		break;
	case PlayerState::Skill:
		RenderOutLineUI(x, y);
		RenderInTextUI(x, y + 5, L"사용할 스킬을 선택하세요!");
		for (int i = 1; i < GameManager::_player.skills.size() + 1; ++i) {
			RenderInTextUI(x, y + (i * 4) + 5, GameManager::_player.skills[i - 1].name);
		}

		SelectPosDownController(skillSet, y + 9, SelectType::Skill);
		RenderOutLineUI(x, y);
		break;
	case PlayerState::Item:
		RenderOutLineUI(x, y);
		RenderInTextUI(x, y + 5, L"사용할 스킬을 선택하세요!");
		for (int i = 1; i < GameManager::_player.itmes.size() + 1; ++i) {
			RenderInTextUI(x, y + (i * 4) + 5, GameManager::_player.itmes[i - 1]._name);
		}

		SelectPosDownController(attackSet, y + 9, SelectType::Item);
		RenderOutLineUI(x, y);
		break;
	case PlayerState::Defence:
		system("cls");

		GameManager::_player._isDefence = true;
		wstring str = L"이번 공격을 방어합니다.";
		KeyControl resultControl = KeyControl(x + 24 + (105 / 2) - str.length() - 0.5f, y + 9, 0, 0, 0);
		RenderOutLineUI(x, y);
		RenderActionResultUI(str);
		SelectPosDownController(resultControl, y, SelectType::Result);
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

void SelectPosDownController(KeyControl keyControl, int originY, SelectType selectType) {
	bool wasPressedEnter = false;
	int posY = 0;
	Gotoxy(keyControl._x - keyControl._downValueX, keyControl._y);
	wcout << L">";

	while (true) {
		if (selectType == SelectType::Select) {
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
		}

		Sleep(100);

		KEY eKey = KeyController();
		switch (eKey)
		{
		case KEY::UP:
			if (originY < keyControl._y)
			{
				posY -= 1;
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
				posY += 1;
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
			break;
		}
	}

	COORD Resolution = GetConsoleResolution();

	if (selectType == SelectType::Select) {
		RenderDetailUI(_currentState);
	}
	else if (selectType == SelectType::Attack) {
		system("cls");
		int x = Resolution.X / 9;
		int y = Resolution.Y / 1.8;

		wstring str = L"공격으로 피해를 입혔습니다!";
		KeyControl resultControl = KeyControl(x + 24 + (105 / 2) - str.length() - 0.5f, y + 9, 0, 0, 0);
		GameManager::_player.Attack();
		RenderOutLineUI(x, y);
		RenderActionResultUI(str);
		SelectPosDownController(resultControl, y, SelectType::Result);
	}
	else if (selectType == SelectType::Skill) {
		system("cls");
		int x = Resolution.X / 9;
		int y = Resolution.Y / 1.8;

		wstring str = L"공격으로 피해를 입혔습니다!";
		KeyControl resultControl = KeyControl(x + 24 + (105 / 2) - str.length() - 0.5f, y + 9, 0, 0, 0);
		GameManager::_player.Attack();
		RenderOutLineUI(x, y);
		RenderActionResultUI(str);
		SelectPosDownController(resultControl, y, SelectType::Result);
	}
	else if (selectType == SelectType::Item) {
		system("cls");
		int x = Resolution.X / 9;
		int y = Resolution.Y / 1.8;

		GameManager::_player.UseItem();
		wstring str = L"회복하였습니다.";
		KeyControl resultControl = KeyControl(x + 24 + (105 / 2) - str.length() - 0.5f, y + 9, 0, 0, 0);
		GameManager::_player.Attack();
		RenderOutLineUI(x, y);
		RenderActionResultUI(str);
		SelectPosDownController(resultControl, y, SelectType::Result);
	}
	else if (selectType == SelectType::Result) {
		_currentState = PlayerState::None;
		RenderBattleUI(_enemy);
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
