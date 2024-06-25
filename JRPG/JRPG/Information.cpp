#include "Console.h"
#include "Information.h"

void RenderEnemyInfo(Enemy enemy)
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 6;
	int y = Resolution.Y / 5;
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	Gotoxy(x - 6, y - 8);
	wcout << L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████" 
		  << '\n';
	Gotoxy(x - 6, y - 7);
	wcout << L"██                                                                                                                                      ██" 
		  << '\n';
	Gotoxy(x + 20, y - 6);
	wcout << L"적의 체력 : " << enemy.currentHp << L"적의 방어력 : " << enemy.stat.armor << L"적의 회피력 : " << enemy.stat.agility;
	Gotoxy(x + 20, y - 5);
	wcout << L"적의 공격력 : " << enemy.stat.strength << L"적의 크리티컬 확률 : " << enemy.stat.ciritalChance << L"적의 치명타 데미지 : " << enemy.stat.ciritalDamage;
	Gotoxy(x - 6, y - 4);
	wcout << L"██                                                                                                                                      ██"
		<< '\n';
	Gotoxy(x - 6, y - 3);
	wcout << L"██                                                                                                                                      ██" 
		  << '\n';
	Gotoxy(x - 6, y - 2);
	wcout << L"██████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████████"
		  << '\n';
	int curmode = _setmode(_fileno(stdout), prevmode);
}

void RenderPlayerInformation(Player player)
{
	COORD Resolution = GetConsoleResolution();
	int x = Resolution.X / 2;
	int y = Resolution.Y / 2;
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	Gotoxy(x + 12, y + 12);
	wcout << L"█████████████████████████████████████████████████████████████████████"
		<< '\n';
	Gotoxy(x + 12, y + 13);
	wcout << L"██                                                                 ██"
		<< '\n';
	Gotoxy(x + 12, y + 14);
	wcout << L"██" << L"                           " << L"플레이어 정보" << L"                         ██";
	Gotoxy(x + 12, y + 15);
	wcout << L"██      민첩 : " << player._stat.agility <<
		L"       치명타율 : " << player._stat.ciritalChance <<
		L"     치명타 데미지 : " << player._stat.ciritalDamage <<
		L"       ██"
		<< '\n';
	Gotoxy(x + 12, y + 16);
	wcout << L"██      체력 : " << player._stat.maxHealth <<
		L"       공격력 : " << player._stat.strength <<
		L"       방어력 : " << player._stat.armor <<
		L"              ██"
		<< '\n';
	Gotoxy(x + 12, y + 17);
	wcout << L"██                                                                 ██"
		<< '\n';
	Gotoxy(x + 12, y + 18);
	wcout << L"█████████████████████████████████████████████████████████████████████"
		<< '\n';

	int curmode = _setmode(_fileno(stdout), prevmode);
}