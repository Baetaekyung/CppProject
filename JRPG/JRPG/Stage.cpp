#include<fcntl.h>
#include<io.h>
#include "Console.h"
#include "Stage.h"
#include "TitleScene.h"

void RenderBattleUI(Stage stage, Enemy enemy)
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 6;
	int y = Resolution.Y / 1.54;
	int originy = y;
	int posY = 0;
	bool fristRender = true;
	PlayerState currentState = PlayerState::None;

	system("cls");
	while (true)
	{
		if (fristRender) {
			RenderUI(currentState, enemy );
			fristRender = false;
		}

		while (true)
		{
			switch (posY)
			{
			case 0:
				currentState = PlayerState::Attack;
				break;
			case 1:
				currentState = PlayerState::Skill;
				break;
			case 2:
				currentState = PlayerState::Item;
				break;
			case 3:
				currentState = PlayerState::Defence;
				break;
			}

			Gotoxy(x - 2, y);
			cout << ">";

			KEY eKey = KeyController();
			switch (eKey)
			{
			case KEY::UP:
				if (originy < y)
				{
					Gotoxy(x - 2, y);
					cout << " ";
					Gotoxy(x - 2, y-=3);
					posY--;
					cout << ">";
					Sleep(100);
				}
				break;
			case KEY::DOWN:
				if (originy + 9 > y)
				{
					Gotoxy(x - 2, y);
					cout << " ";
					Gotoxy(x - 2, y+=3);
					posY++;
					cout << ">";
					Sleep(100);
				}
				break;
			case KEY::Enter:
			{
				if (posY);
				system("cls");
				RenderUI(currentState, enemy);
			}
			break;
			}
		}
	}
}

void RenderUI(PlayerState state, Enemy enemy) {
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	COORD Resolution = GetConsoleResolution();
	SetColor((int)COLOR::WHITE, (int)COLOR::BLACK);
	int x = Resolution.X / 9;
	int y = Resolution.Y / 1.8;
	RenderUIText(state, x, y, enemy);
	_setmode(_fileno(stdout), prevmode);
}

void RenderUIText(PlayerState state, int x, int y, Enemy enemy)
{
	Gotoxy(x, y);
	switch (state)
	{
	case PlayerState::None:
		wcout << L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████";
		Gotoxy(x, y + 1);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 2);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 3);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 4);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 5);
		wcout << L"██        attack        ██                                                                                                      ██";
		Gotoxy(x, y + 6);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 7);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 8);
		wcout << L"██        skill         ██                                                                                                      ██";
		Gotoxy(x, y + 9);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 10);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 11);
		wcout << L"██        item          ██                                                                                                      ██";
		Gotoxy(x, y + 12);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 13);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 14);
		wcout << L"██        Defence       ██                                                                                                      ██";
		Gotoxy(x, y + 15);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 16);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 17);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 18);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 19);
		wcout << L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████";
		break;
	case PlayerState::Attack:
		wcout << L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████";
		Gotoxy(x, y + 1);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 2);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 3);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 4);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 5);
		wcout << L"██        attack        ██                                                                                                      ██";
		Gotoxy(x, y + 6);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 7);
		wcout << L"██                      ██                                                                                                      ██"; 
		Gotoxy(x, y + 8);
		wcout << L"██        skill         ██                                                                                                      ██";
		Gotoxy(x, y + 9);
		//wcout << L"██                      ██                                                                                                      ██";
		for (int i = 0; i < 105; ++i) {
			if (i == 0) {
				wcout << L"██                      ██ ";
			}
			else if (i == (105 / 2) - enemy.nameOfEnemy.length()) {
				wcout << enemy.nameOfEnemy.length();
				i += enemy.nameOfEnemy.size();
			}
			else if (i == 103) {
				wcout << L"██";
				break;
			}
			else {
				wcout << L" ";
			}
		}
		Gotoxy(x, y + 10);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 11);
		wcout << L"██        item          ██                                                                                                      ██";
		Gotoxy(x, y + 12);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 13);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 14);
		wcout << L"██        Defence       ██                                                                                                      ██";
		Gotoxy(x, y + 15);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 16);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 17);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 18);
		wcout << L"██                      ██                                                                                                      ██";
		Gotoxy(x, y + 19);
		wcout << L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████";
		break;
	case PlayerState::Skill:
		break;
	case PlayerState::Item:
		break;
	case PlayerState::Defence:
		break;
	}

}
